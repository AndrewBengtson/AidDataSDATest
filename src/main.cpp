#include <iostream>
#include "algorithms/MergeSortGeneric.cpp"
#include "entities/Comparator.cpp"
#include "entities/Coordinate.cpp"
#include "entities/XComparator.cpp"
#include "entities/YComparator.cpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <float.h>

void readFile(vector<Coordinate> &coordArray, fstream &fStream, bool isInA);
vector<Coordinate> findClosestCoordinatePair(vector<Coordinate> &coordArray,int left, int right);
using namespace std;

int main() {
    cout<<"Question 1:"<<endl;
    //first we will have to read data from the files and insert them into a single vector
    //we will use a custom coordinate class to hold x and y as fields and a reference to which file it came from
    vector<Coordinate> unsortedCoordArray;
    fstream a;
    a.open("../include/data/a.csv", ios::in);
    //check if the file is open
    if (!a.is_open()) {
        cout << "Could not find/open file a" << endl;
        return 1;
    }
    readFile(unsortedCoordArray, a, true);
    fstream b;
    b.open("../include/data/b.csv", ios::in);
    //check if the file is open
    if (!b.is_open()) {
        cout << "Could not find/open file b" << endl;
        return 1;
    }
    readFile(unsortedCoordArray, b, false);
    //next we will use MergeSort to sort the entire array by x values and than y (Taking advantage of O(n logn)
    Coordinate distance = Coordinate(1.0,1.0,true);
    Coordinate distance2 = Coordinate(2,2,true);
    cout<<"distance test: "<<distance.distance(&distance2)<<endl;
    Comparator<Coordinate> *xComparator =new XComparator;
    vector<Coordinate> sortedCoordArray =MergeSortGeneric<Coordinate>(unsortedCoordArray).sort(xComparator);
    //now that we have the array sorted by x values we can use a divide and conquer algorithm to find the closest coordinates
    vector<Coordinate> closestPair = findClosestCoordinatePair(sortedCoordArray,0,sortedCoordArray.size()-2);
    cout<<"the closest pair are " <<closestPair[0].getX()<<", "<<closestPair[0].getY()<<" from "<<closestPair[0].isInA()<<
    " and "<<closestPair[1].getX()<<", "<<closestPair[1].getY()<<" from "<<closestPair[1].isInA()<<endl;



    return 0;
}
//this recursive function reads the given file, and inserts coordinates into the provided array
void readFile(vector<Coordinate> &coordArray, fstream &fStream, bool isInA) {
    string line;
    //we use the bool first line to not ingest the column names
    bool firstLine = true;
    while(getline(fStream,line)){
        if(!firstLine) {
            //first we will walk until we find a comma, creating an x value
            string xString = "";
            int i = 0;
            for (i; line.at(i) != ','; i++) {
                xString.push_back(line.at(i));
            }
            //repeat this for y
            string yString = "";
            for (i++; line.at(i) != ','; i++) {
                yString.push_back(line.at(i));
            }
            //make a coordinate with the given line and push it to the back of the coordArray
            coordArray.emplace_back(stof(xString), stof(yString), isInA);
        }
        else{
            firstLine = false;
        }
    }
}

//This recursive function finds the pair of closest coordinates between the indexes left and right
//this function will return a vector which contains the two Coordinates
vector<Coordinate> findClosestCoordinatePair(vector<Coordinate> &coordArray,int left, int right){
    //if this is called for a negative value we return
    if(left<0 || right<0){
        cout<<"called on "<<left<<", "<<right<<endl;
        return {Coordinate(0,0,true),Coordinate(FLT_MAX,FLT_MAX,false)};
    }
    //the base case for recursion is when left and right are within ~15 indexes of each other, this small brute force
    // solution will only be used on small arrays
    if(right-left<15){
        //to get things ready we use a fake value which is absurdly large
        vector<Coordinate> closestPair {Coordinate(0,0,true),Coordinate(FLT_MAX,FLT_MAX,false)};
        //when we hit our base case we simply iterate across the vector between left and right
        for(int i=left;i<=right;i++){
            //for each coordinate, we iterate across the vector again
            for(int j=left;j<=right;j++){
                //for each coordinate pair, we evaluate their distance
                //if they are the closest two coordinates (and one is in a while the other isnt), we store them
                if(coordArray[i].distance(&coordArray[j])<closestPair[0].distance(&closestPair[1])&&(coordArray[i].isInA()^coordArray[j].isInA())){
                    closestPair[0] = coordArray[i];
                    closestPair[1] = coordArray[j];
                    //printf("we are now storing :%i, %i and %i, %i",closestPair[0].getX(),closestPair[0].getY(),closestPair[1].getY(),closestPair[1].getY());
                }
            }
        }
        //finally return the closest pair
        return closestPair;
    }
    //for the recursive case we will first split the array in half and call this on each half
    //we will store the pair of the closest two from each half
    int center = left+floor((right-left)/2);
    vector<Coordinate> leftPair = findClosestCoordinatePair(coordArray,left,center);
    vector<Coordinate> rightPair = findClosestCoordinatePair(coordArray,center+1,right);
    vector<Coordinate> recursivePair;
    //recursive pair will be the lesser of left and right
    recursivePair = leftPair[0].distance(&leftPair[1]) < rightPair[0].distance(&rightPair[1]) ? leftPair : rightPair;
    int closestDistance = recursivePair[0].distance(&recursivePair[1]);
    //now we have to consider the coordinates on the line between the two halves
    //these will be the coordinates which are between the center-closestDistance and center+closestDistance
    vector<Coordinate> edgePair = findClosestCoordinatePair(coordArray, center - closestDistance,
                                                                center + closestDistance);
    return recursivePair[0].distance(&recursivePair[1]) < edgePair[0].distance(&edgePair[1]) ? recursivePair : edgePair;
}
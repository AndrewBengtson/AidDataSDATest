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

void readFile(vector<Coordinate> &coordArray, fstream &fStream, bool isInA);

using namespace std;

int main() {
    cout<<"Question 1:"<<endl;
    //first we will have to read data from the files and insert them into a single vector
    vector<Coordinate> coordArray;
    fstream a;
    a.open("../include/data/a.csv", ios::in);
    //check if the file is open
    if (!a.is_open()) {
        cout << "Could not find/open file a" << endl;
        return 1;
    }
    readFile(coordArray, a, true);
    fstream b;
    b.open("../include/data/b.csv", ios::in);
    //check if the file is open
    if (!b.is_open()) {
        cout << "Could not find/open file b" << endl;
        return 1;
    }
    readFile(coordArray, b, false);
    //we will use a custom coordinate class to hold x and y as fields and a reference to which file it came from
    //next we will use MergeSort to sort the entire array by x values and than y (Taking advantage of O(n logn)
    //now that we have the array sorted by x values we can use a divide and conquer algorithm to find the closest coordinates

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
            coordArray.push_back(Coordinate(stof(xString), stof(yString), isInA));
        }
        else{
            firstLine = false;
        }
    }
}

//This recursive function finds the pair of closest coordinates between the indexes left and right
//this function will return a vector which contains the two Coordinates
vector<Coordinate> findClosestCoordinatePair(int left, int right){
    //the base case for recursion is when left and right are within ~4 indexes of each other
        //when we hit our base case we simply iterate across the vector between left and right
        //for each coordinate, we iterate across the vector again
            //for each coordinate pair, we evaluate their distance
            //if they are the closest two coordinates (and one is in a while the other isnt),
                //we store them and the distance
        //finally return the closest pair

    //for the recursive case we will first split the array in half and call this on each half
    //we will store the pair of the closest two from each half
    //now we have to consider the coordinates on the line between the two halves
    //these will be the coordinates which are between the center-closestDistance and center+closestDistance
    //form an array of these items and sort them by Y values
    //now we loop through the edge case array
        //for each element we will iterate through the small array until we find a pair further
        //than the distance we already have
    //if the distance in the edge case is less than the distance found recursively, return it
    //else return the recursive distance
}
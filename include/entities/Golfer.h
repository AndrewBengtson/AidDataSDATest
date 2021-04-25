//
// Created by agben on 4/25/2021.
//

#ifndef AIDDATASDATEST_GOLFER_H
#define AIDDATASDATEST_GOLFER_H

//This class will store the relevant information for each golfer in private fields we access with get methods
class Golfer {
public:
    //default constructor for the compiler
    Golfer(){}
    //this constructor initializes the relevant fields
    Golfer(string name,float avg_score,int lowest_round);
    //get method for the golfer's name
    string getName() const{
        return name;
    }
    //get method for the average score
    float getAvgScore() const{
        return avgScore;
    }
    //get method for the single round
    int getLowestScore() const{
        return lowestSingleRound;
    }
private:
    //this string stores the name of the golfer
    string name;
    //this floating point number is the average score for the golfer
    float avgScore;
    //this int is the lowest score the golfer got across all rounds
    int lowestSingleRound;
};


#endif //AIDDATASDATEST_GOLFER_H

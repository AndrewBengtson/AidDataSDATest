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
private:
    //this string stores the name of the golfer
    std::string name;
    //this floating point number is the average score for the golfer
    float avg_score;
    //this int is the lowest score the golfer got across all rounds
    int lowest_single_round;
};


#endif //AIDDATASDATEST_GOLFER_H

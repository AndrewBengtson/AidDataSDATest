//
// Created by agben on 4/25/2021.
//

#include "entities/Golfer.h"


Golfer::Golfer(string name, float avg_score, int lowest_round) {
    //this stores all parameters as fields
    this->name = name;
    this->avgScore = avg_score;
    this->lowestSingleRound = lowest_round;
}

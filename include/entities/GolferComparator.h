//
// Created by agben on 4/25/2021.
//

#ifndef AIDDATASDATEST_GOLFERCOMPARATOR_H
#define AIDDATASDATEST_GOLFERCOMPARATOR_H

#include "Golfer.h"

//this class is used to compare the golfers
class GolferComparator : public Comparator<Golfer>{
    //this returns true if g1 is less than g2, false otherwise
    //golfers are compared by average score and then round score is used as a tie breaker
    bool lessThan(Golfer &g1, Golfer &g2) override ;
};


#endif //AIDDATASDATEST_GOLFERCOMPARATOR_H

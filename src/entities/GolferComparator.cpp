//
// Created by agben on 4/25/2021.
//

#include "entities/GolferComparator.h"

bool GolferComparator::lessThan(Golfer &g1, Golfer &g2) {
    //first we evaluate average score
    if(g1.getAvgScore()<g2.getAvgScore()){
        return true;
    }
    //if there is a tie we differ to the round score
    else{
        return g1.getLowestScore()<g2.getLowestScore();
    }
}

bool GolferComparator::equals(Golfer &g1, Golfer &g2) {
    //consider the case they would be equal even with a tie breaker
    return g1.getAvgScore()==g2.getAvgScore()&&g1.getLowestScore()==g2.getLowestScore();
}

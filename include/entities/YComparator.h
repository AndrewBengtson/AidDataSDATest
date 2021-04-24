//
// Created by agben on 4/24/2021.
//

#ifndef AIDDATASDATEST_YCOMPARATOR_H
#define AIDDATASDATEST_YCOMPARATOR_H

#include "Comparator.h"
/*
 * This class is used to compare Coordinates using Y first and then X
 */
class YComparator : public Comparator<Coordinate>{
    //This returns true if c1 is less than c2, else returns false
    bool lessThan(Coordinate &c1, Coordinate &c2) override ;
    //This returns true if the two are equals
    bool equals(Coordinate &c1, Coordinate &c2) override ;
};


#endif //AIDDATASDATEST_YCOMPARATOR_H

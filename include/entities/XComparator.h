//
// Created by agben on 4/24/2021.
//

#ifndef AIDDATASDATEST_XCOMPARATOR_H
#define AIDDATASDATEST_XCOMPARATOR_H

/*
 * This class is used to Compare coordinates by x value, then y value
 */
class XComparator : public Comparator<Coordinate>{
    //This returns true if c1 is less than c2, else returns false
    bool lessThan(Coordinate &c1, Coordinate &c2) override ;
    //This returns true if the two are equals
    bool equals(Coordinate &c1, Coordinate &c2) override ;
};


#endif //AIDDATASDATEST_XCOMPARATOR_H

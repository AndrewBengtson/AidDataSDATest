//
// Created by agben on 4/24/2021.
//

#include "entities/XComparator.h"

bool XComparator::lessThan(Coordinate &c1, Coordinate &c2) {
    return c1.getX()<c2.getX();
}

bool XComparator::equals(Coordinate &c1, Coordinate &c2) {
    return c1.getY()==c1.getX() && c1.getY()==c2.getY() && c1.isInA() == c2.isInA();
}

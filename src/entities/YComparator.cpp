//
// Created by agben on 4/24/2021.
//

#include "entities/YComparator.h"

bool YComparator::lessThan(Coordinate &c1, Coordinate &c2) {
    return c1.getY()<c2.getY();
}

bool YComparator::equals(Coordinate &c1, Coordinate &c2) {
    return c1.getY()==c1.getX() && c1.getY()==c2.getY() && c1.isInA() == c2.isInA();
}

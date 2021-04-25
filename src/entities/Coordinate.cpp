//
// Created by agben on 4/23/2021.
//

#include "entities/Coordinate.h"
#include <math.h>

Coordinate::Coordinate(float x, float y, bool isInA) {
    //this constructor takes all of the relevant fields as parameters and store them as private fields
    this->x = x;
    this->y = y;
    this->InA = isInA;
}

int Coordinate::distance(Coordinate *coordinate) const {
    //we will use the standard formula for the distance between two points
    // the distance will be the square root of (x2 - x1)^2 + (y2-y1)^2
    return sqrt(pow((x - coordinate->getX()),2) + pow((y - coordinate->getY()),2));
}

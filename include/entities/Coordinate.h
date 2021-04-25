//
// Created by agben on 4/23/2021.
//

#ifndef AIDDATASDATEST_COORDINATE_H
#define AIDDATASDATEST_COORDINATE_H


class Coordinate {
public:
    //default constructor
    Coordinate(){}
    //We have a constructor which fills in the private fields
    Coordinate(float x, float y, bool isInA);
    //Get method for the stored x value
    float getX() const {
        return x;
    }
    //Get method for the stored y value
    float getY() const {
        return y;
    }
    //returns true if the coordinate is from a.csv, else returns false
    bool isInA() const{
        return InA;
    }
    //this constant method returns the distance between this coordinate and the parameter coordinate
    float distance(Coordinate* coordinate) const;

private:
    //this field will store the x value
    float x;
    float y;
    bool InA;
};


#endif //AIDDATASDATEST_COORDINATE_H

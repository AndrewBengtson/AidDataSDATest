//
// Created by agben on 4/23/2021.
//

#ifndef AIDDATASDATEST_COORDINATE_H
#define AIDDATASDATEST_COORDINATE_H


class Coordinate {
public:
    //We have a constructor which fills in the private fields
    Coordinate(int x, int y, bool isInA);
    //Get method for the stored x value
    int getX() {
        return x;
    }
    //Get method for the stored y value
    int getY() {
        return y;
    }
    //returns true if the coordinate is from a.csv, else returns false
    bool isInA(){
        return InA;
    }
    //this constant method returns the distance between this coordinate and the parameter coordinate
    int distance(Coordinate* coordinate) const;

private:
    //this field will store the x value
    int x;
    int y;
    bool InA;
};


#endif //AIDDATASDATEST_COORDINATE_H

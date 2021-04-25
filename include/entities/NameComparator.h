//
// Created by agben on 4/25/2021.
//

#ifndef AIDDATASDATEST_NAMECOMPARATOR_H
#define AIDDATASDATEST_NAMECOMPARATOR_H

//this class is used to sort golfers by their names
class NameComparator : public Comparator<Golfer>{
public:
    //this compares golfers only by their names, which will sort golfers with the same name together
    bool lessThan(Golfer &g1, Golfer &g2) override ;
    //this returns true if the golfers have the same name
    bool equals(Golfer &g1, Golfer &g2) override;
};


#endif //AIDDATASDATEST_NAMECOMPARATOR_H

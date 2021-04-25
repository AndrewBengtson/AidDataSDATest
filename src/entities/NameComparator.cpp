//
// Created by agben on 4/25/2021.
//

#include "entities/NameComparator.h"

bool NameComparator::lessThan(Golfer &g1, Golfer &g2) {
    //simply calls string.lessThan
    return g1.getName()<g2.getName();
}

bool NameComparator::equals(Golfer &g1, Golfer &g2) {
    return g1.getName()==g2.getName();
}

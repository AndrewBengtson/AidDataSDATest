#include "comparator/Comparator.h"

template<class Comparable>
bool Comparator<Comparable>::lessThanOrEqualTo(Comparable &obj1, Comparable &obj2) {
    return lessThan(obj1, obj2) || equals(obj1, obj2);
}

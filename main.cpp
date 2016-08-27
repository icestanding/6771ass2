#include <iostream>
#include "EuclideanVector.h"
#include <vector>
#include <list>
int main() {
    evec::EuclideanVector a(2);

    std::list<double> l {1,2,3};
    evec::EuclideanVector b{l.begin(),l.end()};

    std::vector<double> v2 {4,5,6,7};
    evec::EuclideanVector c{v2.begin(),v2.end()};

    std::vector<double> a1 {5,4,3,2};
    evec::EuclideanVector d{a1.begin(),a1.end()};

    std::list<double> a2 {9,0,8,6,7};
    evec::EuclideanVector e{a2.begin(),a2.end()};

    // use the copy constructor
    evec::EuclideanVector f{e};


    evec::EuclideanVector abc;

    std::cout<<e;
}
#include <iostream>
#include "EuclideanVector.h"
#include <vector>
#include <list>

int main() {

    evec::EuclideanVector a{1,2,3};
    std::cout<<a<<"\n";
    evec::EuclideanVector b = std::move(a);
    int c = b[1];
    std::cout<<c<<"\n";




}
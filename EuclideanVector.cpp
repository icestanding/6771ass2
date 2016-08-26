#include "EuclideanVector.h"
#include <iostream>
#include<cmath>
//
// Created by chenyu on 24/08/16.
//

/******************************************************/
/************* Constructor ****************************/
/******************************************************/
evec::EuclideanVector::EuclideanVector(int n_dim, double i_mag) : magnit{new std::vector<double>(n_dim, i_mag)} {}

// delegate constructor
evec::EuclideanVector::EuclideanVector(int n_dim) : magnit{new std::vector<double>(n_dim, 0.0)} {}

// initial_list constructor
evec::EuclideanVector::EuclideanVector(std::initializer_list<double> il):magnit{new std::vector<double>(il)} {}

// Copy constructor
evec::EuclideanVector::EuclideanVector(const evec::EuclideanVector &a): magnit{new std::vector<double>(*(a.magnit))} {}

// template/range constructor
//template<class T>
//evec:: EuclideanVector::EuclideanVector(std::_List_iterator<T> a, std::_List_iterator<T> b):magnit{new std::vector<T>{a, b}} {}
evec::EuclideanVector::
EuclideanVector(std::_List_iterator<double> begin,
                std::_List_iterator<double> end):
        magnit{new std::vector<double>{begin, end}} {};

evec::EuclideanVector::
EuclideanVector(std::vector<double>::const_iterator begin,
                std::vector<double>::const_iterator end):
        magnit{new std::vector<double>{begin, end}} {};

// move constructor
evec::EuclideanVector::EuclideanVector(EuclideanVector &&a): magnit(a.magnit) {
    a.magnit = nullptr;
}

evec::EuclideanVector::~EuclideanVector() {
    delete magnit;
};

// move operator
// copy operator
/*****************************************************/
/*************** Member function *********************/
/*****************************************************/

// getNumDimensions()
unsigned int evec::EuclideanVector::getNumDimensions() {
    return (unsigned int) magnit->size();
}
double evec::EuclideanVector::get(unsigned int i) {
    return magnit->at(i);
}
double evec::EuclideanVector::getEuclideanNorm(){
    double result = 0;
    for (unsigned int i = 0; i < magnit->size(); ++i) {
        result += pow(magnit->at(i), 2);
    }
    return sqrt(result);
}

void evec::EuclideanVector::getc(){
    std::cout<<this->magnit->size();
}


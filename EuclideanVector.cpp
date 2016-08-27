#include "EuclideanVector.h"
#include <iostream>
#include<cmath>
//
// Created by chenyu(Z3492794) on 24/08/16.
//

// be remeber of the return scope of the code

/******************************************************/
/************* Constructor ****************************/
/******************************************************/
evec::EuclideanVector::EuclideanVector(int n_dim, double i_mag) : magnit{new std::vector<double>(n_dim, i_mag)} {}

// delegate constructor
evec::EuclideanVector::EuclideanVector(int n_dim) : magnit{new std::vector<double>(n_dim, 0.0)} {}

evec::EuclideanVector::EuclideanVector():magnit{new std::vector<double>(1, 0.0)} {}
// initial_list constructor
evec::EuclideanVector::EuclideanVector(std::initializer_list<double> il):magnit{new std::vector<double>(il)} {}

// Copy constructor
evec::EuclideanVector::EuclideanVector(const evec::EuclideanVector &a): magnit{new std::vector<double>(*(a.magnit))} {}

// template/range constructor
//template<class T>
//evec:: EuclideanVector::EuclideanVector(std::_List_iterator<T> a, std::_List_iterator<T> b):magnit{new std::vector<T>{a, b}} {}
evec::EuclideanVector::
EuclideanVector(std::list<double>::iterator begin ,
                std::list<double>::iterator end):
        magnit{new std::vector<double>{begin, end}} {};

evec::EuclideanVector::
EuclideanVector(std::vector<double>::const_iterator begin,
                std::vector<double>::const_iterator end):
        magnit{new std::vector<double>{begin, end}} {};

// move constructor, noexcept
evec::EuclideanVector::EuclideanVector(EuclideanVector &&a) noexcept: magnit(a.magnit) {
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
unsigned int evec::EuclideanVector::getNumDimensions() const  {
    return (unsigned int) magnit->size();
}
double evec::EuclideanVector::get(unsigned int i) const {
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

evec::EuclideanVector evec::EuclideanVector::createUnitVector() {
    double norm  = getEuclideanNorm();
    EuclideanVector result(int(magnit->size()));
    for (unsigned int i = 0; i < magnit->size(); ++i) {
        result[i] = magnit->at(i) / norm;
    }
    return result;
}

double & evec::EuclideanVector::operator[](int i) {
    return magnit->at(i);
}

// copy assignment '='
evec::EuclideanVector & evec::EuclideanVector::operator= (const evec::EuclideanVector &rhs) {
    delete magnit;
    magnit = nullptr;
    magnit = new std::vector<double>;
    for (unsigned int i = 0; i < rhs.getNumDimensions(); ++i) {
        magnit->push_back(rhs.get(i));
    }
    return *this;
}

// move assignment '='
evec::EuclideanVector & evec::EuclideanVector::operator= (evec::EuclideanVector &&rhs) noexcept {
   if(this != &rhs) {
       this->magnit = rhs.magnit;
       delete rhs.magnit;
       rhs.magnit = nullptr;
   }
    return *this;
}


// +=
evec::EuclideanVector& evec::EuclideanVector::operator+= (const evec::EuclideanVector &rgt) {

    for (unsigned int i = 0; i < rgt.getNumDimensions(); i++) {
        magnit->at(i) = magnit->at(i) + rgt.get(i);
    }
    return *this;
}
// -=
evec::EuclideanVector& evec::EuclideanVector::operator-= (const evec::EuclideanVector &rgt) {

    for (unsigned int i = 0; i < rgt.getNumDimensions(); i++) {
        magnit->at(i) = magnit->at(i) - rgt.get(i);
    }
    return *this;
}
// *=
evec::EuclideanVector& evec::EuclideanVector::operator*= (const double &s) {

    for (unsigned int i = 0; i < getNumDimensions(); i++) {
        magnit->at(i) = magnit->at(i) *s;
    }
    return *this;
}
// /=
evec::EuclideanVector& evec::EuclideanVector::operator/= (const double &s) {

    for (unsigned int i = 0; i < getNumDimensions(); i++) {
        magnit->at(i) = magnit->at(i) / s;
    }
    return *this;
}
// Type Conversion
evec::EuclideanVector::operator std::vector<double> const() {
    std::vector<double> result = *magnit;
    return result;
};

evec::EuclideanVector::operator std::list<double> const() {
    std::list<double> result(magnit->begin(), magnit->end());
    return result;
};




// friend function
// +
evec::EuclideanVector evec::operator + (const evec::EuclideanVector &a, const evec::EuclideanVector &b) {
    evec::EuclideanVector result(a.getNumDimensions());
    for (unsigned int i = 0; i < a.getNumDimensions(); i++) {
        result[i] = a.get(i) + b.get(i);
    }
    return result;
}
// -
evec::EuclideanVector evec::operator - (const evec::EuclideanVector &lft, const evec::EuclideanVector &rgt) {
    evec::EuclideanVector result(lft.getNumDimensions());
    for (unsigned int i = 0; i < lft.getNumDimensions(); i++) {
        result[i] = lft.get(i) - rgt.get(i);
    }
    return result;
}
//  []*[]
double evec::operator* (const EuclideanVector &f, const EuclideanVector &s) {
    double result = 0;
    for (unsigned int i = 0; i < f.getNumDimensions(); ++i) {
        result += (f.get(i) * s.get(i));
    }
    return result;
}
//  []*double
evec::EuclideanVector evec::operator* (const evec::EuclideanVector &f, const double &num) {
    EuclideanVector result(f.getNumDimensions());
    for (unsigned int i = 0;  i < f.getNumDimensions(); ++i) {
        result[i] = f.get(i) * num;
    }
    return result;
}
// []/double
evec::EuclideanVector evec::operator / (const evec::EuclideanVector &f, const double &num) {
    EuclideanVector result(f.getNumDimensions());
    for (unsigned int i = 0;  i < f.getNumDimensions(); ++i) {
        result[i] = f.get(i) / num;
    }
    return result;
}
// stream << output
std::ostream & evec::operator<<(std::ostream &os, const EuclideanVector &obj) {
    if (obj.magnit == nullptr) {
        os <<'['<<']';
        return os;
    }
    os<<'[';
    for (unsigned int i = 0; i < obj.getNumDimensions() ; ++i) {
        if(i == obj.getNumDimensions() - 1) {
            os<<obj.get(i)<<']';
        }
        os<<obj.get(i)<<' ';
    }
    return os;

}

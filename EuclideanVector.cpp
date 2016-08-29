#include "EuclideanVector.h"
#include <iostream>
#include <cmath>

//
// Created by chenyu(Z3492794) on 24/08/16.
//

// be remeber of the return scope of the code

/******************************************************/
/************* Constructor ****************************/
/******************************************************/
evec::EuclideanVector::EuclideanVector(int n_dim, double i_mag) : size_{n_dim}, parray_{new double[n_dim]} {
    for(unsigned int i; i < size_; i++) {
        *(parray_ + i) = i_mag;
    }
}

// delegate constructor
evec::EuclideanVector::EuclideanVector(int n_dim) : evec::EuclideanVector(n_dim, 0.0) {}

evec::EuclideanVector::EuclideanVector(): evec::EuclideanVector(1, 0.0) {}
// initial_list constructor
evec::EuclideanVector::EuclideanVector(std::initializer_list<double> il): size_(il.size()) {
    parray_ = new double[size_];
    auto tmp = std::vector<double>(il.begin(), il.end());
    for (unsigned int i = 0; i < size_; ++i) {
        *(parray_ + i) = tmp[i];
    }

}

// Copy constructor
evec::EuclideanVector::EuclideanVector(const evec::EuclideanVector &a)
{
    size_ = a.size_;
    parray_ = new double[a.size_];
    for (unsigned int i = 0; i < a.size_; ++i) {
        *(parray_ + i) = a.get(i);
    }
}

// move constructor, noexcept
evec::EuclideanVector::EuclideanVector(EuclideanVector &&a) noexcept {
    if (a.parray_ != nullptr) {
        parray_ = a.parray_;
        a.parray_ = nullptr;
        size_ = a.size_;
        a.size_ = 0;
    }
}
//
// template/range constructor
// for list
evec::EuclideanVector::
EuclideanVector(std::list<double>::iterator begin , std::list<double>::iterator end) {
    auto tmp = std::vector<double>(begin, end);
    size_ = tmp.size();
    parray_  = new double[size_];
    for (unsigned int i = 0; i < size_; ++i) {
        *(parray_ + i) = tmp.at(i);
    }
};

// for array
evec::EuclideanVector::
EuclideanVector(std::vector<double>::const_iterator begin, std::vector<double>::const_iterator end) {
    auto tmp = std::vector<double>(begin, end);
    size_ = tmp.size();
    parray_  = new double[size_];
    for (unsigned int i = 0; i < size_; ++i) {
        *(parray_ + i) = tmp.at(i);
    }
};


// Destructor
evec::EuclideanVector::~EuclideanVector() {
    if (parray_ != NULL) {
        delete [] parray_;
        parray_ = nullptr;
    }
};

// move operator
// copy operator
/*****************************************************/
/*************** Member function *********************/
/*****************************************************/

// getNumDimensions()
unsigned int evec::EuclideanVector::getNumDimensions() const  {
    return (unsigned int) size_;
}
// get value
double evec::EuclideanVector::get(unsigned int i) const {
    return *(parray_ + i);
}
double evec::EuclideanVector::getEuclideanNorm(){
    double result = 0;
    for (unsigned int i = 0; i < size_; ++i) {
        result += pow(get(i), 2);
    }
    return sqrt(result);
}


evec::EuclideanVector evec::EuclideanVector::createUnitVector() {
    double norm  = getEuclideanNorm();
    EuclideanVector result(size_);
    for (unsigned int i = 0; i < size_; ++i) {
        *(result.parray_ + i) = *(parray_ + i) / norm;
    }
    return result;
}
//
double & evec::EuclideanVector::operator[](int i) {
    return *(parray_ + i);
}
//
// copy assignment '='
evec::EuclideanVector & evec::EuclideanVector::operator= (const evec::EuclideanVector &rhs) {
    delete parray_;
    parray_ = nullptr;
    parray_ = new double[rhs.size_];
    size_ = rhs.size_;
    for (unsigned int i = 0; i < size_; ++i) {
        *(parray_ + i) = *(rhs.parray_ + i) ;
    }
    return *this;
}
//
// move assignment '='
evec::EuclideanVector & evec::EuclideanVector::operator= (evec::EuclideanVector &&rhs) noexcept {
   if(this != &rhs) {
       this->parray_ = rhs.parray_;
       this->size_ = rhs.size_;
       rhs.parray_ = nullptr;
   }
    return *this;
}
//
//
// +=
evec::EuclideanVector& evec::EuclideanVector::operator+= (const evec::EuclideanVector &rgt) {

    for (unsigned int i = 0; i < rgt.getNumDimensions(); i++) {
        *(parray_ + i) = this->get(i) + rgt.get(i);
    }
    return *this;
}
// -=
evec::EuclideanVector& evec::EuclideanVector::operator-= (const evec::EuclideanVector &rgt) {

    for (unsigned int i = 0; i < rgt.getNumDimensions(); i++) {
        *(parray_ + i) = this->get(i) - rgt.get(i);
    }
    return *this;
}
// *=
evec::EuclideanVector& evec::EuclideanVector::operator*= (const double &s) {

    for (unsigned int i = 0; i < getNumDimensions(); i++) {
        *(parray_ + i) = *(parray_ + i) * s;
    }
    return *this;
}
// /=
evec::EuclideanVector& evec::EuclideanVector::operator/= (const double &s) {

    for (unsigned int i = 0; i < getNumDimensions(); i++) {
        *(parray_ + i) = *(parray_ + i) / s;
    }
    return *this;
}
// Type Conversion
evec::EuclideanVector::operator std::vector<double> const() {
    std::vector<double> result;
    for (unsigned int i; i < size_; i++) {
        result.push_back(*(parray_ + i));
    }
    return result;
};
//
evec::EuclideanVector::operator std::list<double> const() {
    std::list<double> result;
    for (unsigned int i; i < size_; i++) {
        result.push_back(*(parray_ + i));
    }
    return result;
};

// friend function
// +
evec::EuclideanVector evec::operator + (const evec::EuclideanVector &lft, const evec::EuclideanVector &rgt) {
    evec::EuclideanVector result(lft.getNumDimensions());
    for (unsigned int i = 0; i < lft.getNumDimensions(); i++) {
        result[i] = lft.get(i) + rgt.get(i);
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
// == operator
bool evec::operator == (const EuclideanVector &l, const EuclideanVector &r) {
    if (l.size_ != r.size_) {
        return false;
    }
    for (unsigned int i = 0; i < l.size_; ++i) {
        if(l.get(i) != r.get(i)) {
            return false;
        }
    }
    return true;
}
// != operator
bool evec::operator != (const EuclideanVector &l, const EuclideanVector &r) {
    if (l == r) {
        return false;
    }
    else {
        return true;
    }
}


// stream << output
std::ostream & evec::operator<<(std::ostream &os, const EuclideanVector &obj) {
    if (obj.parray_ == nullptr) {
        os <<'['<<']';
        return os;
    }
    os<<'[';
    for (unsigned int i = 0; i < obj.getNumDimensions() ; ++i) {
        if(i == obj.getNumDimensions() - 1) {
            os<<obj.get(i)<<']';
            break;
        }
        os<<obj.get(i)<<' ';
    }
    return os;
}

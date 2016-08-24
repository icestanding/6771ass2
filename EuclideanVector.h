//
// Created by chenyu on 24/08/16.
//
#include <arpa/nameser.h>
#include <vector>

#ifndef ASS2_EUCLIDEANVECTOR_H
#define ASS2_EUCLIDEANVECTOR_H

#endif //ASS2_EUCLIDEANVECTOR_H

namespace evec {
    class EuclideanVector {
    private:
        std::vector<double> *magnit;
    public:
        // initial pointer;
        EuclideanVector(int n_dim, double i_mag) : magnit{new std::vector<double>(n_dim, i_mag)} {}
        // delegate constructor
        EuclideanVector(int n_dim) : magnit{new std::vector<double>(n_dim, 0.0)} {}
        // template/range constructor
        template<class T> EuclideanVector(T first, T last):magnit{new std::vector<T>(first, last)} {}
        // initial_list constructor
        EuclideanVector(std::initializer_list<double> il):magnit{new std::vector<double>(il)} {}
        void getc() ;
    };
}


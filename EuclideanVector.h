//
// Created by chenyu on 24/08/16.
//
#include <arpa/nameser.h>
#include <vector>
#include <list>
#include <iterator>

#ifndef ASS2_EUCLIDEANVECTOR_H
#define ASS2_EUCLIDEANVECTOR_H

#endif //ASS2_EUCLIDEANVECTOR_H

namespace evec {
    class EuclideanVector {
    private:
        std::vector<double> *magnit;
    public:
        /******************************************************/
        /************* Constructor ****************************/
        /******************************************************/

        // initial pointer;
        EuclideanVector(int n_dim, double i_mag);

        // delegate constructor
        EuclideanVector(int n_dim);

        // template/range constructor
//        template<class T>
        EuclideanVector(std::_List_iterator<double> begin, std::_List_iterator<double> end);

//        template<class C>
        EuclideanVector(std::vector<double>::const_iterator begin, std::vector<double>::const_iterator end);

        // initial_list constructor
        EuclideanVector(std::initializer_list<double> il);

        // Copy constructor
        EuclideanVector(const EuclideanVector &a);

        // move constructor
        EuclideanVector(EuclideanVector &&a);

        // Destructor, need more stuff
        ~EuclideanVector();

        /*****************************************************/
        /*************** Member function *********************/
        /*****************************************************/
        unsigned int getNumDimensions();
        double get(unsigned int i);

        void getc();

    };
}

// Two question template declaration, and test case all double?
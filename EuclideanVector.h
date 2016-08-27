//
// Created by chenyu on 24/08/16.
//
#include <arpa/nameser.h>
#include <vector>
#include <list>
#include <iterator>
#include <cmath>

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
        EuclideanVector();
        // initial pointer;
        EuclideanVector(int n_dim, double i_mag);

        // delegate constructor
        EuclideanVector(int n_dim);

        // template/range constructor
//        template<class T>
        EuclideanVector(std::list<double>::iterator begin, std::list<double>::iterator end);

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
        unsigned int getNumDimensions() const;
        double get(unsigned int i) const;
        double getEuclideanNorm();
        EuclideanVector createUnitVector();
        void getc();

        /*****************************************************/
        /*************** operator overload *******************/
        /*****************************************************/

        // get specific value
        double & operator[](int i);

        // copy assignment
        EuclideanVector& operator= (const EuclideanVector &rhs);

        // member operator
        EuclideanVector& operator+= (const EuclideanVector &);



        // operator
        friend EuclideanVector operator + (const EuclideanVector &, const EuclideanVector &);
        friend EuclideanVector operator - (const EuclideanVector &, const EuclideanVector &);



    };

    EuclideanVector operator + (const EuclideanVector &, const EuclideanVector &) ;
    EuclideanVector operator - (const EuclideanVector &, const EuclideanVector &);

}

// Two question template declaration, and test case all double?

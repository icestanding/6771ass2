//
// Created by chenyu(Z3492794) on 24/08/16.
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
        EuclideanVector(EuclideanVector &&a) noexcept;

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

        // Assignment
        // Copy
        EuclideanVector& operator= (const EuclideanVector &rhs);
        // Move
        EuclideanVector& operator= (EuclideanVector &&rhs) noexcept;
        // Operator
        EuclideanVector& operator+= (const EuclideanVector &);
        EuclideanVector& operator-= (const EuclideanVector &);
        EuclideanVector& operator*= (const double &);
        EuclideanVector& operator/= (const double &);
        // Type Conversion
        operator std::vector<double> const();
        operator std::list<double> const();

        // Operator
        friend EuclideanVector operator + (const EuclideanVector &, const EuclideanVector &);
        friend EuclideanVector operator - (const EuclideanVector &, const EuclideanVector &);
        friend double operator* (const EuclideanVector &, const EuclideanVector &);
        friend EuclideanVector operator* (const EuclideanVector &, double num);
        friend EuclideanVector operator / (const EuclideanVector &, const double &);
        friend std::ostream& operator<< (std::ostream& os, const EuclideanVector& obj);

    };

    // +
    EuclideanVector operator + (const EuclideanVector &, const EuclideanVector &);
    // -
    EuclideanVector operator - (const EuclideanVector &, const EuclideanVector &);
    // *
    // for [][]
    double operator * (const EuclideanVector &, const EuclideanVector &);
    // for []*double
    EuclideanVector operator * (const EuclideanVector &, const double &);
    // /
    EuclideanVector operator / (const EuclideanVector &, const double &);
    // stream output
    std::ostream& operator<< (std::ostream& os, const EuclideanVector& obj);

}

// Two question template declaration, and test case all double?

//
// Created by ksenia on 11/30/19.
//

#ifndef CLASS_MATRIX_LINEARALGEBRA_H
#define CLASS_MATRIX_LINEARALGEBRA_H


#include <vector>
#include <algorithm>
#include <cstdio>
#include <stdexcept>
#include <type_traits>
#include <iostream>
#include "controls_id.h"
namespace la {
    class matrix {
    protected:
        std::vector<float> data_;
        size_t amount_of_rows_;
        size_t amount_of_columns_;
    public:

        matrix(size_t const &rows, size_t const &columns, size_t const& capacity = MAX_SIZE ) : data_(capacity*capacity),
                                                            amount_of_rows_(rows),
                                                            amount_of_columns_(columns) {

        }

        matrix(size_t const &dim) : data_(MAX_SIZE * MAX_SIZE),
                                                            amount_of_rows_(dim),
                                                            amount_of_columns_(dim) {

        }

        friend bool can_add(const matrix& A, const matrix& B)
        {
            return A.amount_of_rows_ == B.amount_of_rows_ && A.amount_of_columns_ == B.amount_of_columns_;
        }
        friend bool can_sub(const matrix& A, const matrix& B)
        {
            return can_add(A,B);
        }
        friend bool can_mult(const matrix& A, const matrix& B)
        {
            return A.amount_of_columns_ == B.amount_of_rows_;
        }
        friend bool can_div(const matrix& A, const matrix& B)
        {
            return B.is_invertible() && A.amount_of_columns_ == B.amount_of_columns_;
        }
        bool is_invertible() const
        {
            return determinant() != 0;
        }

        size_t get_h()
        {
            return amount_of_rows_;
        }
        size_t get_w()
        {
            return amount_of_columns_;
        }
//        matrix(matrix const &rhs) = default;

        matrix() = default;

        float const &operator()(size_t const &row, size_t const &column) const;

        float &operator()(size_t const &row, size_t const &column);

        matrix &operator+=(matrix const &rhs);

        friend matrix operator+(matrix const &lhs, matrix const &rhs);

        matrix &operator-=(matrix const &rhs);

        friend matrix operator-(matrix const &lhs, matrix const &rhs);

        matrix &operator/=(float const &rhs);

        friend matrix operator/(matrix const &lhs, float const &rhs);

        matrix &operator*=(float const &rhs);

        friend matrix operator*(matrix const &lhs, float const &rhs);

        friend matrix operator*(float const &lhs, matrix const &rhs);

        matrix &operator*=(matrix const &rhs);

        friend matrix operator*(matrix const &lhs, matrix &rhs);

        friend bool operator==(matrix const &lhs, matrix const &rhs);

        friend bool operator!=(matrix const &lhs, matrix const &rhs);

        float determinant() const;

        matrix &transpose();

        matrix &inverse();

        size_t height() const;

        size_t length() const;

        friend std::ostream &operator<<(std::ostream &cout, matrix const &a);

        friend std::istream &operator>>(std::istream &cin, matrix &a);

        friend bool can_similarity_transformation(const matrix& R, const matrix& H);

        friend matrix similarity_transformation(const matrix& R, const matrix& H);

        matrix principal_leading_submatrix(const size_t dim) const;

        float principal_leading_minor(const size_t dim);

        bool all_corner_minors_greater_rho(const size_t& rho);

        friend matrix intermediate_step(const size_t dim, const matrix& from, const matrix& to);

//        friend bool is_in_R(matrix& R, const float rho = 1);
    };//


    matrix transpose(matrix const &a);

    matrix inverse(matrix const &a) ;

    matrix E(size_t i);


}


#endif //CLASS_MATRIX_LINEARALGEBRA_H

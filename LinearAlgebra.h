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

        matrix(size_t const rows, size_t const columns) : data_(columns*rows),
                                                          amount_of_rows_(rows),
                                                          amount_of_columns_(columns) {}

        matrix(size_t const &dim) : data_(dim*dim),
                                    amount_of_rows_(dim),
                                    amount_of_columns_(dim) {}


        matrix() = default;

        float const &operator()(size_t const row, size_t const column) const;

        float &operator()(size_t const row, size_t const column);

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

        bool all_corner_minors_greater_rho(const float rho);

        matrix intermediate_step(const matrix &from, const matrix &to);

        friend matrix intermediate_step(const size_t dim, const matrix& from, const matrix& to);

        friend bool is_rho_law_abiding(const matrix& R, const matrix& H, const float rho = 0);

        friend bool can_add(const matrix& A, const matrix& B);

        friend bool can_sub(const matrix& A, const matrix& B);

        friend bool can_mult(const matrix& A, const matrix& B);

        friend bool can_div(const matrix& A, const matrix& B);

        bool is_invertible() const;

        size_t get_h();

        size_t get_w();

        void set_h(size_t new_rows);

        void set_w(size_t new_cols);

        bool is_in_R(const float rho = 0);

        bool is_in_H(const float rho = 0);

        bool is_square();

        bool is_lower_triangular();
    };


    matrix transpose(matrix const &a);

    matrix inverse(matrix const &a) ;

    matrix E(size_t i);


}


#endif //CLASS_MATRIX_LINEARALGEBRA_H

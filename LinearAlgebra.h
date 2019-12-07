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
namespace la {
    class matrix {
    protected:
        std::vector<float> data_;
        size_t amount_of_rows_;
        size_t amount_of_columns_;
    public:

        matrix(size_t const &rows, size_t const &columns) : data_(10 * 10),
                                                            amount_of_rows_(rows),
                                                            amount_of_columns_(columns) {

        }
        bool set_w(size_t new_w)
        {
            if(new_w <= 10) {
                amount_of_columns_ = new_w;
                return true;
            }
            return false;
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
            return B.is_invertible();
        }
        bool is_invertible() const
        {
            return determinant() != 0;
        }
        bool set_h(size_t new_h)
        {
            if(new_h <= 10) {
                amount_of_rows_ = new_h;
                return true;
            }
            return false;
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
    };

    matrix transpose(matrix const &a);

    matrix inverse(matrix const &a);

    matrix E(size_t i);
}


#endif //CLASS_MATRIX_LINEARALGEBRA_H

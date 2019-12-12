//
// Created by ksenia on 11/30/19.
//

#include "LinearAlgebra.h"
#include "controls_id.h"


namespace la {
    float const &matrix::operator()(size_t const &row, size_t const &column) const {
        if (row >= amount_of_rows_ || column >= amount_of_columns_) {

            char error[256];
            std::sprintf(error,
                         "Adress to [%zu][%zu], size of matrix is [%zu][%zu]",
                         row, column, amount_of_rows_, amount_of_columns_);
            throw std::out_of_range(error);
        }
        // std::cout << "." << row * columns_capacity + column << ".";
        return data_[row * MAX_SIZE + column];
    }

    float &matrix::operator()(size_t const &row, size_t const &column) {
        return const_cast<float &>(const_cast<const matrix *>(this)->operator()(row, column));
    }

    matrix &matrix::operator+=(matrix const &rhs) {
        if (amount_of_rows_ != rhs.amount_of_rows_ || amount_of_columns_ != rhs.amount_of_columns_) {
            char error[256];
            std::sprintf(error,
                         "Sum of matrices with different sizes lhs:[%zu][%zu], rhs:[%zu][%zu]",
                         amount_of_rows_, amount_of_columns_, rhs.amount_of_rows_, rhs.amount_of_columns_);
            throw std::runtime_error(error);
        }
        std::transform(data_.begin(), data_.end(), rhs.data_.begin(), data_.begin(),
                       [](float &lhs_value, float const &rhs_value) { return lhs_value += rhs_value; });
        return *this;
    }

    matrix operator+(matrix const &lhs, matrix const &rhs) {
        return matrix(lhs) += rhs;
    }

    matrix &matrix::operator-=(matrix const &rhs) {
        if (amount_of_rows_ != rhs.amount_of_rows_ || amount_of_columns_ != rhs.amount_of_columns_) {
            char error[256];
            std::sprintf(error,
                         "Sub of matrices with different sizes lhs:[%zu][%zu], rhs:[%zu][%zu]",
                         amount_of_rows_, amount_of_columns_, rhs.amount_of_rows_, rhs.amount_of_columns_);
            throw std::runtime_error(error);
        }
        std::transform(data_.begin(), data_.end(), rhs.data_.begin(), data_.begin(),
                       [](float &lhs_value, float const &rhs_value) { return lhs_value -= rhs_value; });
        return *this;
    }

    matrix operator-(matrix const &lhs, matrix const &rhs) {
        return matrix(lhs) -= rhs;
    }

    matrix &matrix::operator/=(float const &rhs) {
        if (rhs == 0) {
            throw std::runtime_error("Divizion by zero");
        }
        std::transform(data_.begin(), data_.end(), data_.begin(),
                       [rhs](float &lhs_value) { return lhs_value /= rhs; });
        return *this;
    }

    matrix operator/(matrix const &lhs, float const &rhs) {
        return matrix(lhs) /= rhs;
    }

    matrix &matrix::operator*=(float const &rhs) {
        if (rhs == 0) {
            throw std::runtime_error("Divizion by zero");
        }
        std::transform(data_.begin(), data_.end(), data_.begin(),
                       [rhs](float &lhs_value) { return lhs_value *= rhs; });
        return *this;
    }

    matrix operator*(matrix const &lhs, float const &rhs) {
        return matrix(lhs) *= rhs;
    }

    matrix operator*(float const &lhs, matrix const &rhs) {
        return matrix(rhs) *= lhs;
    }

    matrix &matrix::operator*=(matrix const &rhs) {
        if (amount_of_columns_ != rhs.amount_of_rows_) {
            char error[256];
            std::sprintf(error,
                         "Mul of matrices with bad sizes lhs:[%zu][%zu], rhs:[%zu][%zu]",
                         amount_of_rows_, amount_of_columns_, rhs.amount_of_rows_, rhs.amount_of_columns_);
            throw std::runtime_error(error);
        }
        matrix tmp(amount_of_rows_, rhs.amount_of_columns_);
        for (size_t i = 0; i < amount_of_rows_; i++) {
            for (size_t j = 0; j < rhs.amount_of_columns_; j++) {
                tmp(i, j) = operator()(i, 0) * rhs(0, j);
                for (size_t k = 1; k < amount_of_columns_; k++) {
                    tmp(i, j) += operator()(i, k) * rhs(k, j);
                }
            }
        }
        this->data_ = tmp.data_;
        amount_of_columns_ = rhs.amount_of_columns_;
        return *this;
    }

    matrix operator*(matrix const &lhs, matrix &rhs) {
        return matrix(lhs) *= rhs;
    }

    bool operator==(matrix const &lhs, matrix const &rhs) {
        if (lhs.amount_of_rows_ != rhs.amount_of_rows_ ||
            lhs.amount_of_columns_ != rhs.amount_of_columns_)
            return false;
        return std::equal(lhs.data_.begin(), lhs.data_.end(), rhs.data_.begin());
    }

    bool operator!=(matrix const &lhs, matrix const &rhs) {
        return !(lhs == rhs);
    }

    float matrix::determinant() const {
        if (amount_of_rows_ != amount_of_columns_) {
            char error[256];
            std::sprintf(error,
                         "Can't get determinant from non-square matrix [%zu][%zu]",
                         amount_of_rows_, amount_of_columns_);
            throw std::runtime_error(error);
        }
        //matrix tmp_matrix = principal_leading_submatrix(amount_of_columns_);
        std::vector<float> tmp;//(tmp_matrix.data_.begin(), data_.end());

        for(int i = amount_of_columns_-1; i >= 0; i--) {
            for (int j = amount_of_rows_ - 1; j >= 0; j--) {
                tmp.push_back((*this)(i, j));
            }
        }
        float res = 1.0;
        for (size_t i = 0; i < amount_of_rows_; i++) {
            size_t change = i;
            for (; change < amount_of_rows_; change++) {
                if (tmp[change * amount_of_columns_ + i] != 0) break;
            }
            if (change == amount_of_rows_) {
                return 0.0;
            }

            if (change != i) {
                res *= -1.0;
                std::swap_ranges(tmp.begin() + i * amount_of_columns_,
                                 tmp.begin() + (i + 1) * amount_of_columns_,
                                 tmp.begin() + change * amount_of_columns_);
            }
            for (size_t k = i + 1; k < amount_of_rows_; k++) {
                float mn = -1 * (tmp[k * amount_of_columns_ + i] / tmp[i * amount_of_columns_ + i]);
                std::transform(tmp.begin() + i * amount_of_columns_,
                               tmp.begin() + (i + 1) * amount_of_columns_,
                               tmp.begin() + k * amount_of_columns_,
                               tmp.begin() + k * amount_of_columns_,
                               [mn](float lhs, float rhs) { return rhs + mn * lhs; });
            }
        }

        for (size_t i = 0; i < amount_of_rows_; i++)
            res *= tmp[i * amount_of_columns_ + i];
        return res;
    }

    matrix &matrix::transpose() {
        if (amount_of_rows_ == 1 || amount_of_columns_ == 1) {
            std::swap(amount_of_rows_, amount_of_columns_);
            return *this;
        }
        if (amount_of_rows_ == amount_of_columns_) {
            for (size_t i = 0; i < (amount_of_rows_ + 1) / 2; i++) {
                for (size_t j = i + 1; j < amount_of_columns_; j++) {
                    std::swap(data_[i * amount_of_columns_ + j], data_[i + j * amount_of_rows_]);
                }
            }
            return *this;
        }
        std::vector<bool> state(amount_of_columns_ * amount_of_rows_, false);
        size_t i = 0;
        while (i < data_.size()) {
            if (state[i]) {
                i++;
                continue;
            }
            state[i] = true;
            size_t save_state = i;
            float tmp = data_[i];
            do {
                i = (i % amount_of_columns_) * amount_of_rows_ + i / amount_of_columns_;
                std::swap(tmp, data_[i]);
                state[i] = true;
            } while (i != save_state);
        }

        std::swap(amount_of_rows_, amount_of_columns_);

        return *this;
    }

    matrix &matrix::inverse() {
        if (amount_of_rows_ != amount_of_columns_) {
            char error[256];
            std::sprintf(error,
                         "Can't inverse non-square matrix [%zu][%zu]",
                         amount_of_rows_, amount_of_columns_);
            throw std::runtime_error(error);
        }

        std::vector<float> tmp[2] = {std::vector<float>(amount_of_rows_ * amount_of_rows_),
                                     std::vector<float>(amount_of_rows_ * amount_of_rows_)};
        for (size_t i = 0; i < data_.size(); i++) {
            tmp[0][i] = data_[i];
        }
        for(int i = 0; i < amount_of_columns_; i++) {
            for (int j = 0; j < amount_of_columns_; j++) {
                tmp[0][i] = ((*this)(i, j));
            }
        }
        for (size_t i = 0; i < amount_of_rows_; i++) {
            for (size_t j = 0; j < amount_of_columns_; j++) {
                tmp[1][i * amount_of_columns_ + j] = (i == j) ? 1.0 : 0.0;
            }
        }

        for (size_t i = 0; i < amount_of_rows_; i++) {
            size_t change = i;
            for (; change < amount_of_rows_; change++) {
                if (tmp[0][change * amount_of_columns_ + i] != 0) break;
            }
            if (change == amount_of_rows_) {
                throw std::runtime_error("Can't inverse matrix matrix with determinant = 0");
            }

            if (change != i) {
                for (auto &t : tmp) {
                    std::swap_ranges(t.begin() + i * amount_of_columns_,
                                     t.begin() + (i + 1) * amount_of_columns_,
                                     t.begin() + change * amount_of_columns_);
                }
            }
            float mn = 1.0 / tmp[0][i * amount_of_columns_ + i];
            for (auto &t : tmp) {
                std::for_each(t.begin() + i * amount_of_columns_,
                              t.begin() + (i + 1) * amount_of_columns_,
                              [mn](auto &lhs) { lhs *= mn; });
            }

            for (size_t k = i + 1; k < amount_of_rows_; k++) {
                mn = -1.0 * tmp[0][k * amount_of_columns_ + i];
                for (auto &t : tmp) {
                    std::transform(t.begin() + i * amount_of_columns_,
                                   t.begin() + (i + 1) * amount_of_columns_,
                                   t.begin() + k * amount_of_columns_,
                                   t.begin() + k * amount_of_columns_,
                                   [mn](float lhs, float rhs) { return rhs + mn * lhs; });
                }
            }
        }
        for (size_t i = amount_of_rows_; i--;) {
            for (size_t j = i + 1; j < amount_of_rows_; j++) {
                float mn = -1.0 * tmp[0][i * amount_of_columns_ + j];
                std::transform(tmp[1].begin() + i * amount_of_columns_,
                               tmp[1].begin() + (i + 1) * amount_of_columns_,
                               tmp[1].begin() + j * amount_of_columns_,
                               tmp[1].begin() + i * amount_of_columns_,
                               [mn](float lhs, float rhs) { return lhs + mn * rhs; });
            }
        }
        this->data_ = std::vector<float>(tmp[1].begin(), tmp[1].end());
        return *this;
    }




    size_t matrix::height() const {
        return amount_of_rows_;
    }

    size_t matrix::length() const {
        return amount_of_columns_;
    }

    std::ostream &operator<<(std::ostream &cout, matrix const &a) {
        for (size_t i = 0; i < a.amount_of_rows_; i++) {
            for (size_t j = 0; j < a.amount_of_columns_; j++) {
                cout << a(i, j) << ' ';
            }
            cout << '\n';
        }
        return cout;
    }

    std::istream &operator>>(std::istream &cin, matrix &a) {
        //size_t h, l;
        // cin >> h >> l;
        //a = matrix(a.get_h(), a.get_l());
        for (size_t i = 0; i < a.get_h(); i++) {
            for (size_t j = 0; j < a.get_w(); j++) {
                cin >> a(i, j);
            }
        }
        return cin;
    }

    matrix similarity_transformation(const matrix &R, const matrix &H) {
        matrix M(R.amount_of_columns_);
        M = R;// * H;
        M *= H;
        M *= inverse(R);
        return M;
    }

    bool can_similarity_transformation(const matrix &R, const matrix &H) {
        return R.determinant() != 0;
    }

    matrix matrix::principal_leading_submatrix(const size_t dim) const{
        matrix submatrix(dim, dim, dim);
        for (size_t i = 0; i < dim; i++) {
            for (size_t j = 0; j < dim; j++) {
                submatrix(i, j) = data_[i * 10 + j];
            }
        }
        return submatrix;
    }


    float matrix::principal_leading_minor(const size_t dim) {
        return principal_leading_submatrix(dim).determinant();
    }

    matrix intermediate_step(const size_t dim, const matrix &from, const matrix &to) {
        matrix S = from;
        for (size_t i = 0; i < dim; i++) {
            for (size_t j = 0; j < S.get_w(); j++) {
                S(i, j) = to(i, j);
            }
        }
        return S;
    }


    bool matrix::all_corner_minors_greater_rho(const size_t &rho) {
        for (size_t i = 0; i < amount_of_columns_; i++) {
            if (principal_leading_minor(i) < rho) {
                return false;
            }

        }
        return true;
    }


//    bool is_in_R(matrix &R, const float rho) {
//        return R.all_corner_minors_greater_rho(rho);
//    }


    matrix transpose(matrix const &a) {
        return matrix(a).transpose();
    }

    matrix inverse(matrix const &a) {
        return matrix(a).inverse();
    }

    matrix E(size_t n) {
        matrix result(n, n);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                result(i, j) = (i == j) ? 1.0 : 0.0;
            }
        }
        return result;
    }


}
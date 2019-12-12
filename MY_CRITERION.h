//
// Created by ksenia on 12/7/19.
//

#ifndef MATRIXCALCULATOR_MY_CRITERION_H
#define MATRIXCALCULATOR_MY_CRITERION_H

#include "GLUI_LinearAlgebra.h"
using namespace GLUI_la;

class MY_CRITERION_matrix : public GLUI_matrix {
    bool is_rho_law_obiding_ST(const MY_CRITERION_matrix& R, const MY_CRITERION_matrix& H, bool prove_side );
    bool is_rho_law_obiding_IS(const MY_CRITERION_matrix& R, const MY_CRITERION_matrix& H, bool prove_side );
public:
    friend bool is_rho_law_obiding(const MY_CRITERION_matrix& R, const MY_CRITERION_matrix& H);
    bool can_similarity_transformation(const MY_CRITERION_matrix& R, const MY_CRITERION_matrix& H) ;
    MY_CRITERION_matrix& similarity_transformation(const MY_CRITERION_matrix& R, const MY_CRITERION_matrix& H) const;
    MY_CRITERION_matrix& principal_leading_submatrix(const size_t dim);
    float principal_leading_minor(const size_t dim);
    matrix& intermediate_step(const size_t dim, const MY_CRITERION_matrix& from_matrix, const MY_CRITERION_matrix& to_matrix);


};


#endif //MATRIXCALCULATOR_MY_CRITERION_H

//
// Created by ksenia on 12/7/19.
//

#include "MY_CRITERION.h"

using namespace GLUI_la;

#define VIA_SIMILARITY_TRANSFORMATION 0
#define VIA_INTERMEDIATE_STEPS 1


bool is_rho_law_obiding(const MY_CRITERION_matrix& R, const MY_CRITERION_matrix& H)
{

}
bool MY_CRITERION_matrix::can_similarity_transformation(const MY_CRITERION_matrix& R, const MY_CRITERION_matrix& H)
{
    return R.determinant() != 0;
}

//bool MY_CRITERION_matrix::is_rho_law_obiding_ST(const MY_CRITERION_matrix& R, const MY_CRITERION_matrix& H){}

bool is_rho_law_obiding_IS(const MY_CRITERION_matrix& R, const MY_CRITERION_matrix& H)
{

}


MY_CRITERION_matrix& MY_CRITERION_matrix::similarity_transformation(const MY_CRITERION_matrix& R, const MY_CRITERION_matrix& H) const
{
    MY_CRITERION_matrix M = R;
    M *= H;
//    M *= inverse(R);
    return M;
}

MY_CRITERION_matrix& MY_CRITERION_matrix::principal_leading_submatrix(const size_t dim){
   MY_CRITERION_matrix sub;//(dim);
    for(size_t row = 0; row < dim; row++)
    {
        for(size_t col = 0 ; col < amount_of_columns_; col++)
        {
           // sub(row, col) =
        }
    }
}
float principal_leading_minor(const size_t dim);
matrix& intermediate_step(const size_t dim, const MY_CRITERION_matrix& from_matrix, const MY_CRITERION_matrix& to_matrix);
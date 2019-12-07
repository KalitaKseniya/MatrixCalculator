//
// Created by ksenia on 12/6/19.
//

#ifndef MATRIXCALCULATOR_GLUI_LINEARALGEBRA_H
#define MATRIXCALCULATOR_GLUI_LINEARALGEBRA_H

#include "LinearAlgebra.h"
#include "GL/glut.h"
#include "glui.h"
#include "controls_id.h"

using namespace la;


class GLUI_matrix : public matrix {
    GLUI_Spinner* spinner_rows_;
    GLUI_Spinner* spinner_columns_;
    GLUI_Panel* panel_dimension;
    GLUI_EditText** edittext_data_;
    GLUI_Panel* panel_matrix;
    bool spin_limits = 0;
public:
    GLUI_matrix(const size_t& row_, const size_t& col_) : matrix(row_, col_) {
        spinner_rows_ = new GLUI_Spinner;
        spinner_columns_ = new GLUI_Spinner;
        panel_dimension = new GLUI_Panel;
        edittext_data_ = new GLUI_EditText *[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++) {
            edittext_data_[i] = new GLUI_EditText[MAX_SIZE];
        }
        panel_matrix = new GLUI_Panel;
    }
    GLUI_matrix() : GLUI_matrix(0,0) {}
    GLUI_matrix(const matrix& m) : matrix(m) {};

    GLUI_matrix& operator=(GLUI_matrix const& M)
    {
        if(this != &M)
        {
            amount_of_rows_ = M.amount_of_rows_;
            amount_of_columns_ = M.amount_of_columns_;
            for(size_t i = 0; i < amount_of_rows_; i++)
            {
                for(size_t j = 0; j < amount_of_columns_; j++)
                {
                    data_[i * MAX_SIZE + j]= M(i,j);
                }
            }
        }
        return *this;
    }
    //add dimensions(as spinners) groupped in the panel to the glui_wnd
    void spinner_display(GLUI* glui_wnd, GLUI_CB (control_cb_func), const int min_limit = MIN_SIZE, const int max_limit = MAX_SIZE, const int id = ID_SPINNER_DIMENSION);
    void set_spinner(GLUI* glui_wnd, GLUI_Spinner* spinner, std::string name, size_t& live_var, GLUI_CB (control_cb_func), const int min_limit = MIN_SIZE, const int max_limit = MAX_SIZE, const int id = ID_SPINNER_DIMENSION );
    void matrix_display(GLUI* glui_wnd, GLUI_CB (control_cb_func))
    {
        panel_matrix = glui_wnd->add_panel("");
        for(size_t i = 0; i < amount_of_columns_; i++)
        {
            for(size_t j = 0; j < amount_of_rows_; j++)
            {
                edittext_data_[i][j] = *glui_wnd->add_edittext_to_panel(panel_matrix, "", GLUI_EDITTEXT_FLOAT, &data_[j * MAX_SIZE + i], -1, control_cb_func);
                (edittext_data_[i]+j)->set_w(5);
            }
            if( i != amount_of_columns_-1)
            {
                glui_wnd->add_column_to_panel(panel_matrix, false);//glui->add_column_to_panel(matrix_panel,false);
            }

        }
    }

};

#endif //MATRIXCALCULATOR_GLUI_LINEARALGEBRA_H

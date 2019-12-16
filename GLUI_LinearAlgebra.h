//
// Created by ksenia on 12/6/19.
//

#ifndef MATRIXCALCULATOR_GLUI_LINEARALGEBRA_H
#define MATRIXCALCULATOR_GLUI_LINEARALGEBRA_H

#include "LinearAlgebra.h"
#include "GL/glut.h"
#include "glui.h"
//#include "controls_id.h"

extern GLUI* glui;

namespace GLUI_la {

    using namespace la;


    class GLUI_matrix : public matrix {
        GLUI_Spinner *spinner_rows_;// = nullptr;
        GLUI_Spinner *spinner_columns_;// = nullptr;
    public:
        GLUI_matrix(const size_t &row_, const size_t &col_) : matrix(row_, col_) {}

        GLUI_matrix() : GLUI_matrix(0, 0) {}

        GLUI_matrix(const matrix &m) : matrix(m) {};

        size_t getSpinnerRowsValue();

        size_t getSpinnerColumnsValue();

        GLUI_matrix &operator=(GLUI_matrix const &M);

        //add dimensions(as spinners) groupped in the panel to the glui_wnd
        void spinner_display(GLUI_CB (control_cb_func));

        void set_spinner(GLUI_Panel* panel_dimension, GLUI_Spinner *&spinner, const std::string name, int val,
                         GLUI_CB (control_cb_func));

        void set_listbox(GLUI* glui_wnd, GLUI_CB (control_cb_func));

        void matrix_display(GLUI_CB (control_cb_func), const std::string& matrix_name = "");

        void lower_triangular_matrix_display(GLUI_CB control_cb_func, const std::string& matrix_name = "");

        bool dim_changed();

        void update_dim(const size_t,const size_t);
    };
}

#endif //MATRIXCALCULATOR_GLUI_LINEARALGEBRA_H

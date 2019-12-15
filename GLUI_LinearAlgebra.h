//
// Created by ksenia on 12/6/19.
//

#ifndef MATRIXCALCULATOR_GLUI_LINEARALGEBRA_H
#define MATRIXCALCULATOR_GLUI_LINEARALGEBRA_H

#include "LinearAlgebra.h"
#include "GL/glut.h"
#include "glui.h"
#include "controls_id.h"

extern GLUI* glui;

namespace GLUI_la {

    using namespace la;

    class MY_GLUI_Button : public GLUI_Button {
        int ID;
        std::string sign;
    public:
        MY_GLUI_Button(const int ID_ = -1, const std::string& sign_ = "") : ID(ID_), sign(sign_) {}
        void add_my_button(GLUI* glui_wnd, GLUI_CB (control_cb_func) );
    };

    class GLUI_matrix : public matrix {
        GLUI_Spinner *spinner_rows_;
        GLUI_Spinner *spinner_columns_;
        GLUI_Panel *panel_dimension;//need locally
        GLUI_EditText **edittext_data_;//not need
        GLUI_Panel *panel_matrix;//need lolcally
        size_t spinner_amount_of_rows_;
        size_t spinner_amount_of_columns_;

    public:
        GLUI_matrix(const size_t &row_, const size_t &col_) : matrix(row_, col_) {
            spinner_rows_ = new GLUI_Spinner;
            spinner_columns_ = new GLUI_Spinner;
            panel_dimension = new GLUI_Panel;
            edittext_data_ = new GLUI_EditText *[MAX_SIZE];
            for (int i = 0; i < MAX_SIZE; i++) {
                edittext_data_[i] = new GLUI_EditText[MAX_SIZE];
            }
            panel_matrix = new GLUI_Panel;
            spinner_amount_of_rows_ = row_;
            spinner_amount_of_columns_ = col_;
        }

        GLUI_matrix() : GLUI_matrix(0, 0) {}

        GLUI_matrix(const matrix &m) : matrix(m) {};

        size_t getSpinnerRowsValue();

        size_t getSpinnerColumnsValue();

        void disableSpinners();

        GLUI_matrix &operator=(GLUI_matrix const &M);

        //add dimensions(as spinners) groupped in the panel to the glui_wnd
        void spinner_display(GLUI *glui_wnd, GLUI_CB (control_cb_func));

        void set_spinner(GLUI *glui_wnd, GLUI_Spinner *&spinner, const std::string name, int val,
                         GLUI_CB (control_cb_func));

        void matrix_display(GLUI *glui_wnd, GLUI_CB (control_cb_func), const std::string& matrix_name = "");

        void lower_triangular_matrix_display(GLUI *glui_wnd, GLUI_CB control_cb_func);

        bool dim_changed();

        void update_dim();
    };
}

#endif //MATRIXCALCULATOR_GLUI_LINEARALGEBRA_H

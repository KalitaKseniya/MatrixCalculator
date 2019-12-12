//
// Created by ksenia on 12/6/19.
//

#include "GLUI_LinearAlgebra.h"


GLUI* glui = nullptr;

using namespace GLUI_la;

void GLUI_matrix::spinner_display(GLUI* glui_wnd, GLUI_CB (control_cb_func), const int min_limit, const int max_limit , const int id)
{
    panel_dimension = glui_wnd->add_panel("");
    panel_dimension->set_alignment(GLUI_ALIGN_LEFT);
    set_spinner(glui_wnd, spinner_rows_, "rows", amount_of_rows_, control_cb_func, min_limit, max_limit, id);
    glui_wnd->add_column_to_panel(panel_dimension, false);
    set_spinner(glui_wnd, spinner_columns_, "columns", amount_of_columns_, control_cb_func, min_limit, max_limit, id);
}

void GLUI_matrix::set_spinner(GLUI* glui_wnd, GLUI_Spinner*& spinner, std::string name, size_t& live_var, GLUI_CB (control_cb_func), const int min_limit, const int max_limit , const int id )
{
    spinner= glui_wnd->add_spinner_to_panel(panel_dimension, name, GLUI_SPINNER_INT, &live_var, id, control_cb_func);
    spinner->set_speed(0.01);
    spinner->set_int_limits(min_limit, max_limit);
}

void GLUI_matrix::matrix_display(GLUI *glui_wnd, GLUI_CB control_cb_func, const std::string& matrix_name ) {
        panel_matrix = glui_wnd->add_panel("Matrix " + matrix_name);
        for (size_t i = 0; i < amount_of_columns_; i++) {
            for (size_t j = 0; j < amount_of_rows_; j++)
            {
                glui_wnd->add_edittext_to_panel(panel_matrix, "", GLUI_EDITTEXT_FLOAT,
                                                &data_[j * MAX_SIZE + i], -1, control_cb_func)->set_w(5);
            }
            if (i != amount_of_columns_ - 1) {
                glui_wnd->add_column_to_panel(panel_matrix, false);
            }
        }
}

void GLUI_matrix::lower_triangular_matrix_display(GLUI *glui_wnd, GLUI_CB control_cb_func) {
    panel_matrix = glui_wnd->add_panel("");
    GLUI_EditText* tmp;
    for (size_t i = 0; i < amount_of_columns_; i++) {
        for (size_t j = 0; j < amount_of_rows_; j++)
        {
            tmp = glui_wnd->add_edittext_to_panel(panel_matrix, "", GLUI_EDITTEXT_FLOAT,
                                            &data_[j * MAX_SIZE + i], -1, control_cb_func);
            tmp->set_w(12);
            if(i > j)
                tmp->disable();
        }
        if (i != amount_of_columns_ - 1) {
            glui_wnd->add_column_to_panel(panel_matrix, false);
        }
    }
}

GLUI_matrix &GLUI_matrix::operator=(GLUI_matrix const &M) {
    if (this != &M) {
        amount_of_rows_ = M.amount_of_rows_;
        amount_of_columns_ = M.amount_of_columns_;
        for (size_t i = 0; i < amount_of_rows_; i++) {
            for (size_t j = 0; j < amount_of_columns_; j++) {
                data_[i * MAX_SIZE + j] = M(i, j);
            }
        }
    }
    return *this;
}

int GLUI_matrix::getSpinnerRowsValue() {
    return spinner_rows_->last_int_val;
}

int GLUI_matrix::getSpinnerColumnsValue() {
    return spinner_columns_->get_int_val();
}

void GLUI_matrix::disableSpinners() {
    spinner_rows_->disable();
    spinner_columns_->disable();
}

void MY_GLUI_Button::add_my_button(GLUI *glui_wnd, GLUI_CB control_cb_func) {
    glui_wnd->add_button(sign, ID, control_cb_func)->set_w(MY_BUTTON_WIDTH);
}

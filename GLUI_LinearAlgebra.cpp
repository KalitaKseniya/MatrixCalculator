//
// Created by ksenia on 12/6/19.
//

#include "GLUI_LinearAlgebra.h"


GLUI* glui = nullptr;

using namespace GLUI_la;

void GLUI_matrix::spinner_display(GLUI* glui_wnd, GLUI_CB (control_cb_func))
{
    panel_dimension = glui_wnd->add_panel("");
    panel_dimension->set_alignment(GLUI_ALIGN_LEFT);
    set_spinner(glui_wnd, spinner_rows_, "rows", amount_of_rows_, control_cb_func);
    glui_wnd->add_column_to_panel(panel_dimension, false);
    set_spinner(glui_wnd, spinner_columns_, "columns", amount_of_columns_, control_cb_func);
}

void GLUI_matrix::set_spinner(GLUI* glui_wnd, GLUI_Spinner*& spinner,const std::string name, int val, GLUI_CB (control_cb_func) )
{
    spinner= glui_wnd->add_spinner_to_panel(panel_dimension, name, GLUI_SPINNER_INT, NULL, ID_SPINNER_DIMENSION, control_cb_func);
    spinner->set_speed(0.01f);
    spinner->set_int_val(val);
    spinner->set_int_limits(MIN_SIZE, MAX_SIZE);
}

void GLUI_matrix::matrix_display(GLUI *glui_wnd, GLUI_CB control_cb_func, const std::string& matrix_name ) {
    panel_matrix = glui_wnd->add_panel("Matrix " + matrix_name);
    for (size_t i = 0; i < amount_of_columns_; i++) {
        for (size_t j = 0; j < amount_of_rows_; j++)
        {
            edittext_data_[j][i] = *(glui_wnd->add_edittext_to_panel(panel_matrix, "", GLUI_EDITTEXT_FLOAT,
                                            &(*this)(j, i), -1, control_cb_func));
            edittext_data_[j][i].set_w(5);
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
                                                  &data_[j + i], -1, control_cb_func);
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
                data_[i  + j] = M(i, j);
            }
        }
    }
    return *this;
}

size_t GLUI_matrix::getSpinnerRowsValue() {
    int a = spinner_rows_->get_int_val();
    return static_cast<size_t>(a);
}

size_t GLUI_matrix::getSpinnerColumnsValue() {
    return static_cast<size_t >(spinner_columns_->get_int_val());
}

void GLUI_matrix::disableSpinners() {
    spinner_rows_->disable();
    spinner_columns_->disable();
}

bool GLUI_matrix::dim_changed() {
    return spinner_columns_->int_val != amount_of_columns_ || spinner_rows_->int_val != amount_of_rows_;
}

void GLUI_matrix::update_dim() {
    GLUI_matrix new_matrix(spinner_rows_->int_val, spinner_columns_->int_val);

    for(size_t i = 0; i < amount_of_rows_; i++)
    {
        for(size_t j = 0; j < amount_of_columns_; j++)
        {
            new_matrix(i, j) = (*this)(i, j);
            std :: cout << new_matrix << std::endl;
        }
    }
    data_ = new_matrix.data_;
    amount_of_rows_ = new_matrix.amount_of_rows_;
    amount_of_columns_ = new_matrix.amount_of_columns_;
}

void MY_GLUI_Button::add_my_button(GLUI *glui_wnd, GLUI_CB control_cb_func) {
    glui_wnd->add_button(sign, ID, control_cb_func)->set_w(MY_BUTTON_WIDTH);
}

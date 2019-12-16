//
// Created by ksenia on 12/6/19.
//

#include "GLUI_LinearAlgebra.h"


GLUI* glui = nullptr;

using namespace GLUI_la;

void GLUI_matrix::spinner_display(GLUI_CB (control_cb_func))
{
    GLUI_Panel* panel_dimension = new GLUI_Panel(glui, "");
    panel_dimension->set_alignment(GLUI_ALIGN_LEFT);
    set_spinner(panel_dimension, spinner_rows_, "rows", static_cast<int>(amount_of_rows_), control_cb_func);
    glui->add_column_to_panel(panel_dimension, false);
    set_spinner(panel_dimension,spinner_columns_, "columns", static_cast<int>(amount_of_columns_), control_cb_func);
    glui->add_column_to_panel(panel_dimension, false);
    //set_listbox(control_cb_func);
}

//void GLUI_matrix::set_listbox(GLUI_CB (control_cb_func))
//{
//    listbox_pow = glui->add_listbox_to_panel(panel_dimension, "", NULL, -1, control_cb_func);
//    listbox_pow->add_item(ID_LISTBOX_1, "1");
//    listbox_pow->add_item(ID_LISTBOX_minus_1, "-1");
//    listbox_pow->add_item(ID_LISTBOX_T, "T");
//    listbox_pow->set_alignment(GLUI_ALIGN_RIGHT);
//}


void GLUI_matrix::set_spinner(GLUI_Panel* panel_dimension, GLUI_Spinner*& spinner,const std::string name, int val, GLUI_CB (control_cb_func) )
{
    spinner = new GLUI_Spinner(panel_dimension, name, GLUI_SPINNER_INT, NULL, ID_SPINNER_DIMENSION, control_cb_func);
    spinner->set_speed(0.01f);
    spinner->set_int_val(val);
    spinner->set_int_limits(MIN_SIZE, MAX_SIZE);
}

void GLUI_matrix::matrix_display(GLUI_CB control_cb_func, const std::string& matrix_name ) {
    GLUI_Panel* panel_matrix = new GLUI_Panel(glui, "Matrix " + matrix_name);
    GLUI_EditText* tmp = nullptr;
    for (size_t i = 0; i < amount_of_columns_; i++) {
        for (size_t j = 0; j < amount_of_rows_; j++)
        {
            tmp = new GLUI_EditText(panel_matrix, "", GLUI_EDITTEXT_FLOAT,
                                            &(*this)(j, i), -1, control_cb_func);
            tmp->set_w(5);
        }
        if (i != amount_of_columns_ - 1) {
            new GLUI_Column(panel_matrix, false);
        }
    }
}

void GLUI_matrix::lower_triangular_matrix_display(GLUI_CB control_cb_func, const std::string& matrix_name )
{
    GLUI_Panel* panel_matrix = new GLUI_Panel(glui, "Matrix " + matrix_name);
    GLUI_EditText* tmp = nullptr;
    for (size_t i = 0; i < amount_of_columns_; i++) {
        for (size_t j = 0; j < amount_of_rows_; j++)
        {
            tmp = new GLUI_EditText(panel_matrix, "", GLUI_EDITTEXT_FLOAT,
                                    &(*this)(j, i), -1, control_cb_func);
            tmp->set_w(5);
            if(i > j)
                tmp->disable();
        }
        if (i != amount_of_columns_ - 1) {
            new GLUI_Column(panel_matrix, false);
        }
    }
}

GLUI_matrix &GLUI_matrix::operator=(GLUI_matrix const &M) {
    if (this != &M) {
        amount_of_rows_ = M.amount_of_rows_;
        amount_of_columns_ = M.amount_of_columns_;
        data_ = M.data_;
    }
    return *this;
}

size_t GLUI_matrix::getSpinnerRowsValue() {
    if(spinner_rows_)
        return static_cast<size_t>(spinner_rows_->get_int_val());
    return amount_of_rows_;
}

size_t GLUI_matrix::getSpinnerColumnsValue() {
    if(spinner_columns_)
        return static_cast<size_t >(spinner_columns_->get_int_val());
    return amount_of_columns_;
}

//void GLUI_matrix::disableSpinners() {
//    spinner_rows_->disable();
//    spinner_columns_->disable();
//}

bool GLUI_matrix::dim_changed() {
    return data_.size() != amount_of_rows_ * amount_of_columns_ || getSpinnerColumnsValue() != amount_of_columns_  || getSpinnerRowsValue() != amount_of_rows_ ;
}

size_t min(const size_t a, const size_t b)
{
    return (a < b) ? a : b;
}

void GLUI_matrix::update_dim(const size_t new_rows, const size_t new_cols) {
    std::vector<float> new_data(new_rows * new_cols);
    for (size_t i = 0; i < min(amount_of_rows_, new_rows); i++)
    {
        for(size_t j = 0; j < min(amount_of_columns_, new_cols);j++)
        {
            new_data[i * new_cols + j] = (*this)(i,j);
        }
    }
    data_.clear();
    data_ = new_data;
    amount_of_rows_ = new_rows;
    amount_of_columns_ = new_cols;

}

void MY_GLUI_Button::add_my_button(GLUI_CB control_cb_func) {
    GLUI_Button* tmp = new GLUI_Button(glui, sign, ID, control_cb_func);
    tmp->set_w(MY_BUTTON_WIDTH);
}

std::string MY_GLUI_Button::getSign() {
    return sign;
}

int MY_GLUI_Button::getID() {
    return ID;
}

//
// Created by ksenia on 12/6/19.
//

#include "GLUI_LinearAlgebra.h"

void GLUI_matrix::spinner_display(GLUI* glui_wnd, GLUI_CB (control_cb_func), const int min_limit, const int max_limit , const int id)
{
    panel_dimension = glui_wnd->add_panel("");
    set_spinner(glui_wnd, spinner_rows_, "rows", amount_of_rows_, control_cb_func, min_limit, max_limit, id);
    glui_wnd->add_column_to_panel(panel_dimension, false);
    set_spinner(glui_wnd, spinner_columns_, "columns", amount_of_columns_, control_cb_func, min_limit, max_limit, id);
}

void GLUI_matrix::set_spinner(GLUI* glui_wnd, GLUI_Spinner* spinner, std::string name, size_t& live_var, GLUI_CB (control_cb_func), const int min_limit, const int max_limit , const int id )
{
    spinner= glui_wnd->add_spinner_to_panel(panel_dimension, name, GLUI_SPINNER_INT, &live_var, id, control_cb_func);
    spinner->set_speed(0.01);
    spinner->set_int_limits(min_limit, max_limit);
}

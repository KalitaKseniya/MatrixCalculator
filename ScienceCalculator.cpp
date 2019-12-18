//
// Created by ksenia on 12/10/19.
//

#include "ScienceCalculator.h"

GLUI_matrix R = GLUI_matrix(SIZE_);
GLUI_matrix H = GLUI_matrix(SIZE_);
GLUI_matrix M = GLUI_matrix(SIZE_);
int is_pressed_checkbox_R_set = false;
int is_pressed_checkbox_H_set = false;
int is_pressed_checkbox_R_H = false;

std::string status_bar_advanced = "";



void update_advanced_glui() {

    glui->close();
    advanced_calculator_create();
}

GLUI* glui_help = nullptr;

void control_cb_help(int control)
{
    switch (control)
    {
        case ID_BUTTON_TO_MENU:
            glui_help->close();
            break;
        default:
            break;
    }
}

void set_dims_from_spinners()
{
    if (R.dim_changed()) {
        R.update_dim(R.getSpinnerRowsValue(), R.getSpinnerColumnsValue());
    }
    if (H.dim_changed()) {
        H.update_dim(H.getSpinnerRowsValue(), H.getSpinnerColumnsValue());
    }
}

void help_subwnd_create()
{
    glui_help = GLUI_Master.create_glui_subwindow(glui->get_glut_window_id(),GLUI_SUBWINDOW_BOTTOM);
    new GLUI_StaticText(glui_help, "For help read my article about the invariance of corner");
    new GLUI_StaticText(glui_help, "minors' positivity on pfmt.gsu.by");
    new GLUI_Button(glui_help, "close", ID_BUTTON_TO_MENU, control_cb_help);
}


void control_advanced_cb( int control ) {

    printf("callback: %d\n", control);
    size_t M_col = M.get_w(), M_row = M.get_h();
    bool flag = true;
    switch(control) {
        case ID_SPINNER_DIMENSION:
            if(R.dim_changed() || H.dim_changed())
            {
                set_dims_from_spinners();
                update_advanced_glui();
            }
            return;
        case ID_BUTTON_IS_IN_R:
            is_pressed_checkbox_R_set = (R.is_in_R()) ? 1 : 0;
            break;
            case ID_BUTTON_IS_IN_H:
                is_pressed_checkbox_H_set = (H.is_in_H()) ? 1 : 0;
                break;
        case ID_BUTTON_BUILD_M:
            if((flag = can_similarity_transformation(R, H)))
            {
                M = similarity_transformation(R, H);
                if(M_col != M.get_w() || M_row != M.get_h())
                {
                    update_advanced_glui();
                }
            }
            break;
        case ID_BUTTON_IS_RHO_LAW_ABIDING:
            is_pressed_checkbox_R_H = (is_rho_law_abiding(R, H, 0)) ? 1 : 0;
            break;
        case ID_BUTTON_TO_MENU:
            glui->close();
            menu_create();
            return;
        case ID_BUTTON_QUEST:
            help_subwnd_create();
            break;
        default:
            return;
    }
    status_bar_advanced = (flag) ? "Success" : "Failure";
    glui->sync_live();
    std::cout << R << std::endl << H << std::endl << M << std::endl ;
}


void advanced_calculator_create()
{
    glui = GLUI_Master.create_glui( "Advanced matrix calculator", 0, wnd_x, wnd_y);
    new GLUI_Button(glui, "to Menu", ID_BUTTON_TO_MENU, control_advanced_cb);
    R.spinner_display( control_advanced_cb);
    R.lower_triangular_matrix_display(control_advanced_cb, "R");
    GLUI_Panel* panel_R_set = new GLUI_Panel(glui, "");
    new GLUI_Button(panel_R_set, "Is in R_set?", ID_BUTTON_IS_IN_R, control_advanced_cb);
    new GLUI_Column(panel_R_set, false);
    GLUI_Checkbox* checkbox_R = new GLUI_Checkbox(panel_R_set, "yes", &is_pressed_checkbox_R_set,ID_CHECKBOX_IS_IN_R_SET, control_advanced_cb);
    checkbox_R->disable();
    H.spinner_display( control_advanced_cb);
    H.matrix_display(control_advanced_cb, "H");
    GLUI_Panel* panel_H_set = new GLUI_Panel(glui, "");
    new GLUI_Button(panel_H_set, "Is in H_set?",  ID_BUTTON_IS_IN_H, control_advanced_cb);
    new GLUI_Column(panel_H_set, false);
    GLUI_Checkbox* checkbox_H = new GLUI_Checkbox(panel_H_set, "yes", &is_pressed_checkbox_H_set, ID_CHECKBOX_IS_IN_H_SET, control_advanced_cb);
    checkbox_H->disable();
    new GLUI_Button(glui,  "Bulid M=RHR^-1", ID_BUTTON_BUILD_M, control_advanced_cb);
    M.matrix_display(control_advanced_cb, "M");
    GLUI_Panel* panel_R_H = new GLUI_Panel(glui, "");
    new GLUI_Button(panel_R_H, "Is (R, H) law-abiding?", ID_BUTTON_IS_RHO_LAW_ABIDING, control_advanced_cb);
    new GLUI_Column(panel_R_H, false);
    GLUI_Checkbox* checkbox_R_H = new GLUI_Checkbox(panel_R_H, "yes", &is_pressed_checkbox_R_H, ID_CHECKBOX_IS_R_H , control_advanced_cb);
    checkbox_R_H->disable();
    GLUI_EditText* editTextStatusBar = new GLUI_EditText(glui, "Status bar:", status_bar_advanced, -1, control_advanced_cb);
    editTextStatusBar->set_alignment(GLUI_ALIGN_LEFT);
    new GLUI_Button(glui, "HELP", ID_BUTTON_QUEST, control_advanced_cb);
}



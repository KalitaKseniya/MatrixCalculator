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

bool need_to_update_advanced_glui(const size_t M_row, const size_t M_col)
{
    return R.dim_changed() || H.dim_changed() || M_row != M.get_h() || M_col != M.get_w();
}


void update_advanced_glui() {
    if (R.dim_changed()) {
        R.update_dim(R.getSpinnerRowsValue(), R.getSpinnerColumnsValue());
    }
    if (H.dim_changed()) {
        H.update_dim(H.getSpinnerRowsValue(), H.getSpinnerColumnsValue());
    }
    glui->close();
    advanced_calculator_create();
}


void control_advanced_cb( int control ) {

    printf("callback: %d\n", control);
    size_t M_col = M.get_w(), M_row = M.get_h();
    bool flag = 1;
    switch(control) {
        case ID_SPINNER_DIMENSION:
            break;
        case ID_BUTTON_IS_IN_R:
            is_pressed_checkbox_R_set = (flag = R.is_in_R()) ? 1 : 0;
            break;
            case ID_BUTTON_IS_IN_H:
                is_pressed_checkbox_H_set = (flag = H.is_in_H()) ? 1 : 0;
                break;
        case ID_BUTTON_BUILD_M:
            if((flag = can_similarity_transformation(R, H))) {
                M = similarity_transformation(R, H);
            }
            break;
        case ID_BUTTON_IS_RHO_LAW_ABIDING:
            is_pressed_checkbox_R_H = (flag = is_rho_law_abiding(R, H, 0)) ? 1 : 0;
            break;
        case ID_BUTTON_TO_MENU:
            glui->close();
            menu_create();
            return;
        default:
            return;
    }
    glui->sync_live();
    std::cout << R << std::endl << H << std::endl << M << std::endl ;
    if(!need_to_update_advanced_glui(M_row, M_col))
    {
        return;
    }
    update_advanced_glui();
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
    glui->add_statictext("Status bar: "+status_bar_advanced)->set_alignment(GLUI_ALIGN_LEFT);

}



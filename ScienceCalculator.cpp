//
// Created by ksenia on 12/10/19.
//

#include "ScienceCalculator.h"

GLUI_matrix R = GLUI_matrix(SIZE_);
GLUI_matrix H = GLUI_matrix(SIZE_);
GLUI_matrix M = GLUI_matrix(SIZE_);
const float rho = 0;
const float r = 0;
int is_pressed_checkbox_R_set = false;
int is_pressed_checkbox_H_set = false;
int is_pressed_checkbox_R_H = false;

std::string status_bar_science = "";

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
    science_calculator_create();
}


void control_science_cb( int control ) {

    printf("callback: %d\n", control);
    size_t M_col = M.get_w(), M_row = M.get_h();
    switch(control) {

        case ID_BUTTON_IS_IN_R:
            if(R.is_in_R())
            {
                is_pressed_checkbox_R_set = 1;
            }
            break;
            case ID_BUTTON_IS_IN_H:
            if(!H.is_in_H())
            {
                status_bar_science = "Failed";
                is_pressed_checkbox_H_set = 0;
                return;
            }
            is_pressed_checkbox_H_set = 1;
            break;
        case ID_BUTTON_BUILD_M:
            if(!can_similarity_transformation(R, H))
            {
                status_bar_science = "Failed";
                return;
            }
            M = similarity_transformation(R, H);
            M.spinner_display(control_science_cb);
            M.matrix_display(control_science_cb);
            break;
        case ID_BUTTON_IS_RHO_LAW_ABIDING:
            if(!rho_law_abiding(R, H))
            {
                status_bar_science = "Failed";
                is_pressed_checkbox_R_H = 0;
                return;
            }
            is_pressed_checkbox_R_H = 1;
            break;
        default:
            return;

    }
    std::cout <<"R:"<< R << std::endl<<"H:" << H << std::endl << std::endl;
    glui->sync_live();
    std::cout << R << std::endl << H << std::endl << M << std::endl ;
    if(!need_to_update_advanced_glui(M_row, M_col))
    {
        return;
    }
    update_advanced_glui();
}


void science_calculator_create()
{
    glui = GLUI_Master.create_glui( "Advanced matrix calculator", 0, wnd_x, wnd_y);
//    GLUI_EditText* edittext_r = new GLUI_EditText(glui, "r=", &r, GLUI_EDITTEXT_FLOAT, control_science_cb);
//    edittext_r->set_w(3);
//    GLUI_EditText* edittext_rho = new GLUI_EditText(glui, "rho=", &rho, GLUI_EDITTEXT_FLOAT, control_science_cb);
//    edittext_rho->set_w(3);
    R.spinner_display( control_science_cb);
    R.lower_triangular_matrix_display(control_science_cb, "R");
    GLUI_Panel* panel_R_set = new GLUI_Panel(glui, "");
    new GLUI_Button(panel_R_set, "Is in R_set?", ID_BUTTON_IS_IN_R, control_science_cb);
    new GLUI_Column(panel_R_set, false);
    GLUI_Checkbox* checkbox_R = new GLUI_Checkbox(panel_R_set, "yes", &is_pressed_checkbox_R_set,ID_CHECKBOX_IS_IN_R_SET, control_science_cb);
    checkbox_R->disable();
    H.spinner_display( control_science_cb);
    H.matrix_display(control_science_cb, "H");
    GLUI_Panel* panel_H_set = new GLUI_Panel(glui, "");
    new GLUI_Button(panel_H_set, "Is in H_set?",  ID_BUTTON_IS_IN_H, control_science_cb);
    new GLUI_Column(panel_H_set, false);
    GLUI_Checkbox* checkbox_H = new GLUI_Checkbox(panel_H_set, "yes", &is_pressed_checkbox_H_set, ID_CHECKBOX_IS_IN_H_SET, control_science_cb);
    checkbox_H->disable();
    new GLUI_Button(glui,  "Bulid M=RHR^-1", ID_BUTTON_BUILD_M, control_science_cb);
    M.matrix_display(control_science_cb, "M");
    GLUI_Panel* panel_R_H = new GLUI_Panel(glui, "");
    new GLUI_Button(panel_R_H, "Is (R, H) rho-law-abiding?", ID_BUTTON_IS_RHO_LAW_ABIDING, control_science_cb);
    new GLUI_Column(panel_R_H, false);
    GLUI_Checkbox* checkbox_R_H = new GLUI_Checkbox(panel_R_H, "yes", &is_pressed_checkbox_R_H, ID_CHECKBOX_IS_R_H , control_science_cb);
    checkbox_R_H->disable();
    glui->add_statictext("Status bar: "+status_bar_science)->set_alignment(GLUI_ALIGN_LEFT);

}



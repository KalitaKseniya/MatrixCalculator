//
// Created by ksenia on 12/10/19.
//

#include "ScienceCalculator.h"

GLUI_matrix R = GLUI_matrix(SIZE_);
GLUI_matrix H = GLUI_matrix(SIZE_);
float rho = 1;
int is_pressed_checkbox = false;

std::string status_bar_science = "I'll show you the result of your actions";

void control_science_cb( int control ) {

    printf("callback: %d\n", control);

    switch(control) {
        case -1:
            return;
        case ID_SPINNER_DIMENSION:
            break;
        case ID_BUTTON_IS_IN_R:
            //if(is_in_R()
            break;
        case ID_BUTTON_IS_IN_H:
//            if(is_in_H(H))
//            {
//                Listbox yes
//            }
//            else
//            {
//                listbox no
//            }
//            break;
//        case ID_BUTTON_BUILD_M:
//            GLUI_matrix M;
//            if(!can_similarity_transformation(R, H))
//            {
//                return;
//            }
//            M = similarity_transformation(R, H);
//            M.spinner_display(glui, control_science_cb);
//            M.disableSpinners();
//            M.matrix_display(glui, control_science_cb);
//            break;
//        case ID_BUTTON_IS_RHO_LAW_ABIDING:
//            if(rho_law_abiedind)
//            {
//                Listbox yes
//            }
//            else
//            {
//                listbox no
//            }
            break;

    }
    std::cout <<"R:"<< R << std::endl<<"H:" << H << std::endl << std::endl;
    if(R.get_w() != R.getSpinnerRowsValue() || H.get_h() != H.getSpinnerColumnsValue() )
    {
        glui->close();
        science_calculator_create();
    }
    else
        {
        glui->sync_live();

    }
}

void science_calculator_create()
{
    glui = GLUI_Master.create_glui( "Science matrix calculator", 0, 1, 1);
    R.spinner_display(glui, control_science_cb);
  //  R.spinners_are_equal();
    R.lower_triangular_matrix_display(glui, control_science_cb);
    //R.
    GLUI_Panel* panel_R_set = new GLUI_Panel;
    panel_R_set = glui->add_panel("");
    glui->add_button_to_panel(panel_R_set, "Is in R_set?", ID_BUTTON_IS_IN_R, control_science_cb);
    glui->add_column_to_panel(panel_R_set, false);
    GLUI_Listbox* listbox = new GLUI_Listbox;
    listbox = glui->add_listbox_to_panel(panel_R_set, "");
    listbox->add_item(-1, "...");
    listbox->add_item(ID_YES, "Yes");
    listbox->add_item(ID_NO, "No");
    H.spinner_display(glui, control_science_cb);
    H.matrix_display(glui, control_science_cb);
    glui->add_button("Is in H_set?", ID_BUTTON_IS_IN_H, control_science_cb);
    GLUI_Panel* panel = new GLUI_Panel;
    panel = glui->add_panel("");
    panel->set_alignment(GLUI_ALIGN_CENTER);
    glui->add_button_to_panel(panel, "Is (R, H) rho-law-abiding?");

    glui->add_checkbox_to_panel(panel, "Record calculations in file", &is_pressed_checkbox, ID_CHECKBOX_FILE_OUTPUT, control_science_cb) ;

    glui->add_column_to_panel(panel, false);

    GLUI_EditText* edittext = new GLUI_EditText;
    edittext = glui->add_edittext_to_panel(panel, "rho=", GLUI_EDITTEXT_FLOAT, &rho);
    edittext->set_w(3);
    edittext->set_alignment(GLUI_ALIGN_LEFT);
    glui->add_statictext("Status bar: "+status_bar_science)->set_alignment(GLUI_ALIGN_LEFT);

}



//
// Created by ksenia on 12/6/19.
//

#include "BasicCalculator.h"
#include "main_menu.h"


GLUI_matrix A = GLUI_matrix(SIZE_, SIZE_);
GLUI_matrix B = GLUI_matrix(SIZE_, SIZE_);
GLUI_matrix C = GLUI_matrix(SIZE_, SIZE_);

std::string status_bar = "";


bool need_to_update_glui(const size_t C_row = C.get_h(), const size_t C_col = C.get_w())
{
    return A.dim_changed() || B.dim_changed() || C_row != C.get_h() || C_col != C.get_w();
}

void set_dimensions_from_spinners()
{
    if(A.dim_changed())
    {
        A.update_dim(A.getSpinnerRowsValue(), A.getSpinnerColumnsValue());
    }
    if(B.dim_changed())
    {
        B.update_dim(B.getSpinnerRowsValue(), B.getSpinnerColumnsValue());
    }
}

void update_glui()
{
    glui->close();
    basic_calculator_create();
}
void control_cb( int control ) {
    printf("callback: %d\n", control);
    size_t C_row = C.get_h(), C_col = C.get_w();
    bool flag = true;
    switch(control) {
        case ID_SPINNER_DIMENSION:
            if(need_to_update_glui())
            {
                set_dimensions_from_spinners();
                update_glui();
                glui->sync_live();
            }
            return;
        case ID_BUTTON_SWAP:
            std::swap(A, B);
            break;
        case ID_BUTTON_ADD:
            if ((flag = can_add(A, B)))
            {
                C = A + B;
            }
            break;
        case ID_BUTTON_SUB:
            if ((flag = can_sub(A, B)))
            {
                C = A - B;
            }
            break;
        case ID_BUTTON_MULT:
            if ((flag = can_mult(A, B)))
            {
                C = A * B;
            }
            break;
        case ID_BUTTON_DIV:
            if ((flag = can_div(A, B)))
            {
                C = A;
                C *= inverse(B);
            }
            break;
        case ID_BUTTON_InsCInA:
            A = C;
            break;
        case ID_BUTTON_InsCInB:
            B = C;
            break;
        case ID_BUTTON_TO_MENU:
            glui->close();
            menu_create();
            return;
        default:
            return;
    }
    status_bar = (flag) ? "Success" : "Failure";
    glui->sync_live();
    std::cout << A << std::endl << B << std::endl << C << std::endl ;
    if(flag && need_to_update_glui(C_row, C_col))
    {
        update_glui();
    }

}

void basic_calculator_create()
{

    glui = GLUI_Master.create_glui( "Basic matrix calculator", 0, wnd_x, wnd_y);
    new GLUI_Button(glui, "to Menu", ID_BUTTON_TO_MENU, control_cb);
    A.spinner_display(control_cb);
    A.matrix_display(control_cb, "A");
    new GLUI_Button(glui, "swap A and B",  ID_BUTTON_SWAP, control_cb);
    new GLUI_Button(glui, "+",  ID_BUTTON_ADD, control_cb);
    new GLUI_Button(glui, "-",  ID_BUTTON_SUB, control_cb);
    new GLUI_Button(glui, "*",  ID_BUTTON_MULT, control_cb);
    new GLUI_Button(glui, "/",  ID_BUTTON_DIV, control_cb);
    B.spinner_display(control_cb);
    B.matrix_display(control_cb,"B");
    glui->add_button("=")->disable();
    GLUI_Panel* panel_C = new GLUI_Panel(glui, "");
    new GLUI_Button(panel_C, "Insert C in A", ID_BUTTON_InsCInA, control_cb);//set_w(MY_BUTTON_WIDTH);
    new GLUI_Column(panel_C);
    new GLUI_Button(panel_C, "Insert C in B", ID_BUTTON_InsCInB, control_cb);//->set_w(MY_BUTTON_WIDTH);
    C.matrix_display(control_cb, "C");
    GLUI_EditText* editTextStatusBar = new GLUI_EditText(glui, "Status bar:", status_bar, -1, control_cb);
    editTextStatusBar->set_alignment(GLUI_ALIGN_LEFT);
}


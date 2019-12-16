//
// Created by ksenia on 12/6/19.
//

#include "BasicCalculator.h"
#define BUTTON_NUM 7
#define take_name(x) #x
GLUI_matrix A = GLUI_matrix(SIZE_, SIZE_);
GLUI_matrix B = GLUI_matrix(SIZE_, SIZE_);
GLUI_matrix C = GLUI_matrix(SIZE_, SIZE_);

std::string status_bar = "";

MY_GLUI_Button myGluiButtonSwap = MY_GLUI_Button(ID_BUTTON_SWAP, "swap A and B"),myGluiButtonAdd = MY_GLUI_Button(ID_BUTTON_ADD, "+"),
        myGluiButtonSub = MY_GLUI_Button(ID_BUTTON_SUB, "-"), myGluiButtonMult = MY_GLUI_Button(ID_BUTTON_MULT, "*"),
        myGluiButtonDiv = MY_GLUI_Button(ID_BUTTON_DIV, "/"),
        myGluiButtonInsCInA = MY_GLUI_Button(ID_BUTTON_InsCInA, "Insert C in A"), myGluiButtonInsCInB = MY_GLUI_Button(ID_BUTTON_InsCInB, "Insert C in B");

MY_GLUI_Button myButtons[BUTTON_NUM] = {myGluiButtonSwap, myGluiButtonAdd,
                                        myGluiButtonSub, myGluiButtonMult, myGluiButtonDiv, myGluiButtonInsCInA, myGluiButtonInsCInB};

bool need_to_update_glui(const size_t C_row, const size_t C_col)
{
    return A.dim_changed() || B.dim_changed() || C_row != C.get_h() || C_col != C.get_w();
}


void update_glui()
{
    if(A.dim_changed())
    {
        A.update_dim(A.getSpinnerRowsValue(), A.getSpinnerColumnsValue());
    }
    if(B.dim_changed())
    {
        B.update_dim(B.getSpinnerRowsValue(), B.getSpinnerColumnsValue());
    }

    glui->close();
    basic_calculator_create();
}
void control_cb( int control ) {

    printf("callback: %d\n", control);
    size_t C_row = C.get_h(), C_col = C.get_h();
    switch(control) {
        case ID_BUTTON_SWAP:
            std::swap(A, B);
            status_bar = "A and B were successfully swapped";
            break;
        case ID_BUTTON_ADD:
            if (!can_add(A, B))
            {
                status_bar = "Can't add (not equal amount of rows or columns)";
            }
            else
            {
                C = A + B;
                status_bar = "Successfully add";
            }
            break;
        case ID_BUTTON_SUB:
            if (!can_sub(A, B))
            {
                status_bar = "Can't sub (not equal amount of rows or columns)";
            }
            else
            {
                C = A - B;
                status_bar = "Successfully ";
            }

            break;
        case ID_BUTTON_MULT:
            if (!can_mult(A, B))
            {
                status_bar = "Can't multiply (A(columns) != B(rows))";
            }
            else
            {
                C = A * B;
                status_bar = "Successfully multiplied";
            }
            break;
        case ID_BUTTON_DIV:
            if (!can_div(A, B))
            {
                status_bar = "Can't divide (not equal amount of rows or columns)";
            }
            else
            {
                C = A;
                C *= inverse(B);
                status_bar = "Successfully divided";
            }
            break;
        case ID_BUTTON_InsCInA:
            A = C;
            status_bar = "Successfully insert C in A";
            break;
        case ID_BUTTON_InsCInB:
            B = C;
            status_bar = "Successfully insert C in B";
            break;
        case ID_BUTTON_TO_MENU:
//            menu();
            return;
        default:
            break;
    }
    glui->sync_live();
    std::cout << A << std::endl << B << std::endl << C << std::endl ;
    if(!need_to_update_glui(C_row, C_col))
    {
        return;
    }
    update_glui();
}

void basic_calculator_create()
{

    glui = GLUI_Master.create_glui( "Basic matrix calculator", 0, wnd_x, wnd_y);
    new GLUI_Button(glui, "to Menu", ID_BUTTON_TO_MENU, control_cb);
    A.spinner_display(control_cb);
    A.matrix_display(control_cb, take_name(A));
    new GLUI_Button(glui, "swap A and B",  ID_BUTTON_SWAP, control_cb);
    new GLUI_Button(glui, "+",  ID_BUTTON_ADD, control_cb);
    new GLUI_Button(glui, "-",  ID_BUTTON_SUB, control_cb);
    new GLUI_Button(glui, "*",  ID_BUTTON_MULT, control_cb);
    new GLUI_Button(glui, "/",  ID_BUTTON_DIV, control_cb);
    B.spinner_display(control_cb);
    B.matrix_display(control_cb, take_name(B));
    glui->add_button("=")->disable();
    GLUI_Panel* panel_C = new GLUI_Panel(glui, "");
    new GLUI_Button(panel_C, myGluiButtonInsCInA.getSign(), myGluiButtonInsCInA.getID(), control_cb);//set_w(MY_BUTTON_WIDTH);
    new GLUI_Column(panel_C);
    new GLUI_Button(panel_C, myGluiButtonInsCInB.getSign(), myGluiButtonInsCInA.getID(), control_cb);//->set_w(MY_BUTTON_WIDTH);
    C.matrix_display(control_cb, take_name(C));
    GLUI_StaticText* st = new GLUI_StaticText(glui, "Status bar: "+status_bar);
    st->set_alignment(GLUI_ALIGN_LEFT);
}




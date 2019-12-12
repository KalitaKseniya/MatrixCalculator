//
// Created by ksenia on 12/6/19.
//

#include "BasicCalculator.h"
#define BUTTON_NUM 7
#define take_name(x) #x
GLUI_matrix A = GLUI_matrix(SIZE_, SIZE_);
GLUI_matrix B = GLUI_matrix(SIZE_, SIZE_);
GLUI_matrix C = GLUI_matrix(SIZE_, SIZE_);

std::string status_bar = "I'll show you the result of your actions";

MY_GLUI_Button myGluiButtonSwap = MY_GLUI_Button(ID_BUTTON_SWAP, "swap A and B"),myGluiButtonAdd = MY_GLUI_Button(ID_BUTTON_ADD, "+"),
        myGluiButtonSub = MY_GLUI_Button(ID_BUTTON_SUB, "-"), myGluiButtonMult = MY_GLUI_Button(ID_BUTTON_MULT, "*"),
        myGluiButtonDiv = MY_GLUI_Button(ID_BUTTON_DIV, "/"),
        myGluiButtonInsCInA = MY_GLUI_Button(ID_BUTTON_InsCInA, "Insert C in A"), myGluiButtonInsCInB = MY_GLUI_Button(ID_BUTTON_InsCInB, "Insert C in B");

MY_GLUI_Button myButtons[BUTTON_NUM] = {myGluiButtonSwap, myGluiButtonAdd,
                               myGluiButtonSub, myGluiButtonMult, myGluiButtonDiv, myGluiButtonInsCInA, myGluiButtonInsCInB};
void control_cb( int control ) {

    printf("callback: %d\n", control);

    switch(control) {
        case -1:
            return;
        case ID_SPINNER_DIMENSION:
            break;
        case ID_BUTTON_SWAP:
            std::swap(A, B);
            status_bar = "A and B were successfully swapped";
            break;
        case ID_BUTTON_ADD:
            if (!can_add(A, B))
            {
                status_bar = "Can't add (not equal amount of rows or columns)";
              //  return;
            }
            C = A + B;
            status_bar = "Successfully add";
            break;
        case ID_BUTTON_SUB:
            if (!can_sub(A, B))
            {
                status_bar = "Can't sub (not equal amount of rows or columns)";
               // return;
            }
            C = A - B;
            status_bar = "Successfully ";
            break;
        case ID_BUTTON_MULT:
            if (!can_mult(A, B))
            {
                status_bar = "Can't multiply (A(columns) != B(rows))";
               // return;
            }
            C = A * B;
            status_bar = "Successfully multiplied";
            break;
        case ID_BUTTON_DIV:
            if (!can_div(A, B))
            {
                status_bar = "Can't divide (not equal amount of rows or columns)";
                //return;
            }
            C = A;
            C *= inverse(B);
            status_bar = "Successfully divided";
            break;
        case ID_BUTTON_InsCInA:
            A = C;
            status_bar = "Successfully insert C in A";
            break;
        case ID_BUTTON_InsCInB:
            B = C;
            status_bar = "Successfully insert C in B";
            break;

    }
    glui->sync_live();
    std::cout <<"A:"<< A << std::endl<<"B:" << B << std::endl << std::endl <<"C:"<< C << std::endl;

    if(A.get_w() != A.getSpinnerRowsValue() || A.get_h() != A.getSpinnerColumnsValue() ||
       B.get_w() != B.getSpinnerRowsValue() || B.get_h() != B.getSpinnerColumnsValue() ||
       C.get_w() != C.getSpinnerRowsValue() || C.get_h() != C.getSpinnerColumnsValue()
            )
    {

        glui->close();
        basic_calculator_create();
    }




}

void basic_calculator_create()
{
    glui = GLUI_Master.create_glui( "Basic matrix calculator", 0, 1, 1);
    A.spinner_display(glui, control_cb);
    A.matrix_display(glui, control_cb, take_name(A));
    for(size_t i = 0; i < BUTTON_NUM ;i++)
    {
        myButtons[i].add_my_button(glui, control_cb);
        //glui->add_column(false);
    }
    B.spinner_display(glui, control_cb);
    B.matrix_display(glui, control_cb, take_name(B));
    glui->add_button("=");
    C.spinner_display(glui, control_cb);
    C.disableSpinners();
    C.matrix_display(glui, control_cb, take_name(C));
    glui->add_statictext("Status bar: "+status_bar)->set_alignment(GLUI_ALIGN_LEFT);

}




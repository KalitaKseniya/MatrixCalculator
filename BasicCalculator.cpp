//
// Created by ksenia on 12/6/19.
//

#include "BasicCalculator.h"
#define BUTTON_NUM 7
GLUI* glui = nullptr;
GLUI_matrix A = GLUI_matrix(SIZE_, SIZE_);
GLUI_matrix B = GLUI_matrix(SIZE_, SIZE_);
GLUI_matrix C = GLUI_matrix(SIZE_, SIZE_);

MY_GLUI_Button myGluiButtonSwap = MY_GLUI_Button(ID_BUTTON_SWAP, "swap"),myGluiButtonAdd = MY_GLUI_Button(ID_BUTTON_ADD, "+"),
        myGluiButtonSub = MY_GLUI_Button(ID_BUTTON_SUB, "-"), myGluiButtonMult = MY_GLUI_Button(ID_BUTTON_MULT, "*"),
        myGluiButtonDiv = MY_GLUI_Button(ID_BUTTON_DIV, "/"),
        myGluiButtonInsCInA = MY_GLUI_Button(ID_BUTTON_InsCInA, "Insert C in A"), myGluiButtonInsCInB = MY_GLUI_Button(ID_BUTTON_InsCInB, "Insert C in B");

MY_GLUI_Button myButtons[BUTTON_NUM] = {myGluiButtonSwap, myGluiButtonAdd,
                               myGluiButtonSub, myGluiButtonMult, myGluiButtonDiv, myGluiButtonInsCInA, myGluiButtonInsCInB};
void control_cb( int control ) {

    printf("callback: %d\n", control);

    switch(control) {
        case ID_SPINNER_DIMENSION:
            break;
        case ID_BUTTON_SWAP:
            std::swap(A, B);
            basic_calculator_create();
            break;
        case ID_BUTTON_ADD:
            if (!can_add(A, B))
            {
                return;
            }
            C = A + B;
            break;
        case ID_BUTTON_SUB:
            if (!can_sub(A, B))
            {
                return;
            }
            C = A - B;
            break;
        case ID_BUTTON_MULT:
            if (!can_mult(A, B))
            {
                return;
            }
            C = A * B;
            break;
        case ID_BUTTON_DIV:
            if (!can_div(A, B))
            {
               return;
            }
            C = inverse(B);
            C *= A;
            break;
        case ID_BUTTON_InsCInA:
           // if(A.)
            A = C;
            break;
        case ID_BUTTON_InsCInB:
            B = C;
            break;

    }
    std::cout <<"A:"<< A << std::endl<<"B:" << B << std::endl << std::endl <<"C:"<< C << std::endl;
    basic_calculator_create();
}
void basic_calculator_create()
{
    if(glui)
    {
        glui->close();
    }
    glui = GLUI_Master.create_glui( "Basic matrix calculator", 0, 1, 1);
    A.spinner_display(glui, control_cb);
    A.matrix_display(glui, control_cb);
    for(size_t i = 0; i < BUTTON_NUM ;i++)
    {
        myButtons[i].add_my_button(glui, control_cb);
        //glui->add_column(false);
    }
    B.spinner_display(glui, control_cb);
    B.matrix_display(glui, control_cb);
    glui->add_button("=");
    C.spinner_display(glui, control_cb, C.get_w(), C.get_h(), 0);
    C.matrix_display(glui, control_cb);


}




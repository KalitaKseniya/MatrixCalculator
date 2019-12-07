//
// Created by ksenia on 12/6/19.
//

#ifndef MATRIXCALCULATOR_BASICCALCULATOR_H
#define MATRIXCALCULATOR_BASICCALCULATOR_H

#include "GLUI_LinearAlgebra.h"
#include <iostream>
#include <string>

using namespace la;

class MY_GLUI_Button : public GLUI_Button {
    int ID;
    std::string sign;
public:
    MY_GLUI_Button(const int ID_ = -1, const std::string& sign_ = "") : ID(ID_), sign(sign_) {}
    void add_my_button(GLUI* glui_wnd, GLUI_CB (control_cb_func) )
    {
        glui_wnd->add_button(sign, ID, control_cb_func)->set_w(MY_BUTTON_WIDTH);
    }
};

extern GLUI* glui;
extern GLUI_matrix A, B, C;
extern MY_GLUI_Button myGluiButtonSwap, myGluiButtonAdd,
        myGluiButtonSub, myGluiButtonMult, myGluiButtonDiv,
        myGluiButtonInsCInA, myGluiButtonInsCInB;

void basic_calculator_create();
void control_cb( int control );



#endif //MATRIXCALCULATOR_BASICCALCULATOR_H

//
// Created by ksenia on 12/6/19.
//

#ifndef MATRIXCALCULATOR_BASICCALCULATOR_H
#define MATRIXCALCULATOR_BASICCALCULATOR_H

#include "GLUI_LinearAlgebra.h"
#include <iostream>
#include <string>

using namespace GLUI_la;




extern GLUI_matrix A, B, C;
extern MY_GLUI_Button myGluiButtonSwap, myGluiButtonAdd,
        myGluiButtonSub, myGluiButtonMult, myGluiButtonDiv,
        myGluiButtonInsCInA, myGluiButtonInsCInB;
extern std::string status_bar;
void basic_calculator_create();
void control_cb( int control );



#endif //MATRIXCALCULATOR_BASICCALCULATOR_H

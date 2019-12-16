//
// Created by ksenia on 12/10/19.
//

#ifndef MATRIXCALCULATOR_SCIENCECALCULATOR_H
#define MATRIXCALCULATOR_SCIENCECALCULATOR_H


#include "GLUI_LinearAlgebra.h"
#include <iostream>
#include <string>

using namespace GLUI_la;

extern GLUI_matrix R, H, M;
extern float rho;
extern float r;
//extern int is_pressed_checkbox;
//extern MY_GLUI_Button
extern std::string status_bar_science;
void science_calculator_create();
void control_science_cb( int control );


#endif //MATRIXCALCULATOR_SCIENCECALCULATOR_H

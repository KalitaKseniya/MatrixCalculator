//
// Created by ksenia on 12/10/19.
//

#ifndef MATRIXCALCULATOR_SCIENCECALCULATOR_H
#define MATRIXCALCULATOR_SCIENCECALCULATOR_H


#include "GLUI_LinearAlgebra.h"
#include "main_menu.h"
#include <iostream>
#include <string>

using namespace GLUI_la;

extern GLUI_matrix R, H, M;
extern std::string status_bar_advanced;
void advanced_calculator_create();
void control_advanced_cb( int control );


#endif //MATRIXCALCULATOR_SCIENCECALCULATOR_H

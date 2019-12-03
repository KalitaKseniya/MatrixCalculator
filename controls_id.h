//
// Created by ksenia on 12/2/19.
//

#ifndef MATRIXCALCULATOR_CONTROLS_ID_H
#define MATRIXCALCULATOR_CONTROLS_ID_H

#include "GL/glut.h"
#include "glui.h"

#define MIN_COL_SIZE 1
#define MAX_COL_SIZE 10
#define MAX_ROW_SIZE 10
#define MIN_ROW_SIZE 1

GLUI_Spinner *spinner_fst_matrix_row = NULL;
GLUI_Spinner *spinner_fst_matrix_col;
GLUI_Spinner *spinner_sec_matrix_row;
GLUI_Spinner *spinner_sec_matrix_col;
GLUI_Spinner *spinner_res_matrix_row;
GLUI_Spinner *spinner_res_matrix_col;

GLUI_EditText  *edittext_lambda_fst_matrix;
GLUI_EditText  *edittext_lambda_sec_matrix;

GLUI_Button* button_change;
GLUI_Button* button_add;
GLUI_Button* button_sub;
GLUI_Button* button_mult;
GLUI_Button* button_div;

GLUI_EditText **edittext_fst_matrix = NULL;
GLUI_EditText **edittext_sec_matrix = NULL;
GLUI_EditText **edittext_res_matrix = NULL;

GLUI_StaticText *statictext_res_matrix[3][3];
GLUI_StaticText *statictext_equal;

#define ID_SPINNER_FST_MATRIX_ROW 100
#define ID_SPINNER_FST_MATRIX_COL 101
#define ID_SPINNER_SEC_MATRIX_ROW 102
#define ID_SPINNER_SEC_MATRIX_COL 103
#define ID_SPINNER_RES_MATRIX_ROW 104
#define ID_SPINNER_RES_MATRIX_COL 105

#define ID_EDITTEXT_LAMBDA_FST_MATRIX 106
#define ID_EDITTEXT_LAMBDA_SEC_MATRIX 107

#define ID_BUTTON_CHANGE 108
#define ID_BUTTON_ADD 109
#define ID_BUTTON_SUB 110
#define ID_BUTTON_MULT 111
#define ID_BUTTON_DIV 112
#define ID_BUTTON_EQU 113

#define MY_BUTTON_WIDTH 45

int row_fst_matr = 3;
int col_fst_matr = 3;
int row_sec_matr = 3;
int col_sec_matr = 3;

//#define ID_EDITTEXT_FST_MATRIX[3][3];
//#define ID_EDITTEXT_SEC_MATRIX[3][3];

#define ID_STATICTEXT_RES_MATRIX[3][3];
#define ID_STATICTEXT_EQUAL 113




#endif //MATRIXCALCULATOR_CONTROLS_ID_H

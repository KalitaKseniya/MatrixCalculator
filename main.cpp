#include <cstring>
#include "GL/glut.h"
#include "glui.h"
#include "controls_id.h"
//старую версию глуи?


float xy_aspect;
int   last_x, last_y;
float rotationX = 0.0, rotationY = 0.0;
int   main_window;


int   wireframe = 0;
int   obj = 0;
int   segments = 8;

GLUI *glui;
std::string text = "Hello World!";

void control_cb( int control )
{
    printf( "callback: %d\n", control );
    switch(control)
    {

    }

}

void displayMatrix(GLUI* glui, int row, int col, GLUI_EditText** edittext_matrix)
{
    // edittext_matrix =  GLUI_EditText* [row];
    if(edittext_matrix == NULL)
    {
        edittext_matrix = new GLUI_EditText* [MAX_ROW_SIZE];
        for(int i = 0; i < MAX_COL_SIZE; i++)
        {
            edittext_matrix[i] = new GLUI_EditText[col];
        }
    }


    GLUI_Panel* matrix_panel = new GLUI_Panel;
    matrix_panel = new GLUI_Panel(glui, "");
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            edittext_matrix[i][j] = *(glui->add_edittext_to_panel(matrix_panel, "",GLUI_EDITTEXT_FLOAT, NULL, -1, control_cb));
        }
        if( i != 2)
        {
            glui->add_column_to_panel(matrix_panel,false);
        }
    }

}




void displayMatrixDimension(GLUI* glui, GLUI_Spinner* spinner_matrix_row,
        int ID_SPINNER_ROW,int& row_matrix, GLUI_Spinner* spinner_matrix_col, int ID_SPINNER_COL, int& col_matrix)
{
    GLUI_Panel* matrixPanel = new GLUI_Panel(glui, "");
    spinner_matrix_row = new GLUI_Spinner;
    (spinner_matrix_row = glui->add_spinner_to_panel(matrixPanel, "", GLUI_SPINNER_INT,
           &row_matrix, ID_SPINNER_ROW,  control_cb))->set_w(5);
    spinner_matrix_row->set_int_limits(MIN_ROW_SIZE,MAX_ROW_SIZE);
    glui->add_column_to_panel(matrixPanel, false);

    spinner_matrix_col = new GLUI_Spinner;
    spinner_matrix_col = (GLUI_Spinner*)
            (glui->add_spinner_to_panel(matrixPanel, "", GLUI_SPINNER_INT,&col_matrix,
             ID_SPINNER_COL,  control_cb));//->set_w(5);//set_w(5);
    spinner_matrix_col->set_int_limits(MIN_COL_SIZE, MAX_COL_SIZE);
}





int main(int argc, char* argv[])
{
    glutInit(&argc, argv);

    glui = GLUI_Master.create_glui( "Matrix calculator", 0, 400, 50 );
    displayMatrixDimension(glui, spinner_fst_matrix_row, ID_SPINNER_FST_MATRIX_ROW, row_fst_matr, spinner_fst_matrix_col, ID_SPINNER_FST_MATRIX_COL, col_fst_matr);
    displayMatrix(glui,3, 3, edittext_fst_matrix);
    glui->add_column(false);

    glui->add_statictext("");//->set_h(5);
    glui->add_button("swap", ID_BUTTON_CHANGE, control_cb)->set_w(MY_BUTTON_WIDTH);
    glui->add_button("+", ID_BUTTON_ADD, control_cb)->set_w(MY_BUTTON_WIDTH);
    glui->add_button("-", ID_BUTTON_SUB, control_cb)->set_w(MY_BUTTON_WIDTH);
    glui->add_button("*", ID_BUTTON_MULT, control_cb)->set_w(MY_BUTTON_WIDTH);
    glui->add_button("/", ID_BUTTON_DIV, control_cb)->set_w(MY_BUTTON_WIDTH);

    glui->add_column(false);
    displayMatrixDimension(glui, spinner_sec_matrix_row, ID_SPINNER_SEC_MATRIX_ROW, row_sec_matr, spinner_sec_matrix_col, ID_SPINNER_SEC_MATRIX_COL, col_sec_matr);
    displayMatrix(glui, 3, 3, edittext_sec_matrix);
    glui->add_column(false);

    glui->add_statictext("")->set_h(70);
    glui->add_button("=", ID_BUTTON_EQU, control_cb)->set_w(MY_BUTTON_WIDTH);

    glui->add_column(false);
    displayMatrix(glui, 3, 3, edittext_res_matrix);
    GLUI_Master.set_glutIdleFunc( NULL );
    glutMainLoop();

    return EXIT_SUCCESS;
}


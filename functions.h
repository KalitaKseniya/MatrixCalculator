////
//// Created by ksenia on 12/3/19.
////
//
//#ifndef MATRIXCALCULATOR_FUNCTIONS_H
//#define MATRIXCALCULATOR_FUNCTIONS_H
//
//#include "glui.h"
//#include "controls_id.h"
//#include "LinearAlgebra.h"
//
//using namespace la;
//
//GLUI* glui = nullptr;
//matrix A(SIZE_, SIZE_);
//matrix B(SIZE_, SIZE_);
//matrix C;
//
//GLUI_EditText** alloc_matr()
//{
//    GLUI_EditText** edittext_matrix = new GLUI_EditText* [MAX_SIZE];
//    for(int i = 0; i < MAX_SIZE; i++)
//    {
//        edittext_matrix[i] = new GLUI_EditText[MAX_SIZE];
//    }
//    return edittext_matrix;
//}
//
//void alloc_spin_panel(GLUI_Panel* panel, GLUI_Spinner* spinner_row, GLUI_Spinner* spinner_column)
//{
//    panel = new GLUI_Panel(glui, "");
//    spinner_row = new GLUI_Spinner;
//    spinner_column = new GLUI_Spinner;
//}
//
//void alloc_buttons()
//{
//    button_swap = new GLUI_Button;
//    button_add = new GLUI_Button;
//    button_sun = new GLUI_Button;
//    button_mult = new GLUI_Button;
//    button_div = new GLUI_Button;
//    button_equ = new GLUI_Button;
//}
//
//void spinner_display(GLUI_Panel* panel, GLUI_Spinner* spinner_matrix_row, GLUI_Spinner* spinner_matrix_col, int& row_live_var, int& col_live_var)
//{
//    *spinner_matrix_row = GLUI_Spinner(glui, "", row_live_var);
//    //  (spinner_matrix_row = glui->add_spinner_to_panel(matrixPanel, "", GLUI_SPINNER_INT,&row_matrix, ID_SPINNER_ROW,  control_cb))->set_w(5);
//    spinner_matrix_row->set_int_limits(MIN_SIZE,MAX_SIZE);
//    glui->add_column(false);
//    //glui->add_column_to_panel(matrixPanel, false);
////    spinner_matrix_col = (GLUI_Spinner*)
////            (glui->add_spinner_to_panel(matrixPanel, "", GLUI_SPINNER_INT,&col_matrix,
////                                        ID_SPINNER_COL,  control_cb));//->set_w(5);//set_w(5);
//    *spinner_matrix_col = GLUI_Spinner(glui, "", col_live_var);
//    spinner_matrix_col->set_int_limits(MIN_SIZE, MAX_SIZE);
//}
//
//void glui_create()
//{
//    if(glui != nullptr)
//    {
//        glui->close();
//    }
//    glui = GLUI_Master.create_glui( "Matrix calculator", 0, 1, 1);
//    spinner_display(panel_fst_matrix, spinner_row_fst_matrix ,spinner_col_fst_matrix, A.amount_of_rows_, A.amount_of_columns_);
////    spinner_display();
////    matrix_display(A);
////    buttons_display();
////    matrix_display(B);
//}
//
//
//
//void displayMatrix(GLUI* glui, int row, int col, GLUI_EditText** edittext_matrix);
//void displayMatrixDimension(GLUI* glui, GLUI_Spinner* spinner_matrix_row,
//                            int ID_SPINNER_ROW,size_t& row_matrix,
//                            GLUI_Spinner* spinner_matrix_col, int ID_SPINNER_COL, size_t& col_matrix);
//
//void control_cb( int control );
//void glui_create();
////void alloc_buttons()
////{
////    button_swap = new GLUI_Button;
////    button_add = new GLUI_Button;
////    button_sun = new GLUI_Button;
////    button_mult = new GLUI_Button;
////    button_div = new GLUI_Button;
////    button_equ = new GLUI_Button;
////}
////
//void buttons_display()
//{
//
//    glui->add_button("", ID_BUTTON_CHANGE, control_cb)->set_w(MY_BUTTON_WIDTH);
//    glui->add_button("+", ID_BUTTON_ADD, control_cb)->set_w(MY_BUTTON_WIDTH);
//    glui->add_button("-", ID_BUTTON_SUB, control_cb)->set_w(MY_BUTTON_WIDTH);
//    glui->add_button("*", ID_BUTTON_MULT, control_cb)->set_w(MY_BUTTON_WIDTH);
//    glui->add_button("/", ID_BUTTON_DIV, control_cb)->set_w(MY_BUTTON_WIDTH);
//    if(col_fst_matr + col_sec_matr < 10)
//    {
//        glui->add_column(false);
//    }
//}
//
//
//void displayMatrix(GLUI_EditText** edittext_matrix, matrix& M)
//{
//
//
//
//    //GLUI_Panel* matrix_panel = new GLUI_Panel(glui, "");
//    GLUI_EditText* p;
//    for(int i = 0; i < col; i++)
//    {
//        for(int j = 0; j < row; j++)
//        {
////            p = new GLUI_EditText(glui, "", GLUI_EDITTEXT_FLOAT, &M(j, i), -1, control_cb);//->set_w(5);
////          p->set_w(5);
//            edittext =  new GLUI_EditText( glui, "Text:", GLUI_EDITTEXT_FLOAT, &dtext, 3, control_cb );
//            edittext->set_w(50);
//        }
//        if( i != col-1)
//        {
//            glui->add_column(false);//glui->add_column_to_panel(matrix_panel,false);
//        }
//    }
//
//    if(col_fst_matr + col_sec_matr < 10)
//    {
//        glui->add_column(false);
//    }
//
//}
//
//
//
//
//void fst_matr_display()
//{
//    displayMatrixDimension(glui, spinner_fst_matrix_row, ID_SPINNER_FST_MATRIX_ROW, row_fst_matr, spinner_fst_matrix_col, ID_SPINNER_FST_MATRIX_COL,col_fst_matr);
//   // displayMatrixDimension(glui, spinner_fst_matrix_row, ID_SPINNER_FST_MATRIX_ROW, A.amount_of_rows_, spinner_fst_matrix_col, ID_SPINNER_FST_MATRIX_COL, A.amount_of_columns_);
//    displayMatrix(glui, A.amount_of_rows_, A.amount_of_columns_, edittext_fst_matrix, A);
//
//}
//void sec_matr_display()
//{
//    displayMatrixDimension(glui, spinner_sec_matrix_row, ID_SPINNER_SEC_MATRIX_ROW, row_sec_matr, spinner_sec_matrix_col, ID_SPINNER_SEC_MATRIX_COL, col_sec_matr);
//    displayMatrix(glui, row_sec_matr, col_sec_matr, edittext_sec_matrix, B);
//}
//
//void res_matr_display()
//{
//    //displayMatrixDimension(glui, spinner_res_matrix_row, -1, 0, ID_SPINNER_SEC_MATRIX_COL, col_sec_matr);
//    displayMatrix(glui, col_fst_matr, row_sec_matr, edittext_res_matrix, C);
//}
//
//
//
//
//
//
//
//
//
//void control_cb( int control )
//{
//    printf( "callback: %d fst:%d*%d, sec%d*%d\n", control, row_fst_matr, col_fst_matr,row_sec_matr, col_sec_matr );
//    //std::cout << A << std::endl << B << std::endl;
//    switch(control)
//    {
//        case ID_SPINNER_FST_MATRIX_ROW:
//        case ID_SPINNER_FST_MATRIX_COL:
//        case ID_SPINNER_SEC_MATRIX_ROW:
//        case ID_SPINNER_SEC_MATRIX_COL:
//        {
//            if(A.amount_of_rows_ != row_fst_matr || A.amount_of_columns_ != col_fst_matr
//               || B.amount_of_rows_ != row_sec_matr || B.amount_of_columns_ != col_sec_matr)
//            {
//                glui->close();
//                A.set_height(row_fst_matr);
//                B.set_height(row_sec_matr);
//                A.set_len(col_fst_matr);
//                B.set_len(col_sec_matr);
//                glui_create();
//            }
//            break;
//        }
//        case ID_BUTTON_CHANGE:
//            std::swap(row_fst_matr, row_sec_matr);
//            std::swap(col_fst_matr, col_sec_matr);
//            std::swap(A, B);
//            glui->close();
//            glui_create();
//            break;
//        case ID_BUTTON_ADD:
//            if(can_add(A, B))
//            {
//                glui->add_statictext("")->set_h(70);
//                glui->add_button("=", ID_BUTTON_EQU, control_cb)->set_w(MY_BUTTON_WIDTH);
//                glui->close();
//                glui_create();
//                C.set_len(A.amount_of_columns_);
//                C.set_height(B.amount_of_rows_);
//                C = A + B;
//                std::cout << A << std::endl << B << std::endl;
//                std::cout << C;
//                res_matr_display();
//            }
//            break;
//        case 1077:
//            glui->sync_live();
//            std::cout <<"i am here*" << a << "*";
//            break;
//
//    }
//
//}
//
//#endif //MATRIXCALCULATOR_FUNCTIONS_H

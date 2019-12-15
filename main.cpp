#include "GL/glut.h"
#include "glui.h"
#include "BasicCalculator.h"
#include "ScienceCalculator.h"

//make mainMenu
//add functions LinearAlgebra
//buttons to panel?
//C ouput doesn work



int main(int argc, char* argv[])
{

    glutInit(&argc, argv);
//    switch(menu_create())
//    {
//        case 1:
//            basic_calculator_create();
//            break;
//        case 2:
//            break;
//        case 3:
//            return EXIT_SUCCESS;
//    }
    basic_calculator_create();
    //science_calculator_create();
    GLUI_Master.set_glutIdleFunc(nullptr );
    glutMainLoop();
    return EXIT_SUCCESS;
}


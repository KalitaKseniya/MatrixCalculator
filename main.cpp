#include "GL/glut.h"
#include "glui.h"
#include "BasicCalculator.h"
#include "ScienceCalculator.h"
void control_menu_cb(int control)
{
    switch(control)
    {
        case ID_BUTTON_BASIC:
            glui->close();
            basic_calculator_create();
            break;
        case ID_BUTTON_ADVANCED:
            glui->close();
            science_calculator_create();
            break;
        case ID_BUTTON_ABOUT_PROG:
            glui->close();
            //about_programm_create();
            break;
        case ID_BUTTON_EXIT:
            glui->close();
            break;
    }
}

void menu_create()
{
    glui = GLUI_Master.create_glui( "Matrix calculator", 0, wnd_x, wnd_y);
    new GLUI_Button (glui, "Basic matrix calculator", ID_BUTTON_BASIC, control_menu_cb);
    new GLUI_StaticText(glui, "");
    new GLUI_Button (glui, "Advanced matrix calculator", ID_BUTTON_ADVANCED, control_menu_cb);
    new GLUI_StaticText(glui, "");
    new GLUI_Button (glui, "About programm", ID_BUTTON_ABOUT_PROG, control_menu_cb);
    new GLUI_StaticText(glui, "");
    new GLUI_Separator (glui);
    new GLUI_Button (glui,"EXIT", ID_BUTTON_EXIT, control_menu_cb);
}








int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    menu_create();
    GLUI_Master.set_glutIdleFunc(nullptr );
    glutMainLoop();
    return EXIT_SUCCESS;
}


//
// Created by ksenia on 12/16/19.
//

#include "main_menu.h"

GLUI* glui_about_prog = nullptr;

void control_cb_about_prog(int control)
{
    switch (control)
    {
        case ID_BUTTON_TO_MENU:
            glui_about_prog->close();
            break;
        default:
            break;
    }
}

void about_programm_create()
{
    glui_about_prog = GLUI_Master.create_glui_subwindow(glui->get_glut_window_id(),GLUI_SUBWINDOW_BOTTOM);
    new GLUI_StaticText(glui_about_prog, "Programm \"Matrix Calculator\"");
    new GLUI_StaticText(glui_about_prog, "created by Ksenia Kalita");
    new GLUI_StaticText(glui_about_prog, "in 2019 year.");
    new GLUI_Button(glui_about_prog, "to menu", ID_BUTTON_TO_MENU, control_cb_about_prog);
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

void control_menu_cb(int control) {
    switch(control)
    {
        case ID_BUTTON_BASIC:
            glui->close();
            basic_calculator_create();
            break;
        case ID_BUTTON_ADVANCED:
            glui->close();
            advanced_calculator_create();
            break;
        case ID_BUTTON_ABOUT_PROG:
            //glui->close();
            about_programm_create();
            break;
        case ID_BUTTON_EXIT:
            glui->close();
            break;
    }
}

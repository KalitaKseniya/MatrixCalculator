
#include "main_menu.h"

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    menu_create();
    GLUI_Master.set_glutIdleFunc(nullptr );
    glutMainLoop();
    return EXIT_SUCCESS;
}


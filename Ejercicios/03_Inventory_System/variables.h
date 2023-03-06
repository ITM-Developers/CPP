#ifndef VARIABLES_GLOBALES_H
#define VARIABLES_GLOBALES_H
    /*

    `8.`888b           ,8' .8.          8 888888888o.    8 8888          .8.          8 888888888o   8 8888         8 8888888888     d888888o.
     `8.`888b         ,8' .888.         8 8888    `88.   8 8888         .888.         8 8888    `88. 8 8888         8 8888         .`8888:' `88.
      `8.`888b       ,8' :88888.        8 8888     `88   8 8888        :88888.        8 8888     `88 8 8888         8 8888         8.`8888.   Y8
       `8.`888b     ,8' . `88888.       8 8888     ,88   8 8888       . `88888.       8 8888     ,88 8 8888         8 8888         `8.`8888.
        `8.`888b   ,8' .8. `88888.      8 8888.   ,88'   8 8888      .8. `88888.      8 8888.   ,88' 8 8888         8 888888888888  `8.`8888.
         `8.`888b ,8' .8`8. `88888.     8 888888888P'    8 8888     .8`8. `88888.     8 8888888888   8 8888         8 8888           `8.`8888.
          `8.`888b8' .8' `8. `88888.    8 8888`8b        8 8888    .8' `8. `88888.    8 8888    `88. 8 8888         8 8888            `8.`8888.
           `8.`888' .8'   `8. `88888.   8 8888 `8b.      8 8888   .8'   `8. `88888.   8 8888      88 8 8888         8 8888        8b   `8.`8888.
            `8.`8' .888888888. `88888.  8 8888   `8b.    8 8888  .888888888. `88888.  8 8888    ,88' 8 8888         8 8888        `8b.  ;8.`8888
             `8.` .8'       `8. `88888. 8 8888     `88.  8 8888 .8'       `8. `88888. 8 888888888P   8 888888888888 8 888888888888 `Y8888P ,88P'

    A continuacion se encuentran definidas todas las variables del programa, estas variables  PUEDEN SER MODIFICADAS para cambiar la configuracion y estilos del programa.
    */
    #define W_WIDTH 150                                                                     // El ancho de la ventana de la consola (es el numero de columnas)
    #define W_HEIGTH 40                                                                     // El alto de la ventana de la consola (es el numero de filas)
    #define W_TITLE "Sistema De Inventario"                                                 // Titulo de la ventana de la consola


    /*
        ,o888888o.        ,o888888o.     b.             8    d888888o. 8888888 8888888888   .8.          b.             8 8888888 8888888888 8 8888888888     d888888o.
       8888     `88.   . 8888     `88.   888o.          8  .`8888:' `88.     8 8888        .888.         888o.          8       8 8888       8 8888         .`8888:' `88.
    ,8 8888       `8. ,8 8888       `8b  Y88888o.       8  8.`8888.   Y8     8 8888       :88888.        Y88888o.       8       8 8888       8 8888         8.`8888.   Y8
    88 8888           88 8888        `8b .`Y888888o.    8  `8.`8888.         8 8888      . `88888.       .`Y888888o.    8       8 8888       8 8888         `8.`8888.
    88 8888           88 8888         88 8o. `Y888888o. 8   `8.`8888.        8 8888     .8. `88888.      8o. `Y888888o. 8       8 8888       8 888888888888  `8.`8888.
    88 8888           88 8888         88 8`Y8o. `Y88888o8    `8.`8888.       8 8888    .8`8. `88888.     8`Y8o. `Y88888o8       8 8888       8 8888           `8.`8888.
    88 8888           88 8888        ,8P 8   `Y8o. `Y8888     `8.`8888.      8 8888   .8' `8. `88888.    8   `Y8o. `Y8888       8 8888       8 8888            `8.`8888.
    `8 8888       .8' `8 8888       ,8P  8      `Y8o. `Y8 8b   `8.`8888.     8 8888  .8'   `8. `88888.   8      `Y8o. `Y8       8 8888       8 8888        8b   `8.`8888.
       8888     ,88'   ` 8888     ,88'   8         `Y8o.` `8b.  ;8.`8888     8 8888 .888888888. `88888.  8         `Y8o.`       8 8888       8 8888        `8b.  ;8.`8888
        `8888888P'        `8888888P'     8            `Yo  `Y8888P ,88P'     8 8888.8'       `8. `88888. 8            `Yo       8 8888       8 888888888888 `Y8888P ,88P'

    A continuacion se define las constantes del programa, estas constantes NO DEBEM DE SER MODIFICADAS para que funcione correctamente el programa, son datos
    */
    #define ROWS W_HEIGTH                                                                   // Es un alias para W_WIDTH, se usa en bucles y el nombre es mas intuitivo
    #define COLS W_WIDTH                                                                    // Es un alias para W_HEIGHT, se usa en bucles y el nombre es mas intuitivo
    #define B_BLACK_F_GREEN (FOREGROUND_GREEN | FOREGROUND_INTENSITY)                       // Background Negro y Texto Verde
    #define B_BLACK_F_CYAN (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY)      // Background Negro y Texto Cyan
    #define TERMINAR_PROGRAMA 0
    COORD consoleWindowSize = {W_WIDTH, W_HEIGTH};
    SMALL_RECT rectWindowSize = {0,0,W_WIDTH,W_HEIGTH};

    /*
        ,o888888o.    8 8888         ,o888888o.     8 888888888o          .8.          8 8888         8 8888888888     d888888o.
       8888     `88.  8 8888      . 8888     `88.   8 8888    `88.       .888.         8 8888         8 8888         .`8888:' `88.
    ,8 8888       `8. 8 8888     ,8 8888       `8b  8 8888     `88      :88888.        8 8888         8 8888         8.`8888.   Y8
    88 8888           8 8888     88 8888        `8b 8 8888     ,88     . `88888.       8 8888         8 8888         `8.`8888.
    88 8888           8 8888     88 8888         88 8 8888.   ,88'    .8. `88888.      8 8888         8 888888888888  `8.`8888.
    88 8888           8 8888     88 8888         88 8 8888888888     .8`8. `88888.     8 8888         8 8888           `8.`8888.
    88 8888   8888888 8 8888     88 8888        ,8P 8 8888    `88.  .8' `8. `88888.    8 8888         8 8888            `8.`8888.
    `8 8888       .8' 8 8888     `8 8888       ,8P  8 8888      88 .8'   `8. `88888.   8 8888         8 8888        8b   `8.`8888.
       8888     ,88'  8 8888      ` 8888     ,88'   8 8888    ,88'.888888888. `88888.  8 8888         8 8888        `8b.  ;8.`8888
        `8888888P'    8 888888888888 `8888888P'     8 888888888P .8'       `8. `88888. 8 888888888888 8 888888888888 `Y8888P ,88P'

    A continuacion se definen todas las variables que son globales para el programa es decir estaran disponibles en todo el programa y se usan por una o mas funciones
    */

    // Variables para la manipulacion de la ventana de la consola
    HWND hWnd;                                                                              // El handle de la ventana de la consola
    HANDLE rHnd;                                                                            // El handle de lectura
    HANDLE wHnd;                                                                            // el handle de escritura
    RECT rectConsole;                                                                       // Rectangulo que representa las dimensiones de la ventana de consola
    RECT rectScreen;                                                                        // Rectangulo que representa las dimensiones del monitor
    CONSOLE_SCREEN_BUFFER_INFO csbi;                                                        // Objeto que guarda la informcion de la consola (color texto, fuente, buffer, etc)

    // variables para la logica de ControllerLogin
    char username[30];
    char password[30];
    int SESSION_ESTA_ABIERTA = FALSE;
#endif // VARIABLES_GLOBALES


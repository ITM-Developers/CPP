#ifndef VARIABLES_GLOBALES_H
    #include "variables.h"
#endif

#ifndef VENTANA_H
    #define VENTANA_H

    void initializeWindow()
    {
        // Inicializamos los Handlers para manipular la consola
        hWnd = GetConsoleWindow();
        wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
        rHnd = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleScreenBufferInfo(wHnd, &csbi);

        SetConsoleTitle(W_TITLE);
        SetConsoleTextAttribute(wHnd, B_BLACK_F_GREEN);
        SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

        csbi.dwSize              = consoleWindowSize;
        csbi.srWindow            = rectWindowSize;
        csbi.dwMaximumWindowSize = consoleWindowSize;

        system("MODE CON: COLS=150 LINES=40");

        // INDICAMOS EL MODO UNICODE PARA EL ASCII EXTENDIDO
        //_setmode(_fileno(stdout), _O_U16TEXT);
    }

    void setWindowBackground(int color)
    {
        WORD wOldColorAttribs = csbi.wAttributes;;
        SetConsoleTextAttribute(wHnd, color);
        for(int row = 0; row < ROWS; row++)
        {
            for(int col = 0; col < COLS; col++)
            {
                wprintf(L"█");
            }
        }
        SetConsoleTextAttribute(wHnd, wOldColorAttribs);
    }

    void gotoxy(int x, int y)
    {
        COORD c = { x, y };
        SetConsoleCursorPosition( wHnd , c);
    }

    void moveConsoleToCoordXY(int x, int y)
    {
        // Obtenemos las dimensiones del rectangulo de la consola
        GetClientRect(hWnd, &rectConsole);
        // Obtenemos las dimensiones del rectangulo de la pantalla
        GetWindowRect(hWnd, &rectScreen);

        MoveWindow(hWnd, x, y, rectConsole.right - rectConsole.left, rectConsole.bottom - rectConsole.top, TRUE);
    }

    void moveConsoleToCenter()
    {
        int x, y;

        // Obtenemos las dimensiones del rectangulo de la consola
        GetClientRect(hWnd, &rectConsole);
        // Obtenemos las dimensiones del rectangulo de la pantalla
        GetWindowRect(hWnd, &rectScreen);

        x = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectScreen.right - rectScreen.left) / 2;
        y = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectScreen.bottom - rectScreen.top) / 2;

        MoveWindow(hWnd, x, y, rectConsole.right - rectConsole.left, rectConsole.bottom - rectConsole.top, TRUE);
    }

    void print(char * text, int x, int y)
    {
        gotoxy(x,y);
        printf(text);
    }

    void printChar(char c, int x, int y)
    {
        int charWidth  = 12;
        int charHeight =  7;

        switch(c)
        {
            case 'C':
                gotoxy(x  , y+0);  printf("████████████");
                gotoxy(x  , y+1);  printf("██");
                gotoxy(x  , y+2);  printf("██");
                gotoxy(x  , y+3);  printf("██");
                gotoxy(x  , y+4);  printf("██");
                gotoxy(x  , y+5);  printf("██");
                gotoxy(x  , y+6);  printf("████████████");
                break;
            case 'E':
                gotoxy(x  , y+0);  printf("████████████");
                gotoxy(x  , y+1);  printf("██");
                gotoxy(x  , y+2);  printf("██");
                gotoxy(x  , y+3);  printf("████████████");
                gotoxy(x  , y+4);  printf("██");
                gotoxy(x  , y+5);  printf("██");
                gotoxy(x  , y+6);  printf("████████████");
                break;
            case 'N':
                gotoxy(x  , y+0);  printf("████████████");
                gotoxy(x  , y+1);  printf("██");
                gotoxy(x  , y+2);  printf("██");
                gotoxy(x  , y+3);  printf("██");
                gotoxy(x  , y+4);  printf("██");
                gotoxy(x  , y+5);  printf("██");
                gotoxy(x  , y+6);  printf("████████████");
                break;
            case 'M':
                gotoxy(x  , y+0);  printf("████████████");
                gotoxy(x  , y+1);  printf("██");
                gotoxy(x  , y+2);  printf("██");
                gotoxy(x  , y+3);  printf("██");
                gotoxy(x  , y+4);  printf("██");
                gotoxy(x  , y+5);  printf("██");
                gotoxy(x  , y+6);  printf("██");
                break;
            case 'U':
                gotoxy(x  , y+0);  printf("████████████");
                gotoxy(x  , y+1);  printf("██");
                gotoxy(x  , y+2);  printf("██");
                gotoxy(x  , y+3);  printf("██");
                gotoxy(x  , y+4);  printf("██");
                gotoxy(x  , y+5);  printf("██");
                gotoxy(x  , y+6);  printf("████████████");
                break;
            case 'I':
                gotoxy(x  , y+0);  printf("████████████");
                gotoxy(x+5, y+1);       printf("██");
                gotoxy(x+5, y+2);       printf("██");
                gotoxy(x+5, y+3);       printf("██");
                gotoxy(x+5, y+4);       printf("██");
                gotoxy(x+5, y+5);       printf("██");
                gotoxy(x  , y+6);  printf("████████████");
                break;
        }
    }

    void showAlert(char * msg)
    {
        int col, row, MARGIN = 10, INITIAL_ROW = 22;
        char response[10];

        gotoxy(MARGIN, INITIAL_ROW);

        for(row = INITIAL_ROW; row < (INITIAL_ROW + 4); row++)
        {
            for(int col = MARGIN; col < COLS - MARGIN; col++)
            {
                printf("%c",219);
            }
            gotoxy(MARGIN, row);
        }

        scanf("%s",&response);
    }

    // VISTAS DISPONIBLES
    void showViewLogin()
    {
        system("cls");
        print("PASSOWRD: ",70,27);
        print("USERNAME: ",70,26);
        scanf("%s", &username);
        gotoxy(80,27);
        scanf("%s", &password);
    }

    int showViewMenu()
    {
        int opcionSeleccionada;
        system("cls");

        print("Menu de Opciones",10,3);
        print("1. Agregar Articulo",10,4);
        print("2. Ver Art",10,5);
        print("3. oascpasopa",10,6);
        print("4. ascasjk",10,7);
        print("5. Terminar Programa",10,8);

        print("Escribe el numero de la opcion que deseas ejecutar:",10,19);
        print(">> ",10,20);
        scanf("%i", &opcionSeleccionada);

        showAlert("mensaje");
        return 1;
    }
#endif // VENTANA_H

#define _WIN32_WINNT 0x0500 //Para evitar que el usuario reajuste el tamano de la ventana

#include <stdio.h>
#include <stdlib.h>

// Librerias para manipulacion de la ventana de la consola
#include <windows.h>
#include <wincon.h>
#include <processenv.h>
// Librerias para imprimir caracteres Unicode
#include <locale.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#ifndef _O_U16TEXT
  #define _O_U16TEXT 0x20000
#endif

#include "variables.h"
#include "ventana.h"
#include "ControllerLogin.h"

// https://kbdlayout.info/kbdes/virtualkeys+names
LRESULT CALLBACK KeyboardHook(int nCode, WPARAM wParam, LPARAM lParam)
{
    char text[20];

    static int last;
    BOOL letter = 1;
    if(nCode == HC_ACTION) {
        if(wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;

            switch (p->vkCode)
            {
            case VK_LBUTTON:            strcpy(text, "<VK_LBUTTON>");   break;
            case VK_RBUTTON:            strcpy(text, "<VK_RBUTTON>");   break;
            case VK_CANCEL:             strcpy(text, "<VK_CANCEL>");    break;
            case VK_MBUTTON:            strcpy(text, "<VK_MBUTTON>");   break;
            case VK_XBUTTON1:           strcpy(text, "<>"); break;
            case VK_XBUTTON2:           strcpy(text, "<>"); break;
            case VK_BACK:               strcpy(text, "<>"); break;
            case VK_TAB:                strcpy(text, "<VK_TAB>");       break;
            case VK_CLEAR:              strcpy(text, "<>"); break;
            case VK_RETURN:             strcpy(text, "<VK_RETURN>");    break;
            case VK_SHIFT:              strcpy(text, "<VK_SHIFT>");     break;
            case VK_CONTROL:            strcpy(text, "<VK_CONTROL>");   break;
            case VK_MENU:               strcpy(text, "<>"); break;
            case VK_PAUSE:              strcpy(text, "<>"); break;
            case VK_CAPITAL:            strcpy(text, "<>"); break;
            case VK_KANA:               strcpy(text, "<>"); break;
            case VK_IME_ON:             strcpy(text, "<>"); break;
            case VK_JUNJA:              strcpy(text, "<>"); break;
            case VK_FINAL:              strcpy(text, "<>"); break;
            case VK_HANJA:              strcpy(text, "<>"); break;
            case VK_IME_OFF:            strcpy(text, "<>"); break;
            case VK_ESCAPE:             strcpy(text, "<>"); break;
            case VK_CONVERT:            strcpy(text, "<>"); break;
            case VK_NONCONVERT:         strcpy(text, "<>"); break;
            case VK_ACCEPT:             strcpy(text, "<>"); break;
            case VK_MODECHANGE:         strcpy(text, "<>"); break;
            case VK_SPACE:              strcpy(text, "<>"); break;
            case VK_PRIOR:              strcpy(text, "<>"); break;
            case VK_NEXT:               strcpy(text, "<>"); break;
            case VK_END:                strcpy(text, "<>"); break;
            case VK_HOME:               strcpy(text, "<>"); break;
            case VK_LEFT:               strcpy(text, "<>"); break;
            case VK_UP:                 strcpy(text, "<>"); break;
            case VK_RIGHT:              strcpy(text, "<>"); break;
            case VK_DOWN:               strcpy(text, "<>"); break;
            case VK_SELECT:             strcpy(text, "<>"); break;
            case VK_PRINT:              strcpy(text, "<>"); break;
            case VK_EXECUTE:            strcpy(text, "<>"); break;
            case VK_SNAPSHOT:           strcpy(text, "<>"); break;
            case VK_INSERT:             strcpy(text, "<>"); break;
            case VK_DELETE:             strcpy(text, "<>"); break;
            case VK_HELP:               strcpy(text, "<>"); break;
            case VK_LWIN:               strcpy(text, "<>"); break;
            case VK_RWIN:               strcpy(text, "<>"); break;
            case VK_APPS:               strcpy(text, "<>"); break;
            case VK_SLEEP:              strcpy(text, "<>"); break;
            case VK_NUMPAD0:            strcpy(text, "<>"); break;
            case VK_NUMPAD1:            strcpy(text, "<>"); break;
            case VK_NUMPAD2:            strcpy(text, "<>"); break;
            case VK_NUMPAD3:            strcpy(text, "<>"); break;
            case VK_NUMPAD4:            strcpy(text, "<>"); break;
            case VK_NUMPAD5:            strcpy(text, "<>"); break;
            case VK_NUMPAD6:            strcpy(text, "<>"); break;
            case VK_NUMPAD7:            strcpy(text, "<>"); break;
            case VK_NUMPAD8:            strcpy(text, "<>"); break;
            case VK_NUMPAD9:            strcpy(text, "<>"); break;
            case VK_MULTIPLY:           strcpy(text, "<>"); break;
            case VK_ADD:                strcpy(text, "<>"); break;
            case VK_SEPARATOR:          strcpy(text, "<>"); break;
            case VK_SUBTRACT:           strcpy(text, "<>"); break;
            case VK_DECIMAL:            strcpy(text, "<>"); break;
            case VK_DIVIDE:             strcpy(text, "<>"); break;
            case VK_F1:                 strcpy(text, "<>"); break;
            case VK_F2:                 strcpy(text, "<>"); break;
            case VK_F3:                 strcpy(text, "<>"); break;
            case VK_F4:                 strcpy(text, "<>"); break;
            case VK_F5:                 strcpy(text, "<>"); break;
            case VK_F6:                 strcpy(text, "<>"); break;
            case VK_F7:                 strcpy(text, "<>"); break;
            case VK_F8:                 strcpy(text, "<>"); break;
            case VK_F9:                 strcpy(text, "<>"); break;
            case VK_F10:                strcpy(text, "<>"); break;
            case VK_F11:                strcpy(text, "<>"); break;
            case VK_F12:                strcpy(text, "<>"); break;
            case VK_NUMLOCK:            strcpy(text, "<>"); break;
            case VK_SCROLL:             strcpy(text, "<>"); break;
            case VK_LSHIFT:             strcpy(text, "<>"); break;
            case VK_RSHIFT:             strcpy(text, "<>"); break;
            case VK_LCONTROL:           strcpy(text, "<>"); break;
            case VK_RCONTROL:           strcpy(text, "<>"); break;
            case VK_LMENU:              strcpy(text, "<>"); break;
            case VK_RMENU:              strcpy(text, "<>"); break;
            case VK_BROWSER_BACK:       strcpy(text, "<>"); break;
            case VK_BROWSER_FORWARD:    strcpy(text, "<>"); break;
            case VK_BROWSER_REFRESH:    strcpy(text, "<>"); break;
            case VK_BROWSER_STOP:       strcpy(text, "<>"); break;
            case VK_OEM_PLUS:           strcpy(text, "<>"); break;
            case VK_OEM_COMMA:          strcpy(text, "<>"); break;
            case VK_OEM_MINUS:          strcpy(text, "<>"); break;
            case VK_OEM_PERIOD:         strcpy(text, "<>"); break;
            case VK_OEM_CLEAR:          strcpy(text, "<>"); break;
            case VK_OEM_3:
                // US STANDARD KEYBOARD '~'
                // ES STANDARD KEYBOARD 'Ñ'
                strcpy(text, "Ñ");
                break;
            case 0x30:                  strcpy(text, "0"); break;
            case 0x31:                  strcpy(text, "1"); break;
            case 0x32:                  strcpy(text, "2"); break;
            case 0x33:                  strcpy(text, "3"); break;
            case 0x34:                  strcpy(text, "4"); break;
            case 0x35:                  strcpy(text, "5"); break;
            case 0x36:                  strcpy(text, "6"); break;
            case 0x37:                  strcpy(text, "7"); break;
            case 0x38:                  strcpy(text, "8"); break;
            case 0x39:                  strcpy(text, "9"); break;
            case 0x41:                  strcpy(text, "A"); break;
            case 0x42:                  strcpy(text, "B"); break;
            case 0x43:                  strcpy(text, "C"); break;
            case 0x44:                  strcpy(text, "D"); break;
            case 0x45:                  strcpy(text, "E"); break;
            case 0x46:                  strcpy(text, "F"); break;
            case 0x47:                  strcpy(text, "G"); break;
            case 0x48:                  strcpy(text, "H"); break;
            case 0x49:                  strcpy(text, "I"); break;
            case 0x4A:                  strcpy(text, "J"); break;
            case 0x4B:                  strcpy(text, "K"); break;
            case 0x4C:                  strcpy(text, "L"); break;
            case 0x4D:                  strcpy(text, "M"); break;
            case 0x4E:                  strcpy(text, "N"); break;
            case 0x4F:                  strcpy(text, "O"); break;
            case 0x50:                  strcpy(text, "P"); break;
            case 0x51:                  strcpy(text, "Q"); break;
            case 0x52:                  strcpy(text, "R"); break;
            case 0x53:                  strcpy(text, "S"); break;
            case 0x54:                  strcpy(text, "T"); break;
            case 0x55:                  strcpy(text, "U"); break;
            case 0x56:                  strcpy(text, "V"); break;
            case 0x57:                  strcpy(text, "W"); break;
            case 0x58:                  strcpy(text, "X"); break;
            case 0x59:                  strcpy(text, "Y"); break;
            case 0x5A:                  strcpy(text, "Z"); break;
            default:
                strcpy(text, "<INVALID>");
                break;
            }

            printf("%s\n",text);
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main(int argc, char* argv[])
{
    // KEYLOGGER
//    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHook, 0, 0);
//    MSG msg;
//    while(!GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }
//    UnhookWindowsHookEx(hook);

    initializeWindow();
//    do{
//        showViewLogin();
//    }while( iniciarSesion() == FALSE );

    int opcionSeleccionada = TERMINAR_PROGRAMA;
    do{
         opcionSeleccionada = showViewMenu();
    }while(opcionSeleccionada != TERMINAR_PROGRAMA);

//    LPSTR buffer[200];
//    if( SESSION_ESTA_ABIERTA )
//        GetEnvironmentVariableA("USERPROFILE",buffer, 200);
//    wprintf(L": %s", buffer);
//    getchar();
    return 0;
}

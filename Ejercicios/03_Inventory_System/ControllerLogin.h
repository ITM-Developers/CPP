#ifndef CONTROLLER_LOGIN_H
#define CONTROLLER_LOGIN_H

int iniciarSesion()
{
    if( strcmp(username, "admin") != 0 )
        return FALSE;

    if( strcmp(password, "admin") != 0 )
        return FALSE;

    SESSION_ESTA_ABIERTA = TRUE;
    return TRUE;
}

int cerrarSesion()
{
    strcpy(username, "");
    strcpy(password, "");
    SESSION_ESTA_ABIERTA = FALSE;
    return TRUE;
}

#endif // CONTROLLER_LOGIN_H

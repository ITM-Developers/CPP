TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    -I/usr/include/cppconn

LIBS += \
    -lmysqlcppconn

SOURCES += \
        Algebra.cpp \
        Cronometro.cpp \
        Diccionario.cpp \
        Fecha.cpp \
        Geometria.cpp \
        MySQLConnection.cpp \
        Texto.cpp \
        ascii_display.cpp \
        main.cpp

HEADERS += \
    ADT/Cola.h \
    ADT/Pila.h \
    ADT/Nodo.h \
    Algebra.h \
    Algoritmos.h \
    Cronometro.h \
    Diccionario.h \
    Fecha.h \
    Geometria.h \
    Matriz2D.h \
    MySQLConnection.h \
    Texto.h \
    ascii_display.h

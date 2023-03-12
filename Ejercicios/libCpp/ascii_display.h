#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#ifndef IOMANIP_H
#define IOMANIP_H
#include <iomanip>
#endif

#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

#include "Matriz2D.h"

#ifndef ASCII_DISPLAY_H
#define ASCII_DISPLAY_H

using namespace std;

class ASCII_Display
{
public:
    ASCII_Display();
    void printTable( Matriz2D<string> model );
    void printAsciiTable();
};

#endif // ASCII_DISPLAY_H

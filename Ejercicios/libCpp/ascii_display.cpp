#include "ascii_display.h"

ASCII_Display::ASCII_Display()
{

}

void ASCII_Display::printTable( Matriz2D<string> model )
{
    // ES NECESARIO SABER CUAL ES LA CASILLA MAS ANCHA PARA ASIGNAR TODAS  LAS
    // CASILLAS DE LA COLUMNA A ESE MISMO TAMANO DE CARCATERES, ARA ESTO ALMACENAMOS
    // LAS DIMENSIONES EN UN ARRAY DE INT's
    vector<size_t> columnWidths;
    size_t sumWidth = 0;

    // INICIALIZAMOS TODOS LOS ANCHOS DE COLUMNA A 0
    for(size_t i=0; i<model.getNumCols(); i++)
        columnWidths.push_back(0);

    // AHORA RECORREMOS LAS CASILLAS DE LA MISMA COLUMNA PARA DETERMINAR CUAL ES LA
    // MAS ANCHA Y ASIGNARLE ESE VALOR A TODAS LAS CASILLAS DE ESA MISMA COLUMNA
    for(size_t col=0; col < model.getNumCols(); col++)
    {
        for(size_t row=0; row < model.getNumRows(); row++)
        {
            string columnValue = model.getXY(col,row);
            if(columnValue.size() > columnWidths[col])
            {
                columnWidths[col] = columnValue.size();
            }
        }
    }
    for(size_t col=0; col < model.getNumCols(); col++)
        sumWidth += columnWidths[col] + 2;
    sumWidth += columnWidths.size()-1;

    for(size_t row=0; row < model.getNumRows(); row++)
    {
        if( row == 0)
        {
            cout << "+";
            cout << setw(sumWidth) << setfill('-') << "-";
            cout << "+" << endl;
        }
        else
        {
             cout << "|";
             cout << setw(sumWidth) << setfill('-') << "-";
             cout << "|" << endl;
        }

        for(size_t col=0; col < model.getNumCols(); col++)
        {
            string columnValue = model.getXY(col,row);

            if( col == 0)
                cout << "|";

            cout << " ";
            cout << setw(columnWidths[col]) << setfill(' ') << left << columnValue;
            cout << " |";
        }
        cout << endl;
    }
    cout << "+";
    cout << setw(sumWidth) << setfill('-') << "-";
    cout << "+" << endl;
}

void ASCII_Display::printAsciiTable(){

}

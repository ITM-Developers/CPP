/*
 ___ _____ __  __       ____                 _
|_ _|_   _|  \/  |     |  _ \  _____   _____| | ___  _ __   ___ _ __ ___
 | |  | | | |\/| |_____| | | |/ _ \ \ / / _ \ |/ _ \| '_ \ / _ \ '__/ __|
 | |  | | | |  | |_____| |_| |  __/\ V /  __/ | (_) | |_) |  __/ |  \__ \
|___| |_| |_|  |_|     |____/ \___| \_/ \___|_|\___/| .__/ \___|_|  |___/
                                                    |_|
            https://www.facebook.com/ITMDevelopers
 */
#include <iostream>
#include <string>

using namespace std;

bool esNumeroImpar( int numero )
{
    if( numero % 2 == 0 )
        return false;   // ES PAR
    else
        return true;    // ES IMPAR
}


int main()
{
    for(int i=0; i<=10; i++)
    {
        if( esNumeroImpar(i) )
            cout << i << " = IMPAR" << endl;
        else
            cout << i << " = PAR" << endl;
    }
    return 0;
}


//    vector<string> mi;

//    unsigned char caracter;
//    setlocale(LC_CTYPE, "");
//    cout << "DEC\t" << "HEX\t" << "Simbolo" << endl;
//    for(int i = 32; i < 256; i++)
//    {
//        caracter = i;
//        cout << dec << i << "\t";
//        cout << hex << i << "\t";
//        cout << caracter << endl;
//    }
//    Matriz2D<int> m1(3,3);
//    Matriz2D<int> m2(3,3);

//    m1.setXY(11,0,0); m1.setXY(21,1,0); m1.setXY(31,2,0);
//    m1.setXY(12,0,1); m1.setXY(22,1,1); m1.setXY(32,2,1);
//    m1.setXY(13,0,2); m1.setXY(23,1,2); m1.setXY(33,2,2);
//    m1.print();

//    m2.setXY(11,0,0); m2.setXY(21,1,0); m2.setXY(31,2,0);
//    m2.setXY(12,0,1); m2.setXY(22,1,1); m2.setXY(32,2,1);
//    m2.setXY(13,0,2); m2.setXY(23,1,2); m2.setXY(33,2,2);
//    m2.print();
//    m1 = m2;
//    m2.print();


//    string V_V = (  true  && true  ) ? "true" : "false" ;
//    string V_F = (  true  && false ) ? "true" : "false" ;
//    string F_F = ( false  && false ) ? "true" : "false" ;
//    string F_V = ( false  && true  ) ? "true" : "false" ;


//    ASCII_Display d;
//    d.printTable( m );


//  LIBRERIA ADT
//    Nodo<int> nodo;
//    nodo.setValue(5);
//    nodo.addNode(7,'N');
//    nodo.addNode(8,'N');
//    nodo.addNode(9,'N');
//    nodo.addNode(1,'S');
//    nodo.addNode(2,'S');
//    nodo.addNode(3,'S');
//    nodo.addNode(6,'W');
//    nodo.addNode(4,'E');
//    nodo.print();

//    Nodo<int>* p2;
//    Nodo<int>* p3;

//    Nodo<int> nodo;
//    nodo.setValue(1);

//    p2 = nodo.addNode(0,'N');
//    p3 = nodo.addNode(2,'S');

//    p2->addNode(-1,'N');
//    p3->addNode(3,'S');
//    nodo.print();
//    p2->print();
//    p3->print();

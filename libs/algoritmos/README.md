# libCpp_Algoritmos

```cpp
#include <iostream>
#include "Algoritmos.h"

using namespace std;

void printArray(int* arreglo, size_t TAM)
{
    cout << "+----------+----------+" << endl;
    cout << "+  Indice  |  Valor   |" << endl;
    cout << "+----------+----------+" << endl;
    for(size_t i = 0; i < TAM; ++i)
    {
        cout << "|";
        cout << setw(10) << i;
        cout << "|";
        cout << setw(10) << arreglo[i];
        cout << "|" << endl;
    }
    cout << "+----------+----------+" << endl;
}

void fillArrayRandomly(int* arreglo, size_t TAM)
{
    int MAXIMO = 50, MINIMO = 0;
    for(size_t i=0; i < TAM; ++i)
    arreglo[i] = (rand() % (MAXIMO - MINIMO + 1)) + MINIMO;
}

int main()
{
    int ar[20];
    fillArrayRandomly(ar, 20);
    printArray(ar, 20);

//    Algoritmos<int> algoritmo;
//    algoritmo.bubbleSort(ar,20);

//    countSort(ar,20);
    printArray(ar, 20);
    return 0;
}
```

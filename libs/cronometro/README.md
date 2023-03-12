# libCPP_Cronometro
Este proyecto es una clase escrita en C++ que representa a un cronometro y es muy útil cuando quieres medir el tiempo trascurrido entre dos puntos de tu programa, también cuando deseas saber cuanto tiempo toma realizar alguna operación.

Para hacer uso de esta clase solo descargar los archivos **Cronometro.h** y **Cronometro.cpp**, despues incluyelos en tu proyecto y listo.

A continuacion se muestra un ejemplo practico.
```cpp
#include <iostream>
#include "Cronometro.h";

using namespace std;

int main()
{
    // Paso 1: Inicializacion
    Cronometro cronometro;

    // Paso 2: Inicia el cronometro
    cronometro.start();

    // Paso 3: Realiza las operaciones que deseas medir
    
    // Paso 4: Deten el cronomtro
    cronometro.stop();

    // Paso 5: Consulta el tiempo transcurrido
    cout << "Tiempo Transcurrido: " << cronometro.getSecondsElapsed() << " segundos." << endl;
    return 0;
}

```

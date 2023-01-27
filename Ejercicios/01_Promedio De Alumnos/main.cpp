/*
 ___ _____ __  __       ____                 _
|_ _|_   _|  \/  |     |  _ \  _____   _____| | ___  _ __   ___ _ __ ___
 | |  | | | |\/| |_____| | | |/ _ \ \ / / _ \ |/ _ \| '_ \ / _ \ '__/ __|
 | |  | | | |  | |_____| |_| |  __/\ V /  __/ | (_) | |_) |  __/ |  \__ \
|___| |_| |_|  |_|     |____/ \___| \_/ \___|_|\___/| .__/ \___|_|  |___/
                                                    |_|
            Pagina:     https://www.facebook.com/ITMDevelopers
            Grupo C++:  https://www.facebook.com/groups/711833650347755
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <iterator>

using namespace std;

struct Alumno{
    int DNI;
    string nombre;
    string apellido;
    double calificaciones[3];

};

double calcularPromedio( double* calificacion, int numeroDeExamenes)
{
    double promedio = 0;

    for(int i=0; i<numeroDeExamenes; i++)
    {
        promedio += calificacion[i];
    }

    return promedio / numeroDeExamenes;
}

int main()
{
    const double NUMERO_DE_EXAMENES = 3;
    int indiceDelAlumno = 0, indiceAlumnoMejorPromedio;
    double mejorPromedio = 0;
    vector<Alumno*> alumnos;
    struct Alumno* alumno;

    // bucle infiinito
    while(true)
    {
        alumno = new Alumno;

        // Separador de lineas
        cout << setw(120)  << setfill('=') << left << "=" << endl;

        cout << "DNI: ";
        cin >> alumno->DNI;

        if( alumno->DNI == 0) // terminamos el bucle infinito si el DNI es 0
            break;

        cout << "Nombre: ";
        cin >> alumno->nombre;

        cout << "Apellido: ";
        cin >> alumno->apellido;

        // Ingresamos las 3 calificaciones
        for(int i=0; i<NUMERO_DE_EXAMENES; i++)
        {
            cout << "Calificacion " << i + 1 << " :";
            cin >> alumno->calificaciones[i];
        }

        // Guardamos el alumno nuevo en el array
        alumnos.push_back(alumno);
        indiceDelAlumno++;
    }

    // IMPRIMIR LA INFORMACION

    cout << endl << endl;
    cout << setw(8)  << setfill(' ') << left << "DNI";
    cout << setw(20) << setfill(' ') << left << "Nombre";
    cout << setw(20) << setfill(' ') << left << "Apellido";
    cout << setw(20) << setfill(' ') << left << "Calificacion 1";
    cout << setw(20) << setfill(' ') << left << "Calificacion 2";
    cout << setw(20) << setfill(' ') << left << "Calificacion 3";
    cout << setw(10) << setfill(' ') << left << "Promedio" << endl;

    for(int i=0; i < alumnos.size(); i++)
    {
        // calculamos el promeido del alumno actual
        double promedio = calcularPromedio(alumnos[i]->calificaciones, NUMERO_DE_EXAMENES);

        if( promedio > mejorPromedio)
        {
            mejorPromedio = promedio;
            indiceAlumnoMejorPromedio = i;
        }

        cout << setw(8)  << setfill(' ') << left << alumnos[i]->DNI;
        cout << setw(20) << setfill(' ') << left << alumnos[i]->nombre;
        cout << setw(20) << setfill(' ') << left << alumnos[i]->apellido;
        cout << setw(20) << setfill(' ') << left << alumnos[i]->calificaciones[0];
        cout << setw(20) << setfill(' ') << left << alumnos[i]->calificaciones[1];
        cout << setw(20) << setfill(' ') << left << alumnos[i]->calificaciones[2];
        cout << setw(10) << setfill(' ') << left << promedio << endl;
    }
    cout << endl << endl
         <<"\tEl mejor promedio es de: "
         << alumnos[indiceAlumnoMejorPromedio]->nombre      << " "
         << alumnos[indiceAlumnoMejorPromedio]->apellido    << endl;

    // eliminar la memoria dinamica
    for( auto i : alumnos )
    {
        delete i;
    }

    return 0;
}

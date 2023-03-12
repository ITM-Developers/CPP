#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#endif

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#ifndef IOMANIP_H
#define IOMANIP_H
#include <iomanip>
#endif

#ifndef NODO_H
#define NODO_H

using namespace std;

template <class T>
class Nodo
{
private:
    bool DEBUGGIN_MODE = true;
    T value;          // El valor de tipo T asignado a este nodo
    vector<Nodo*> N;     // North Nodes, Parent Nodes
    vector<Nodo*> S;     // South Nodes, Child Nodes
    vector<Nodo*> E;     // East Nodes,  Right Nodes
    vector<Nodo*> W;     // West Nodes,  Left Nodes
public:
    Nodo();
    Nodo(T value);
    ~Nodo();
    Nodo<T>* addNode(T Nodo, char direction);
    void setValue(T value);
    T getValue();

    void print();
};

/**
 * ===============================================================================================
 * @brief Nodo::Nodo
 */
template <class T>
Nodo<T>::Nodo()
{

}

/**
 * ===============================================================================================
 * @brief Nodo::Nodo
 *
 * @param value
 * Es el valor que se le desea asignar al nodo.
 */
template <class T>
Nodo<T>::Nodo(T value)
{
    this->value = value;
}

/**
 * ===============================================================================================
 * @brief Nodo::~Nodo
 * El destructor se encarga de liberar toda la memoria que ha  sido  solicitada, en caso de que la
 * constante DEBUG este definida y tenga el valor booleano de true se mandara a imprimir en STDOUT
 * algunos mensajes que sirven para depurar el codigo con mas facilidad.
 */
template <class T>
Nodo<T>::~Nodo()
{
    for(size_t i = 0; i < this->N.size(); i++)
    {
        if(this->DEBUGGIN_MODE)
            cout << "[SUCCESS] Removing node of address" << this->N[i]
                 << " with value: "  << this->N[i]->getValue() << endl;
        delete this->N[i];
    }
    for(size_t i = 0; i < this->S.size(); i++)
    {
        if(this->DEBUGGIN_MODE)
            cout << "[SUCCESS] Removing node of address" << this->S[i]
                 << " with value: "  << this->S[i]->getValue() << endl;
        delete this->S[i];
    }
    for(size_t i = 0; i < this->E.size(); i++)
    {
        if(this->DEBUGGIN_MODE)
            cout << "[SUCCESS] Removing node of address" << this->E[i]
                 << " with value: "  << this->E[i]->getValue() << endl;
        delete this->E[i];
    }
    for(size_t i = 0; i < this->W.size(); i++)
    {
        if(this->DEBUGGIN_MODE)
            cout << "[SUCCESS] Removing node of address" << this->W[i]
                 << " with value: "  << this->W[i]->getValue() << endl;
        delete this->W[i];
    }
}

/**
 * ===============================================================================================
 * @brief Nodo::addNode
 * Agrega un Nodo
 * @param value
 * @param direction
 * @return
 */
template <class T>
Nodo<T>* Nodo<T>::addNode(T value, char direction)
{
    Nodo* newNode = new Nodo();   // Separamos espacio en memoria de manera dinamica para almacenar el nuevo nodo
    newNode->setValue(value);     // Copiamos el valor del Nodo en la posicion de memoria separado previamente

    if(this->DEBUGGIN_MODE)
        cout << "[SUCCESS] adding node in " << newNode << " with value "<< value << endl;

    switch (direction) {
    case 'N':
        this->N.push_back(newNode);
        break;
    case 'S':
        this->S.push_back(newNode);
        break;
    case 'W':
        this->W.push_back(newNode);
        break;
    case 'E':
        this->E.push_back(newNode);
        break;
    default:
        if(this->DEBUGGIN_MODE)
            cout << "[ERROR] No se puede agregar el nodo en la direccion especificad "
                 << "solo son validos (N,S,W,E)" << endl;
        return nullptr;
        break;
    }
    return newNode;
}

/**
 * ===============================================================================================
 * @brief Nodo::setValue
 * @param value
 */
template <class T>
void Nodo<T>::setValue(T value)
{
    this->value = value;
}

/**
 * ===============================================================================================
 * @brief Nodo::getValue
 * @return
 */
template <class T>
T Nodo<T>::getValue()
{
    return this->value;
}

/**
 * ===============================================================================================
 * @brief Nodo::print
 */
template <class T>
void Nodo<T>::print()
{
    // ---------- 10 chars
    // 0x7ffc4ade3aa0 14 chars

    cout << "Node Value: " << this->value << endl;
    cout << "+------------------------------------------------------------+\n";
    cout << "|                 Node Address: " << this << "               |\n";
    cout << "+------------------------------------------------------------+\n";
    cout << "| Direction | Memory Address | Value                         |\n";
    cout << "+------------------------------------------------------------+\n";

    // Imprimimos la tabla de nodos hijos que tiene este nodo
    for(size_t i = 0; i < this->N.size(); i++)
    {
        cout << "| North     | " << this->N[i] << " |";
        cout << " " << this->N[i]->getValue() << setw(31) << setfill(' ') << "|\n";
        cout << "+------------------------------------------------------------+\n";
    }
    for(size_t i = 0; i < this->S.size(); i++)
    {
        cout << "| South     | " << this->S[i] << " |";
        cout << " " << this->S[i]->getValue() << setw(31) << setfill(' ') << "|\n";
        cout << "+------------------------------------------------------------+\n";
    }
    for(size_t i = 0; i < this->E.size(); i++)
    {
        cout << "| East      | " << this->E[i] << " |";
        cout << " " << this->E[i]->getValue() << setw(31) << setfill(' ') << "|\n";
        cout << "+------------------------------------------------------------+\n";
    }
    for(size_t i = 0; i < this->W.size(); i++)
    {
        cout << "| West      | " << this->W[i] << " |";
        cout << " " << this->W[i]->getValue() << setw(31) << setfill(' ') << "|\n";
        cout << "+------------------------------------------------------------+\n";
    }
}
#endif // NODO_H

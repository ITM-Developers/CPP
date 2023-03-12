#ifndef PILA_H
#define PILA_H

template <class T>
class Pila
{
private:
    unsigned int sizeOfStack;
    T* stack;
public:
    Pila();
    ~Pila();
    bool isEmpty();
    unsigned int size();
    void push(T value);
    void clear();
    T& top();                       // PENDIENTE LA IMPLENETACION DE ESTE METODO
    void pop();
};

template <class T>
Pila<T>::Pila()
{
    this->stack = nullptr;           // Inicializamos el array a null
    this->sizeOfStack = 0;           // Inicializamos el tamano de la pila
}

template <class T>
bool Pila<T>::isEmpty()
{
    return (this->sizeOfstack == 0) ? true : false;
}

template <class T>
unsigned int Pila<T>::size()
{
    return this->sizeOfStack;
}

template <class T>
void Pila<T>::push(T value)
{
    if( this->stack == nullptr )
    {
        this->stack = new T[1];
        this->stack[0] = value;
        this->sizeOfStack = 1;
    }
    else
    {
        T* newStack = new T[ this->sizeOfStack + 1 ];
        T tmpValue;

        // Copiamos cada elemento de la pila actual a la nueva pila
        for(unsigned int i=0; i < this->sizeOfStack; i++)
        {
            tmpValue = this->stack[i];
            newStack[i] = tmpValue;
        }

        delete[] this->stack;                           // eliminamos la pila vijea de la memoria

        // actualizamos el puntero con la nueva direccion de memoria
        this->stack = newStack;

        this->stack[ this->sizeOfStack ] = value;       // copiamos el nuevo elemento a la pila
        this->sizeOfStack++;                            // actualizamos el contador de elementos
    }
}

template <class T>
void Pila<T>::clear()
{
    delete[] this->stack;
}

template <class T>
T& Pila<T>::top()
{
//    if( this->sizeOfStack > 0 )
//    {
//        T* topElement = this->stack[ this->sizeOfStack - 1 ];
//        return &topElement;
//    }
//    else
//    {
//        return nullptr;
//    }
}

template <class T>
void Pila<T>::pop()
{
    if( this->sizeOfStack > 0 )
    {
        T* newStack = new T[ this->sizeOfStack - 1 ];
        T tmpValue;

        // Copiamos cada elemento de la pila actual a la nueva pila
        for(unsigned int i=0; i < this->sizeOfStack - 1; i++)
        {
            tmpValue = this->stack[i];
            newStack[i] = tmpValue;
        }

        delete[] this->stack;                           // eliminamos la pila vijea de la memoria

        // actualizamos el puntero con la nueva direccion de memoria
        this->stack = newStack;
        this->sizeOfStack--;                            // actualizamos el contador de elementos
    }
}

template <class T>
Pila<T>::~Pila()
{
    this->clear();
}
#endif // PILA_H

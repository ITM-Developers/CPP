#include <stdio.h>
#include <limits.h>

int main()
{
    int numeros[5];
    int mayor = INT_MIN;
    int menor = INT_MAX;

    printf("Escribe los valores numericos separados por espacios: \n");

    for(int i=0; i<5; i++)
    {
        scanf("%i", &numeros[i]);

        // validamos cual es el numero mayor
        if( mayor < numeros[i] )
            mayor = numeros[i]

        // validamos cual es el nuemro menor
        if( menor > numeros[i] )
            menor = numeros[i];
    }

    printf("Mayor: %i\n", mayor);
    printf("Menor: %i\n", menor);
    
    return 0;
}
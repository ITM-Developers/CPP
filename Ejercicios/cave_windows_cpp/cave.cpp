#include "cave.h"


bool vis[5002];
int n, R[5002], D[5002];

void change( int i, int j ){
    for( ; i <= j; i++ )
        if( !vis[i] )
            R[i] = ( R[i] + 1 ) % 2;
}

void open( int i ){

    int s, ps, r, b, e, m;
    r = tryCombination( n, R );
    s = r > i || r == -1 ? 0 : 1;

    b = 0; e = n - 1;
    while( b != e ){
        m = (b + e) / 2;
        change( b, m );
        r = tryCombination( n, R );
        ps = r > i || r == -1 ? 0 : 1;
        change( b, m );
        if( ps != s )
            e = m;
        else
            b = m + 1;
    }

    D[b] = i;
    R[b] = s;
    vis[b] = 1;

}

void exploreCave(int N) {
	n = N;
	for( int i = 0; i < n; i++ )
        open( i );
    answer( n, R, D );
}

// Main
//	int tryCombination(int N, int S[])
//	void answer(int N, int S[], int D[])
/*
void exploreCave(int N) {
	// FIXME
	int combinacion[5000];
	int conexiones[5000];
	const int ALL_DOORS_OPEN = -1;
	const int DOWN 	= 0;
	const int UP 	= 1;

	// LIMPIAMOS EL GARBAGE DE LA MEMORIA
	for(int i=0;i<N;++i)
	{
		// INDICAMOS TODAS LAS PALANCAS ABAJO
		combinacion[i] = DOWN;
		// Y TODAS LAS CONEXIONES APUNTANDO A LA PUERTA 0
		conexiones[i]  = 0;
	}

    int indexClosedDoor     = 0;
    int indexCurrentSwitch  = 0;
    int lastDoorClosed = -1;

	while(indexClosedDoor != ALL_DOORS_OPEN)
	{
	    // MIENTRAS LA PUERTA ESTE CERRADA
	    while(lastDoorClosed != indexClosedDoor)
        {
            lastDoorClosed = tryCombination(N, combinacion);

            //
            if( lastDoorClosed == indexClosedDoor )
            {
                /
            }

        }
		indexClosedDoor =

		// SI EL INDICE DE LA PUERTA ABIERTA ES MAYOR QUE I
		if( ret > i)
		{
			// SIGNIFICA QUE LAS DEMAS COMBINACIONES ESTAN BIEN, LAS OMITIMOS
			// PARA AHORRA TIEMPO
			i = ret;
		}

		// COMO TODAS LAS COMBINACION YA ESTAN EN CERO SABEMOS QUE EL VALOR CORRECTO ES UP (1)
		combinacion[i] = UP;

	}

    // AL TERMINAR ESTE TENEMOS TODAS LAS PUERTAS ABIERTAS, AHORA ES MOMENTO DE SABER CUAL ESTA
	// CONCETADA CON CADA SWITCH, PARA ESTO DEBEMOS PROBRAR CADA UNO


	for(int i=0; i<N; ++i)
	{
		// INVERTIMOS EL ESTADO DEL SWITCH PARA CERRAR LA PUERTA Y SABER CUAL ES SU INDICE
		(combinacion[i] == DOWN) ? UP : DOWN;

		// AL ESTAR CERRADA LA PUERTA, LA FUNCION tryCombination NO DARA EL INDICE DE ESTA
		conexiones[i] = tryCombination(N, combinacion);
		// REVERTIMOS EL SWITCH A SU ESTADO ORIGINAL
		(combinacion[i] == DOWN) ? UP : DOWN;
	}

	answer(N, combinacion, conexiones);
}
*/

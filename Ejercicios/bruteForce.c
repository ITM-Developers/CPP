#include <stdio.h>
#include <stdlib.h>

void bruteValue(unsigned char *word, int wlen, int currentByte)
{
    // SI LLEGAMOS A 256 o FF
    if( word[currentByte] == 0xFF )
    {
        // REINICNIAMOS
        word[currentByte] = 0x00;

        // VALIDAMOS LOS LIMITES DE EL ARRAY
        if( currentByte < wlen )
        {
            // INCREMENETAMOS EL SIGUIENTE BYTE
            bruteValue( &word[0], wlen, currentByte + 1 );
        }
    }
    // SI NO
    else
    {
        // INCREMENTAR EN 1
        word[currentByte] += 1;
    }
}


int main()
{
    unsigned char bytes[4] = { 0x00, 0x00, 0x00, 0x00 };
    while( 1 )
    {
        bruteValue(&bytes[0], sizeof(bytes), 0);

        printf("%02X - %02X - %02X - %02X\n", bytes[0],bytes[1],bytes[2],bytes[3]);
        usleep(100000);
    }
    return 0;
}

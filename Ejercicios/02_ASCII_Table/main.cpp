#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int code;


    cout << setw(5)  << "Dec";
    cout << setw(5)  << "Char" << endl;
//    for( code = 32; code < 127; code++)
//    {
//        cout << setw(5) << dec << code;
//        cout << setw(5) << (char)code << endl;
//    }

    cout << "ASCII Extended" << endl;
    cout << setw(5)  << "Dec";
    cout << setw(5)  << "Char" << endl;
    for( code = 128; code < 255; code++)
    {
        cout << setw(5) << dec << code;
        cout << setw(5) << (char)code << endl;
    }
    getchar();
    return 0;
}

#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<vector>


#define N 10

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3


using namespace std;
string nombre, auxnombre, apellido, dui, anos, direc, respo, fami, paren;
int clave=0, auxclave=0;  
int edad;
char delito[10];
char opca;
bool encontrado = false;
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 void dibujarCuadro(int x1,int y1,int x2,int y2){
    int i;
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "-";
		gotoxy(i,y2); cout << "-";
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout << "|";
		gotoxy(x2,i); cout << "|";
    }
    
    gotoxy(x1,y1); cout << "|";
    gotoxy(x1,y2); cout << "|";
    gotoxy(x2,y1); cout << "|";
    gotoxy(x2,y2); cout << "|";
}
void agregando(){
    ///Variables de la biblioteca fstream para el manejo de archivos
    ofstream escritura;
    ifstream consulta;

    do{
    escritura.open("alumnos.txt", ios::out | ios::app);//crea y escribe, si ya tiene texto une al final del archivo
    consulta.open("alumnos.txt", ios::in);//solamente consulta o lee usando la variable sobre el archivo físico alumnos.txt

    if (escritura.is_open() && consulta.is_open()){


            bool repetido=false;
            
            cout<<"                S I S T E M A  D E  C O M I S E R I A"<<endl<<endl;
			dibujarCuadro(1,1,115,28);//Cuadro grande
		    dibujarCuadro(2,2,113,4);//Cuadro del titulo
		     
            cout<<"\n";
            cout<<"\tIngresa el codigo:    ";
            cin>>auxclave;
        
            
            ///A continuación se aplica el tipo de lectura de archivos secuencial
            consulta>>clave;
            while (!consulta.eof()){
                consulta>>nombre>>apellido>>delito>>edad;
                if (auxclave==clave){
                    cout<<"\t\tYa existe la clave del reo...\n";
                    repetido=true;
                    break;
                }
                consulta>>clave;
            }

            if (repetido==false){
                cout<<"\tIngresa el nombre del detenido:   ";
                cin>>nombre;
                fflush(stdin);
                cout<<"\tIngresa el apellido del detenido: ";
                cin>>apellido;
                fflush(stdin);
                 cout<<"\tIngrese la direccion del detenido:     ";
                cin>>direc;
                fflush(stdin);
                
                cout<<"\tIngresa la edad del detenido:    ";
                cin>>edad;
                if(edad>=10&&(edad<18))
				{
			cout<<"usted es menor de edad por tanto: Sera transferido a un penal de menoridad";
			cout<<"\tIngrese el responsable del menor de edad:     ";
                cin>>respo;
                fflush(stdin);
			
			
		}
		else{
			cout<<"el reo es mayor de edad";
			cout<<"\tIngrese el dui del detenido:     ";
                cin>>dui;
                fflush(stdin);
		}
                fflush(stdin);
                cout<<"\tIngrese un nombre de un familiar:     ";
                cin>>fami;
                fflush(stdin);
                cout<<"\tIngrese su padentesco:     ";
                cin>>paren;
                fflush(stdin);
                cout<<"\tIngrese el delito que cometio:     ";
                cin>>delito;
                fflush(stdin);
                 cout<<"\tIngrese los años que pasara en pricion:     ";
                cin>>anos;
                fflush(stdin);
                
                
                //ESCRIBIENDO LOS DATOS CAPTURADOS POR EL USUARIO EN EL ARCHIVO
                escritura<<auxclave<<" "<<nombre<<" "<<apellido<<" "<<direc<<" "<<edad<<" "<<respo<<" "<<dui<<" "<<fami<<" "<<paren<<" "<<delito<<" "<<anos<<endl;
                cout<<"\n\tRegistro agregado...\n";
            }

            cout<<"\n\tDeseas ingresar otro detenido? (S/N): ";
            cin>>opca;

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }

    escritura.close();
    consulta.close();

    }while (opca=='S' or opca=='s');

}
void eliminarRegistro()
{
	cout<<"                           S I S T E M A  D E  C O M I S E R I A"<<endl<<endl;
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tIngresa la clave del alumno que deseas eliminar: ";
        cin>>auxclave;
            
            ///De nuevo se aplica el tipo de lectura de archivos secuencial, esto quiere decir que lee campo por campo hasta
            ///hasta llegar al final del archivo gracias a la función .eof()
            lectura>>clave;
            while (!lectura.eof()){
                lectura>>nombre>>apellido>>delito>>edad;
                if (auxclave==clave){
                        encontrado=true;
                        cout<<"\n";
                        cout<<"\tClave:    "<<clave<<endl;
                        cout<<"\tNombre:   "<<nombre<<endl;
                        cout<<"\tApellido: "<<apellido<<endl;
                        cout<<"\tdelito:    "<<delito<<endl;
                        cout<<"\tEdad:     "<<edad<<endl;
                        cout<<"\t________________________________\n\n";
                        cout<<"\tRealmente deseas eliminar el registro actual (S/N)? ---> ";
                        cin>>opca;

                        if (opca=='S' or opca=='s'){
                            cout<<"\n\n\t\t\tRegistro eliminado...\n\n\t\t\a";
                        }else{
                            aux<<clave<<" "<<nombre<<" "<<apellido<<" "<<delito<<" "<<edad<<endl;
                        }

                    }else{
                        aux<<clave<<" "<<nombre<<" "<<apellido<<" "<<delito<<" "<<edad<<endl;
                    }
                lectura>>clave;
            }
    }else{
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }

    if (encontrado==false){
                cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
            }

    aux.close();
    lectura.close();
    remove ("alumnos.txt");
    rename("auxiliar.txt", "alumnos.txt");
}


void verRegistro()
{
	
	 cout<<"                           S I S T E M A  D E  C O M I S E R I A"<<endl<<endl;
    //Lectura de archivos

    ifstream lectura;
    lectura.open("alumnos.txt", ios::out | ios::in);//CREA, ESCRIBE O LEE
    if (lectura.is_open()){
       //LEYENDO Y MOSTRANDO CADA CAMPO DEL ARCHIVO DE FORMA SECUENCIAL
       lectura>>clave;
       while (!lectura.eof()){
            lectura>>nombre>>apellido>>delito>>edad;
            cout<<"\n";
            cout<<"\tClave:    "<<clave<<endl;
            cout<<"\tNombre:   "<<nombre<<endl;
            cout<<"\tApellido: "<<apellido<<endl;
            cout<<"\tDelito:    "<<delito<<endl;
            cout<<"\tEdad:     "<<edad<<endl;
            lectura>>clave;
            cout<<"\t________________________________\n";
       }

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close();
}

void buscar()
{
	 cout<<"                                 S I S T E M A  D E  C O M I S E R I A"<<endl<<endl;
    ifstream lectura;
    lectura.open("alumnos.txt", ios::out );

    encontrado=false;

    if (lectura.is_open()){
        cout<<"\n\tIngresa el codigo que se le asigno: ";
        cin>>auxclave;

        lectura>>clave;
        while(!lectura.eof()){
            lectura>>nombre>>apellido>>delito>>edad;
        //comparar cada registro para ver si es encontrado

        if(auxclave==clave){
            cout<<"\n";
            cout<<"\tClave:    "<<clave<<endl;
            cout<<"\tNombre:   "<<nombre<<endl;
            cout<<"\tApellido: "<<apellido<<endl;
            cout<<"\tDelito:    "<<delito<<endl;
            cout<<"\tEdad:     "<<edad<<endl;
            cout<<"\t________________________________\n";
            encontrado=true;
            break;
        }//fin del if mostrar encontrado

        //lectura adelantada
        lectura>>clave;
        }//fin del while
        if (encontrado==false){
            cout<<"\n\n\tNo hay registros con la clave: "<<auxclave<<"\n\n\t\t\t";
        }
    }else{
        cout<<"\n\tAun no se pudo abrir el archivo...";
    }

    lectura.close();
}


void modificar()
{
	 cout<<"                             S I S T E M A  D E  C O M I S E R I A"<<endl<<endl;
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("alumnos.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\n";
        cout<<"\tIngrese el codigo de la persona que deseas modificar: ";
        cin>>auxclave;

            lectura>>clave;
            while (!lectura.eof()){
                lectura>>nombre>>apellido>>apellido>>delito>>edad;
                if (auxclave==clave){
                    encontrado=true;
                    cout<<"\n";
                    cout<<"\tClave:    "<<clave<<endl;
                    cout<<"\tNombre:   "<<nombre<<endl;
                    cout<<"\tApellido: "<<apellido<<endl;
                    cout<<"\tDelito:    "<<delito<<endl;
                    cout<<"\tEdad:     "<<edad<<endl;
                    cout<<"\t________________________________\n\n";
                    cout<<"\tIngresa el nuevo nombre de la persona con el codigo: "<<auxclave<<"\n\n\t---> ";
                    cin>>auxnombre;

                    aux<<clave<<" "<<auxnombre<<" "<<apellido<<" "<<delito<<" "<<edad<<endl;
                    cout<<"\n\n\t\t\tRegistro modificado...\n\t\t\a";
                    }else{
                    aux<<clave<<" "<<nombre<<" "<<apellido<<" "<<delito<<" "<<edad<<endl;
                    }
                lectura>>clave;
            }
    }else{
        cout<<"\n\tEl archivo no se pudo abrir \n";
    }

    if (encontrado==false){
                cout<<"\n\tNo se encontro ningun registro con la clave: "<<auxclave<<"\n\n\t\t\t";
            }

    aux.close();
    lectura.close();
    remove ("alumnos.txt");
    rename("auxiliar.txt", "alumnos.txt");
}
int menu()
{
    system ("color f4");
    int opc;

    do{
    system("cls");
	int x;
	
	gotoxy(29,3); 
        cout<<"         S I S T E M A  D E  C O M I S E R I A"<<endl;
			dibujarCuadro(1,1,115,28);//Cuadro grande
		    dibujarCuadro(2,2,113,4);//Cuadro del titulo
		    gotoxy(29,6); 
        cout << "\t\t\tMENU PRINCIPAL" << endl;
        gotoxy(29,7); 
   cout << "\t\t\t----------------" << endl;
   
	gotoxy(4,9); 
	cout<<"\n\t1.-Agregar Registro"<<endl;
    gotoxy(4,11);
	cout<<"\n\t2.-Eliminar Registro"<<endl;
	gotoxy(4,13);
	cout<<"\n\t3.-Ver Registro"<<endl;
	gotoxy(4,15);
	cout<<"\n\t4.-Buscar Registro"<<endl;
	gotoxy(4,17);
	cout<<"\n\t5.-Modificar Datos "<<endl;
gotoxy(4,19);
	cout<<"\n\t6.-Salir "<<endl;

	cout<<"\n\tOpcion: ";

    cin>>opc;
    switch (opc)
    {
case 1:{
    system("cls");
    agregando();
    cout<<"\n\t\t";
    system ("pause");
    break;
}
case 2:{
    system("cls");
    eliminarRegistro();
    cout<<"\n\t\t";
    system ("pause");
    break;
}

case 3:{
    system("cls");
    verRegistro();
    cout<<"\n\t\t";
    system ("pause");
    break;
}
case 4:{
    system("cls");
    buscar();
    cout<<"\n\t\t";
    system ("pause");
    break;
}
case 5:{
    system("cls");
    modificar();
    cout<<"\n\t\t";
    system ("pause");

    break;
}
case 6:{
    cout<<"\n\n\tHa elegido salir...\n\n\t\t"; system ("pause");
    break;
}
default:{
    cout<<"\n\n\tHa elegido una opcion inexistente...\n\n\t\t"; system ("pause");
    break;
}
    }//fin switch

    }while (opc!=6);

    system("cls");

    

}
int main(){ 
	vector<string> usuarios;
    vector<string> claves;

    // Se añaden usuarios al vector
    usuarios.push_back("luis");
    usuarios.push_back("dany");
    usuarios.push_back("jorge");
    usuarios.push_back("miguel");
    usuarios.push_back("jesus");

    // Se añaden claves al vector
    claves.push_back("123"); //luis
    claves.push_back("456"); //daniel
    claves.push_back("789"); //Jose
    claves.push_back("abc"); //carlos
    claves.push_back("efg"); //jesus

    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        gotoxy(29,3); 
        cout<<"         S I S T E M A  D E  C O M I S E R I A"<<endl;
			dibujarCuadro(1,1,115,28);//Cuadro grande
		    dibujarCuadro(2,2,113,4);//Cuadro del titulo
		    gotoxy(29,6); 
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        gotoxy(29,7); 
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
        return 0;
        
    }
    else
    {
        cout << "\n\n\tBienvenido al sistema" << endl;
        
    }

    cin.get(); 
	
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		system("cls");
		op=menu();
		switch(op){
			case 1:
			 agregando();
			break;
			case 2:
			 eliminarRegistro();	
			break;
			case 3:
			verRegistro();
			break;
			case 4:
			buscar();
			break;
			case 5:
				 modificar();
			break;
		}
	}while(op!=5);
 
	return 0;
}

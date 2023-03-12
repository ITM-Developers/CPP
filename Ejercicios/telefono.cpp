#include<iostream>
#include<stdlib.h>
#include<fstream>  
using namespace std;

void escribirFrases();

int main(){
	escribirFrases();
	
	system("pause");
	return 0;
} 

void escribirFrases(){
	ofstream archivo;
	string nombreArchivo,clave, nombre,apellido,edad,dui,anos,direc,respo,fam9i,paren;
	char rpt;
	
	cout<<"Digite el nombre del archivo: ";
	getline(cin,nombreArchivo);
	
	archivo.open(nombreArchivo.c_str(),ios::out); //Creamos el archivo
	
	if(archivo.fail()){ //Si a ocurrido algun error
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	do{
		fflush(stdin);
		cout<<"Digite una frase: ";
		getline(cin,clave);
		archivo<<clave<<endl;
		fflush(stdin);
		cout<<"Digite su nombre: ";
		getline(cin,nombre);
		archivo<<nombre<<endl;
		cout<<"Digite su apellido: ";
		getline(cin,apellido);
		archivo<<apellido<<endl;
		cout<<"Digite su edad: ";
		getline(cin,edad);
		archivo<<edad<<endl; 
	
		
		
		cout<<"\nDesea agregar otra frase(S/N): ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));
	
	archivo.close(); //Cerramos el archivo
}

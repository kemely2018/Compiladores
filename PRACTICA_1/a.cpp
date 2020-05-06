/*
   a)	Leer toda una instrucción por consola (Ejemplo: "int temp;") y mostrar en
        pantalla letra por letra.
*/

#include <iostream>
using namespace std;
int main( )
{
    char palabra[]="int temp;";//una cadena que contiene la instrucción 
    int tam = sizeof(palabra) / sizeof(palabra[0]); 
    for(int i=0;i<tam;i++){
    	if(palabra[i]!=' '){//eliminalos espacios blancos 
      		cout<<palabra[i]<<endl;
		}
	}
    return 0;
}

/* d)	Leer un archivo de texto plano, letra por letra hasta encontrar 
        un separador (espacio, tabulador o salto de línea) y mostrar en 
		pantalla si el vocablo se trata de un número entero, una palabra 
		o un carácter especial ("+","- "," *"," /")
		Archivos externos utilizados : 
		            - texto.txt
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

fstream archivo;
void leerArchivo(){
	archivo.open("texto.txt",ios::in);
	if(archivo.is_open()){
		string linea;
		while(getline(archivo,linea,' ')){
			int c=linea.size();
			if(linea[c-1]>=48 && linea[c-1]<=57){
				cout<<linea<<" = numero"<<endl;
			}
			else if(linea[c-1]>=65 && linea[c-1]<=90){
				cout<<linea<<" = palabra"<<endl;
			}	
			else if(linea[c-1]>=97 && linea[c-1]<=122){
				cout<<linea<<" = palabra"<<endl;
			}
			else{
				cout<<linea<<" = caracter especial "<<endl;
			}	
		}
		archivo.close();
	}
	else{
		cout<<"No se encuentra el archivo";
	}
}

int main(){
	leerArchivo();
	return 0;
}

/* b)	Leer un archivo de texto plano (archivo con un pseudocódigo) y 
        muestre en pantalla letra por letra. 
	   	Archivos externos utilizados : 
		    - datos.txt
*/

#include <iostream>
#include <fstream>
using namespace std;

fstream archivo;

void leerArchivo(){
	archivo.open("datos.txt",ios::in);
	if(archivo.is_open()){
		char cadena;
		while(!archivo.eof()){
			archivo >> cadena;
			cout<<cadena<<endl;
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


/*SEGUNDA FORMA
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

fstream archivo;
void leerArchivo(){
	archivo.open("datos.txt",ios::in);
	if(archivo.is_open()){
		string linea;
		while(getline(archivo,linea)){
			int c=linea.size();
			for(int i=0;i<c;i++){
				if (linea[i]!=' '){
				    cout<<linea[i]<<endl;	
				}
			}
			//cout<<linea<<endl;
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
}*/

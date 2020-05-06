/*   c)	Crear un programa que cifre un pseudocódigo y otro que lo descifre, 
       según la técnica del cifrado de César. El seudocódigo se encuentra en 
	   un archivo de texto plano. El cifrado de César consiste en mover cada 
	   letra un determinado número de espacios en el alfabeto (puede ser 3 espacios).
	   		Archivos externos utilizados : 
		            - cifrar.txt
		            - descifrar.txt
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

fstream archivo;
fstream archive;
void cifrar(){
	archivo.open("cifrar.txt",ios::in);
	archive.open("descifrar.txt",ios::out);
	if(archivo.is_open()){
		string linea,salida_texto;
		int clave,aux,tam;
		while(getline(archivo,linea)){
			tam=linea.size();
			clave=3;
			for(int i=0;i<tam;i++){
				aux=linea[i];
				aux=aux+clave;
				if(linea[i]!=' '){
					linea[i]=aux;             
		        }
			}
			
			if(archive.is_open()){
				string salida_texto;
				salida_texto += linea +'\n';
				archive<<salida_texto;
			}
			
			cout<<linea<<endl;
		}
		archivo.close();
		archive.close();
	}
	else{
		cout<<"No se encuentra el archivo";
	}
	
}

void descifrar(){
	archivo.open("descifrar.txt",ios::in);
	if(archivo.is_open()){
		string linea;
		int clave,aux,tam;
		while(getline(archivo,linea)){
			tam=linea.size();
			clave=3;
			for(int i=0;i<tam;i++){
				aux=linea[i];
				aux=aux-clave;
				if(linea[i]!=' '){
					linea[i]=aux;             
		        }
			}
			cout<<linea<<endl;
		}
		archivo.close();
	}
	else{
		cout<<"No se encuentra el archivo";
	}
	
}
int main(){
	cout<<"\n---     Cifrado    ----\n"<<endl;
	cifrar();
	cout<<"\n---    Descifrado    ----\n"<<endl;
	descifrar();
	return 0;
}

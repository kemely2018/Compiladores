/* SIN TXT */
/* d)La solución 2, puede ser automatizada, teniendo como dato de entrada la tabla de transiciones. 
Defina el formato de la tabla de transición y en un archivo de texto plano represente 
la respectiva tabla (considere el diagrama del ejercicio C). 
Finalmente, en base al archivo de texto plano, determine la validez de una entrada.*/
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

enum class Estado {Q1,Q2,Q3,Q4,Q5,ERROR,ACEPTAR};
enum class Simbolo{punto,menos,digito,FDC};

void reconocerIdentificador(string& inputString,string tabla[][4])
{
	int pos = 0;
	Estado actual = Estado::Q1;
	Simbolo entrada;
	string state;
	bool rutinaDeError = false;
	while (rutinaDeError == false){
		char palabra = inputString[pos];
		if (palabra == 46)
			entrada = Simbolo::punto;
		else if (palabra ==45)
			entrada = Simbolo::menos;
		else if (isdigit(palabra))
			entrada = Simbolo::digito;
		else if (pos >= inputString.length())
			entrada = Simbolo::FDC;	
		else
		    rutinaDeError = true; 
		    
       
		state=tabla[(int)actual][(int)entrada];
		if(state == "2"){
			actual = Estado::Q2;
		}
		else if(state == "3"){
			actual = Estado::Q3;
		}
		else if(state == "4"){
			actual = Estado::Q4;
		}
		else if(state == "5"){
			actual = Estado::Q5;
		}
		else if(state == "error"){
			rutinaDeError = true;	
		}
		else if(state == "aceptar"){
			cout<<"Si acepta el identificador";	
			break;
		}
		pos++;
	}
    if (rutinaDeError) {
        cout<<"No acepta el identificador";
    }

}
		
int main() {
	string tabla[5][4]={{"2","2","3","error"},
	                    {"4","error","3","error"},
						{"4","error","3","aceptar"},
						{"error","error","5","error"},
						{"error","error","5","aceptar"}};
	while(true){
    cout << "Identificador :" << endl;
    string inputString;
    cin >> inputString;
    reconocerIdentificador(inputString,tabla);
    cout << "\n" << endl;
	}
    return 0;
}

/* CON TXT */
/*
#include <iostream>
#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>


using namespace std;

enum class Estado {Q1,Q2,Q3,Q4,Q5,ERROR,ACEPTAR};
enum class Simbolo{punto,menos,digito,FDC};

void reconocerIdentificador(string& inputString,string tabla[][5])
{
	int pos = 0;
	Estado actual = Estado::Q1;
	Simbolo entrada;
	string state;
	bool rutinaDeError = false;
	while (rutinaDeError == false){
		char palabra = inputString[pos];
		if (palabra == 46)
			entrada = Simbolo::punto;
		else if (palabra ==45)
			entrada = Simbolo::menos;
		else if (isdigit(palabra))
			entrada = Simbolo::digito;
		else if (pos >= inputString.length())
			entrada = Simbolo::FDC;	
		else
		    rutinaDeError = true; 
		    
        cout<<(int)actual<<(int)entrada<<endl;
        
		state=tabla[(int)actual][(int)entrada];
		if(state == "2"){
			actual = Estado::Q2;
		}
		else if(state == "3"){
			actual = Estado::Q3;
		}
		else if(state == "4"){
			actual = Estado::Q4;
		}
		else if(state == "5"){
			actual = Estado::Q5;
		}
		else if(state == "error"){
			rutinaDeError = true;	
		}
		else if(state == "aceptar"){
			cout<<"Si acepta el identificador";	
			break;
		}
		pos++;
	}
    if (rutinaDeError) {
        cout<<"No acepta el identificador";
    }

}
		
int main() {
	string tabla[6][5];
	ifstream myfile("matriz.txt",ios::in);
	if(!myfile){
		cerr << "File not Read"<< endl;
		exit( 1 );	
	}
    for(int i=0;i<6;++i){
     	for(int j=0;j<5;++j){
	    	myfile>>tabla[i][j];
	    }
	}
	
	myfile.close();
	
    cout << "Identificador :" << endl;
    string inputString;
    cin >> inputString;
    reconocerIdentificador(inputString,tabla);
    cout << "\n" << endl;

    return 0;
}*/

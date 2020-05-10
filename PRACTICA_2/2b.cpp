/* b)Implemente, el algoritmo por tablas de transición para el reconocimiento de un identificador.*/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

enum class Estado {Q1, Q2, Q3,ERROR,ACEPTAR};
enum class Simbolo{digito,letra,FDC};

void reconocerIdentificador(string& inputString,string tabla[][3])
{
	int pos = 0;
	Estado actual = Estado::Q1;
	Simbolo entrada;
	string state;
	bool rutinaDeError = false;
	while (rutinaDeError == false){
		char palabra = inputString[pos];
		if (isdigit(palabra))
			entrada = Simbolo::digito;
		else if (isalpha(palabra))
			entrada = Simbolo::letra;
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
	string tabla[3][3]={{"2","3","error"},
	                    {"error","error","error"},
						{"3","3","aceptar"}};
    cout << "Identificador :" << endl;
    string inputString;
    cin >> inputString;
    reconocerIdentificador(inputString,tabla);
    cout << "\n" << endl;
    return 0;
}

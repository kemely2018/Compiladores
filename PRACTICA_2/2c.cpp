/* c) Proponga un diagrama de transición y su correspondiente 
programa para el reconocimiento de números (Ejemplo: 45,-45, 0.15,-0.15,.67,-.67)*/

#include <iostream>
#include <cctype>
using namespace std;

enum class Estado {Q0, Q1, Q2, Q3,Q4, NO_RECONOCIDO};

Estado reconocerNumero(const string& inputString)
{
    unsigned int pos = 0;
    Estado actual = Estado::Q0;
    bool cadenaRechazada = false;
    while (cadenaRechazada == false and pos < inputString.length()) {
        char simbolo = inputString[pos];
        switch (actual) {
        case Estado::Q0:
            if (isdigit(simbolo)) {
                actual = Estado::Q2	;
            } else if (simbolo  == '-' or simbolo == '.') {
                actual = Estado::Q1;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q1:
            if (isdigit(simbolo)) {
                actual = Estado::Q2;
            } else if (simbolo == '.') {
                actual = Estado::Q3;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q2:
            if (isdigit(simbolo)) {
                actual = Estado::Q2;
            } else if (simbolo == '.') {
                actual = Estado::Q3;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q3:
            if (isdigit(simbolo)) {
                actual = Estado::Q4;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q4:
            if (isdigit(simbolo)) {
                actual = Estado::Q4;
            } else {
                cadenaRechazada = true;
            }
            break;
        }
        pos++;
    }
    if (cadenaRechazada) {
        return Estado::NO_RECONOCIDO;
    }
    return actual;
}

int main() {
	while(true){
	
    cout << "Programa que reconoce numeros :" << endl;
    string inputString;
    cin >> inputString;
    Estado ultimo = reconocerNumero(inputString);
    if (ultimo == Estado::Q2 ) {
        cout << "Cadena ingresada SI aceptada" << endl;
    } else if (ultimo == Estado::Q4) {
        cout << "Cadena ingresada SI aceptada" << endl;
    } else {
        cout << "Cadena ingresada NO aceptada" << endl;
    }
    cout << endl;
    }
    return 0;
}


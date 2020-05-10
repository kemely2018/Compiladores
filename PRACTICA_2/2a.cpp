/* a)Implemente el algoritmo por diagramas de transición para el reconocimiento de un identificador.*/

#include <iostream>
#include <cctype>
using namespace std;

enum class Estado {OF, Q1, Q2, Q3,NO_RECONOCIDO};
Estado reconocerIdentificador(string& inputString)
{
    int pos = 0;
    Estado actual = Estado::Q1;
    bool rutinaDeError = false;
    while (rutinaDeError == false and pos < inputString.length()) {
        char simbolo = inputString[pos];
        switch (actual) {
        case Estado::Q1:
            if (isdigit(simbolo)) {
                actual = Estado::Q2;
            } else if ( isalpha(simbolo)) {
                actual = Estado::Q3;
            } else {
                rutinaDeError = true;
            }
            break;
        case Estado::Q2:
            rutinaDeError = true;
            break;
        case Estado::Q3:
            if (isalpha(simbolo)) {
                actual = Estado::Q3;
            } else if (isdigit(simbolo) ){
                actual = Estado::Q3;
            } else {
                rutinaDeError = true;
            }
        }
        pos++;
    }
    if (rutinaDeError) {
        return Estado::NO_RECONOCIDO;
    }
    return actual;
}

int main() {
while(true){

    cout << "Identificador :" << endl;
    string inputString;
    cin >> inputString;
    Estado ultimo = reconocerIdentificador(inputString);
    if (ultimo != Estado::Q3) {
        cout << "NO se reconoce el identificador :)" << endl;
    } 
	else {
        cout << "SI se reconoce el identificador :(" << endl;
    }
    cout << "\n" << endl;
}

    return 0;
}

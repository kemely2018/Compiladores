#include<iostream>
#include<stack>
#include<string>
#include <fstream>
using namespace std;

bool EsOperando(char C) {
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

bool EsOperador(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/' )
		return true;

	return false;
}

int GetOperatorWeight(char op){
	int weight = -1; 
	switch(op){
		case '+':
		case '-':
			weight = 1;
		case '*':
		case '/':
			weight = 2;
	}
	return weight;
}
string InfixToPostfix(string linea){
    stack<char> PILA;
	string postfix = ""; 
	for(int i = 0;i< linea.length();i++) {

		if(EsOperador(linea[i])) 
		{
			while(!PILA.empty() && PILA.top() != '(' )
			{
				postfix+= PILA.top();
				PILA.pop();
			}
			PILA.push(linea[i]);
		}

		else if(EsOperando(linea[i]))
		{
			postfix +=linea[i];
		}

		else if (linea[i] == '(') 
		{
			PILA.push(linea[i]);
		}

		else if(linea[i] == ')') 
		{
			while(!PILA.empty() && PILA.top() !=  '(') {
				postfix += PILA.top();
				PILA.pop();
			}
			PILA.pop();
		}

	}

	while(!PILA.empty()) {
		postfix += PILA.top();
		PILA.pop();
	}

	return postfix;
}

int main() 
{
	ifstream archivo;
	archivo.open("programa1.txt",ios::in); 	
	string linea; 
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	while(!archivo.eof()){ 
		getline(archivo,linea);
		string postfix = InfixToPostfix(linea);
		if(postfix=="INICIO"||postfix== "FIN"){}
		else{
			cout<<"Salida : "<<postfix<<"\n";
		}	
	}
	archivo.close(); 
}

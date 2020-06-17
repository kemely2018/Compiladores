#include <iostream>
#include <vector>
#include<string>
#include <fstream>
#include <sstream>
using namespace std;

void mostrar(vector<string> vc)
{
  for(int i = 0; i < vc.size(); i++)
  {
    if(vc.at(i) != "(" || vc.at(i) != ")")
      cout << vc.at(i) << " ";
  }
  cout << "\n";
}

int Prev(char c)
{
  if(c == '*' || c == '/')
    return 2;
  if(c == '+' || c == '-')
    return 1;
}

bool isOperator(string c)
{
  return c == "+" || c == "-" || c == "*" || c == "/";
}

bool isOperator(char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isOperand(string c)
{
  if(!(isOperator(c)))
    return (c != ")") && (c != "(");
  return false;
}

int signo(char c, int a, int b)
{
  switch(c)
  {
    case '+':
      return (a + b);
    case '-':
      return (a - b);
    case '*':
      return (a * b);
    case '/':
      return (a / b);
  }
}

int postfixValor(vector<string> postfixes)
{
  vector<int> operands;
  int a = 0, b = 0, c = 0;
  for(int i = 0; i < postfixes.size(); i++)
  {
    if(isOperand(postfixes[i]))
      operands.push_back(std::stoi(postfixes[i]));
    else
    if(operands.size()>1)
    {
      b = operands.back();
      operands.pop_back();
      a = operands.back();
      operands.pop_back();
      c = signo(postfixes[i][0], a, b);
      operands.push_back(c);
    }
  }
  return operands[0];
}

vector<string> convertir(vector<string> infix)
{
  vector<string> O;
  vector<string> P;

  for(int i = 0; i < infix.size(); i++)
  {
    if(isOperand(infix[i]))
      P.push_back(infix[i]);

    else if(infix[i] == "(")
    {
      O.push_back(infix[i]);
    }

    else if(infix[i] == ")")
    {
      while(!O.empty() && O.back()[0] !=  '(')
      {
        P.push_back(string(1, O.back()[0]));
        O.pop_back();
      }
      O.pop_back();
    }

    else if(isOperator(infix[i]))
    {
      while (!O.empty() && O.back()[0] != '(' && Prev(O.back()[0]) >= Prev(infix[i][0]))
      {
        P.push_back(string(1, O.back()[0]));
        O.pop_back();
      }
      O.push_back(infix[i]);
    }
  }

  while (O.size()!=0)
  {
    P.push_back(string(1, O.back()[0]));
    O.pop_back();
  }
  return P;
}

vector<string> token(string str)
{
  string tempstr="";
  vector<string> vc;
  
  for(int i = 0; i < str.length(); i++)
  {
    if(str[i]==' ')
      continue;
    if(str[i]=='('||str[i]==')')
    {
      tempstr = str[i];
      vc.push_back(tempstr);
      tempstr = "";
      continue;
    }

    if(isOperator(str[i]))
    {
      tempstr = "";
      tempstr += str[i];
      vc.push_back(tempstr);
      tempstr = "";
    }
    
    else
    {
      while(i < str.length())
      {
        tempstr += str[i];
        i++;
        if(isOperator(str[i])||str[i]=='('||str[i]==')')
        {
          i--;
          break;
        }
      }
      vc.push_back(tempstr);
      tempstr = "";
    }
  }
  return vc;
}

int main() 
{
	ifstream archivo;
	archivo.open("programa1.txt",ios::in); 	
	string l; 
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	while(!archivo.eof()){ 
		getline(archivo,l);
		stringstream   stream(l);
		string linea;
		while(getline(stream,linea,';')){
			string s = linea;
		    if(s=="INICIO"||s== "FIN"){}
		    else{
		    	cout<<"INFIJA:      ";
		    	mostrar(token(s));
		    	cout<<"POSTFIJA:    ";
			mostrar(convertir(token(s)));
			cout <<"RESULTADO:   "<<postfixValor(convertir(token(s)))<<endl;	
		    }			
		}
		cout << "\n";
	
	}
	archivo.close(); 
	return 0;
}

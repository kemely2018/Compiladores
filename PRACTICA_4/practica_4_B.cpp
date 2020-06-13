#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int preanalisis;

void parea(int);
void Exp();
void Term();
void Resto();
void error();

void Exp()
{
    Term();
    Resto();
}

void Resto()
{
    if (preanalisis == '+'){
        parea('+');
        Term();
        printf("+");
        Resto();
    }
    else if (preanalisis=='-'){
        parea('-');
        Term();
        printf("-");
        Resto();
    }
    else;
}

void Term()
{
    if(isdigit(preanalisis)){
    	printf("%c ",preanalisis);
        parea(preanalisis);
    }
    else
        error();
}
void error()
{
    printf("Error de sintaxis");
}
void parea(int t)
{
    if (preanalisis==t)
        preanalisis=getchar();
    else
        error(); 
}
int main()
{
    cout<< "Expresion: ";
    preanalisis=getchar(); 
    Exp();
    return 0;
}

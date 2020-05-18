#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>

#define MAYOR '>'
#define MENOR '<'
#define IGUAL '='
#define MAS '+'
#define MENOS '-'
#define MULTI '*'
#define DIVI '/'
#define PUNTOYCOMA ';'
#define COMA ','
#define PARI '('
#define PARD ')'
#define CORI '['
#define CORD ']'
#define LLAVEI '{'
#define LLAVED '}'
#define DIFE '!='



enum TokenTipo{
    WHILE,IF,ELSE,RETURN,FOR,INT,CHAR,STRING,MAIN, //PALABRA RESERVADAS
    ID,NUM,// id
    MAYORIGUAL,MENORIGUAL,IGUALIGUAL,
} ;

using namespace std;
int scaner();
void mostrar(int);
int espalres();

FILE *f;
char lexema[80];

int main( ){
	int token;
	f=stdin;
    f=fopen("inpt.txt","rt"); 
        if(f==NULL){
        	f=stdin;
		
	}      
	if(f==stdin) {//la lectura sera desde la entrada estandar
			printf("Ingrese texto ........ termine con Ctrl z \n");
	}
	while(1){
		token=scaner();
        if(token==EOF)break;
        mostrar(token);
	}
	if(f !=stdin){
		fclose(f); 
	} 

}

int scaner(){
		int c;
        int i;
        do c=fgetc(f); while(isspace(c)); 
        
        if(c==EOF) return EOF;
        if(isalpha(c)){//regla del ID
        	i=0;
        	do{
        		lexema[i++]=c;
        		c=fgetc(f);
			}while(isalnum(c)||c=='_');
			lexema[i]=0;
			ungetc(c,f); //se devuelve c al flujo de entrada
			i=espalres(); // verifica si es palabra reservada
                          // WHILE , IF
            if(i>=0){
            	return i; 
			} 
			return ID; // se trata de un ID           
		}
		
		if(isdigit(c)) {
			i=0;
			do{
				lexema[i++]=c;
				c=fgetc(f);
			}while(isdigit(c));
            lexema[i]=0;
            ungetc(c,f);
            return NUM;
		}
		if((c==';')||(c==',')||(c=='+')||(c=='-')||(c=='*')||
		   (c=='(')||(c==')')||(c=='[')||(c==']')||(c=='{')||(c=='}')) 
		   return c;
		if(c=='>'){
			c=fgetc(f);
			if(c=='='){
				lexema[0]='>'; lexema[1]='='; lexema[2]=0;
				return MAYORIGUAL;
			}
			ungetc(c,f);
			return MAYOR;
		}
		if(c=='<'){
			c=fgetc(f);
			if(c=='='){
				lexema[0]='<'; lexema[1]='='; lexema[2]=0;
				return MENORIGUAL;
			}
			ungetc(c,f);
			return MENOR;
		}
		if(c=='='){
			c=fgetc(f);
			if(c=='='){
				lexema[0]='='; lexema[1]='='; lexema[2]=0;
				return IGUALIGUAL;
			}
			ungetc(c,f);
			return IGUAL;
		}
		if(c=='/'){
			c=fgetc(f);
			if(c=='/'){
				
			}
			ungetc(c,f);
			return DIVI;
		}
}
		
int espalres(){
	if(strcmp(lexema,"while")==0) return WHILE;
	if(strcmp(lexema,"if")==0) return IF;
	if(strcmp(lexema,"else")==0) return ELSE;
	if(strcmp(lexema,"return")==0) return RETURN;
	if(strcmp(lexema,"for")==0) return FOR;
	if(strcmp(lexema,"int")==0) return INT;
	if(strcmp(lexema,"char")==0) return CHAR;
	if(strcmp(lexema,"string")==0) return STRING;
	if(strcmp(lexema,"main")==0) return MAIN;
	return -1;
}
		
void mostrar(int token){
			switch(token){
				case ID: printf("token = ID [%s] \n",lexema); break;
				case NUM: printf("token = NUM [%s] \n",lexema); break;
				case MAYORIGUAL: printf("token = MENOR IGUAL [%s]\n",lexema); break;
				case MENORIGUAL: printf("token = MENOR IGUAL [%s]\n",lexema); break;
				case IGUALIGUAL: printf("token = DOBLE IGUAL [%s]\n",lexema); break;
				case DIVI: printf("token = DIVISION [%c] \n",token); break;
				case WHILE: printf("token = WHILE [%s] \n",lexema); break;
				case IF: printf("token = IF [%s] \n",lexema); break;
				case ELSE: printf("token = ELSE [%s] \n",lexema); break;
				case RETURN: printf("token = RETURN [%s] \n",lexema); break;
				case FOR: printf("token = FOR [%s] \n",lexema); break;
				case INT: printf("token = INT [%s] \n",lexema); break;
				case CHAR: printf("token = CHAR [%s] \n",lexema); break;
				case STRING: printf("token = STRING [%s] \n",lexema); break;
				case MAIN: printf("token = MAIN [%s] \n",lexema); break;
				case PARI: printf("token = PARIzq [%c] \n",token); break;
				case PARD: printf("token = PARDer [%c] \n",token); break;
				case CORI: printf("token = CORIzq [%c] \n",token); break;
				case CORD: printf("token = CORDer [%c] \n",token); break;
				case LLAVEI: printf("token = LLAVEIzq [%c] \n",token); break;
				case LLAVED: printf("token = LLAVEDer [%c] \n",token); break;
                case MAYOR: printf("token = MAYOR [%c] \n",token); break;
                case MENOR: printf("token = MENOR [%c] \n",token); break;
                case IGUAL: printf("token = IGUAL [%c] \n",token); break;
                case MAS: printf("token = MAS [%c] \n",token); break;
                case MENOS: printf("token = MENOS [%c] \n",token); break;
                case MULTI: printf("token = MULTIPLI [%c] \n",token); break;
                //case DIVI: printf("token = DIVISION [%c] \n",token); break;
                case PUNTOYCOMA: printf("token = PUNTOYCOMA [%c]\n",token); break;
			}
}
			
        




	










































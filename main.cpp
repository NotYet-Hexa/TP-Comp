#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <fstream>
#include "constante.h"
#include "Symbole.h"
//g+#include "Expression.h"



using namespace std;

int main()
{
	string str;
	int c;
	std::ifstream is;
	bool lastWasDigit = false;
	while( c = getchar())
	{
		//Condition de sortie en cas de fin de chain de caractère
		if(c==EOF || c == (int)('\n') || c == (int)('\r'))
		{
			// l'Expression n'est formé que de caractère reconue 
			break;
		}

		// si le caractère lu est un chiffre on récupère le nombre
	 	if ( c >= INT_ZERO && c <= INT_NEUF )
		{	
			str = (char)c;	
			while(c = cin.peek())
			{
				if( c >= INT_ZERO && c <= INT_NEUF)
				{	
					getchar();
					str+= (char)c;
				}
				else
				{
					break;
				}
			}
		}
		else 	// Si ce n'est pas un nombre ça doit être un 
				// des symbole suivante : ( ) + *
		{	
			switch(c)
			{
				case INT_FOIS   : str = '*';    break;
				case INT_PLUS	: str = '+'; break;
				case INT_POUV	: str = '('; break;
				case INT_PFER	: str = ')'; break;
				default    		: cout <<"caractère non recunu"<< c <<endl; return 0; 
			}
		}
	}
		cout<<str<<endl;
	}
	return 0;
}

#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <fstream>
#include <list>

#include "Constante.h"
#include "Symbole.h"
#include "Expression.h"
#include "Lexer.h"
#include "Automate.h"

//g+#include "Expression.h"



using namespace std;

int main()
{
	string str;
	int c;

	ifstream is;
	list<Symbole *> symboles;

	bool lastWasDigit = false;
	while( c = getchar())
	{
		//Condition de sortie en cas de fin de chain de caractère
		if(c==EOF || c == (int)('\n') || c == (int)('\r'))
		{
			// l'Expression n'est formé que de caractère reconue
			symboles.push_back(new Symbole(DOLL));
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
					str += (char)c;
				}
				else
				{
					break;
				}
			}
			
			symboles.push_back(new Expression(stoi(str)));

		}
		else 	// Si ce n'est pas un nombre ça doit être un 
				// des symbole suivante : ( ) + *
		{	
			int id;
			switch(c)
			{
				case INT_FOIS   : id = FOIS; break;
				case INT_PLUS	: id = PLUS; break;
				case INT_POUV	: id = POUV; break;
				case INT_PFER	: id = PFER; break;
				default    		: cout <<"caractère non recunu"<< c <<endl; return 0; 
			}
			symboles.push_back(new Symbole(id));
		}		
	}

// // #if DEBUG


// 	for(list<Symbole *>::iterator it = symboles.begin(); it != symboles.end(); it++)
// 	{
// 		(*it)->print();
// 		cout << endl;
// 	}
// 	cout<<"fin de lecture création du lexer"<<endl;
// #endif 


	Lexer lexer(symboles);

	Automate aut(lexer);
	int resultat = aut.Run();
	cout <<"resultat: "<< resultat<< endl;

	symboles.clear();
	return 0;
}
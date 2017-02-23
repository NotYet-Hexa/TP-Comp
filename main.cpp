#include <iostream>
#include <string>
#include <list>

#include "Constante.h"
#include "Symbole.h"
#include "Expression.h"
#include "Lexer.h"
#include "Automate.h"

using namespace std;

int main()
{
	string str;
	int c;

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
				case INT_FOIS : id = FOIS; break;
				case INT_PLUS : id = PLUS; break;
				case INT_POUV : id = POUV; break;
				case INT_PFER : id = PFER; break;
				default : 
					cout << "caractère non reconnu : " << (char)c << endl;
					return 0; 
			}
			symboles.push_back(new Symbole(id));
		}		
	}

	if(symboles.size() <= 1)
	{
		cout << "Aucune expression à évaluer" << endl;
		return 0;
	}


	// On initialise le lexer avec nos symboles
	Lexer lexer(symboles);

	// On initialise l'automate avec le lexer
	Automate autom(lexer);

	// On lance le lexer et on récupère l'expression évalué
	int resultat = autom.Run();

#ifdef DEBUG

	cout << "Resultat : ";

#endif

	cout << resultat << endl;

	symboles.clear();
	return 0;
}
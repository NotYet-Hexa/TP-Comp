/*************************************************************************
TPComp
Lexer.cpp  -  Implémentation de la classe Lexer
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Lexer (fichier Lexer.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Lexer.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

/// Decale la tête de lecture de 1 vers la fin
void Lexer::Decalage()
{
    if(this->teteDeLecture != this->listeDeSymbole.end())
    {
        this->teteDeLecture++;
    }
}

/// Retourne le symbole pointé par la tête de lecture
Symbole* Lexer::Lecture()
{

#ifdef DEBUG
    cout << "Symbole lu dans le lexer : ";
    (*(this->teteDeLecture))->print();
    cout << endl;
#endif

    return *(this->teteDeLecture);
}

/// Insert le symbole dans le lexer de telle sorte que celui-ci soit le prochain lu
void Lexer::Insert(Symbole* s)
{
    teteDeLecture--;
    Symbole* tmp = *teteDeLecture;
    *teteDeLecture = s;
    delete tmp;
}

//----- Constructeur
Lexer::Lexer(list<Symbole *> symboles) : listeDeSymbole(symboles)
{
    this->teteDeLecture = listeDeSymbole.begin();

    
#if DEBUG
	cout << "------DEBUG-Contenue-du-lexer------" << endl;
	for(list<Symbole *>::iterator it = symboles.begin(); it != symboles.end(); it++)
	{
		(*it)->print();
		cout << endl;
	}
	cout << "-----------------------------------" << endl;
#endif

}
//----- Fin constructeur

//----- Destructeur
Lexer::~Lexer()
{
    for(list<Symbole *>::iterator it = listeDeSymbole.begin(); it != listeDeSymbole.end(); it++)
    {
        delete *it;
    }
    listeDeSymbole.clear();
}
//----- Fin destructeur
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
void Lexer::Decalage()
{
    if(this->teteDeLecture != this->listeDeSymbole.end())
    {
        this->teteDeLecture++;
    }
}

Symbole* Lexer::Lecture()
{
    // cout<<"lu dans lex : ";
    // (*(this->teteDeLecture))->print();
    // cout<<endl;
    return *(this->teteDeLecture);
}

void Lexer::Insert(Symbole* s)
{
    // delete *teteDeLecture;
    teteDeLecture--;
    // Symbole * tmp
    *teteDeLecture = s;
    // cout<<"En tete de lecture après insert : ";
    // (*(this->teteDeLecture))->print();
    // cout<<endl;
}


//----- Constructeur
Lexer::Lexer(list<Symbole *> symboles) : listeDeSymbole(symboles)
{
    // cout<<"construction de Lexer"<<endl;
    this->teteDeLecture = listeDeSymbole.begin();
    // for(list<Symbole *>::iterator it = listeDeSymbole.begin(); it != listeDeSymbole.end(); it++)
	// {
	// 	(*it)->print();
	// 	cout << endl;
	// }
    // cout<<"Lexer construit" <<endl;
}
//----- Fin constructeur

//----- Destructeur
Lexer::~Lexer()
{}// Bloc vide
//----- Fin destructeur
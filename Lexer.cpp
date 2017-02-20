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
    return *(this->teteDeLecture);
}


//----- Constructeur
Lexer::Lexer(list<Symbole *> symboles) : listeDeSymbole(symboles)
{
    this->teteDeLecture = listeDeSymbole.begin();
}
//----- Fin constructeur

//----- Destructeur
Lexer::~Lexer()
{}// Bloc vide
//----- Fin destructeur
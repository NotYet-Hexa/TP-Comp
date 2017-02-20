/*************************************************************************
TPComp
Symbole.cpp  -  description
 -------------------
 début                : 15/02/2017
 copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
 *************************************************************************/

//---------- Réalisation de la classe Symbole (fichier Symbole.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Symbole.h"
#include "Constante.h"
#include "Expression.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//----- Nouvelle méthode
void Symbole::print()
{
     switch(this->ident)
    {
        case EXPR  : cout << "problem"; break;
        case PLUS  : cout << "PLUS";   break;
        case FOIS  : cout << "FOIS";   break;
        case POUV  : cout << "POUV";   break;
        case PFER  : cout << "PFER";   break;
        default    : cout << "NULL";
    }
}
//----- Fin méthode

//----- Nouvelle méthode
Symbole::operator int () const
{
    return ident;
}
//----- Fin méthode

//----- Constructeur
Symbole::Symbole(int id) : ident(id)
{
}
//------ Fin constructeur

//----- Destructeur
Symbole::~Symbole()
{} // Bloc vide
//------ Fin destructeur


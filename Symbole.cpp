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

/// Affiche les informations de l'objet instancié de la classe Symbole
void Symbole::print()
{
     switch(this->ident)
    {
        case EXPR  : cout << "La fonction print de expression devrait être appelé" << endl;
        case PLUS  : cout << "PLUS";   break;
        case FOIS  : cout << "FOIS";   break;
        case POUV  : cout << "POUV";   break;
        case PFER  : cout << "PFER";   break;
        case DOLL  : cout << "DOLL";   break;
        default    : cout << "NULL";
    }
}

/// Cast en int d'un objet instancié de la classe Symbole retournant son identifiant
Symbole::operator int () const
{
    return ident;
}

//----- Constructeur
Symbole::Symbole(int id) : ident(id)
{} // Bloc vide
//------ Fin constructeur

//----- Destructeur
Symbole::~Symbole()
{} // Bloc vide
//------ Fin destructeur


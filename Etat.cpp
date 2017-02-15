/*************************************************************************
TPComp
Etat.h  -  description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Etat (fichier Etat.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Etat.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


//----- Nouvelle méthode
void Etat::print() const
{
    cout<<name<<"\n";
} 
//-----Fin méthode

//----- Constructeur
Etat::Etat(string name)
{
    this->name = name;
}
//----- Fin constructeur

//----- Destructeur
Etat::~Etat()
{}// Bloc vide
//----- Fin destructeur
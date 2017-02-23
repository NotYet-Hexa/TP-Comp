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



void Etat::print() const
{
    cout<<name;
} 

//----- Constructeur
Etat::Etat(string theName): name(theName)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Etat::~Etat()
{}// Bloc vide
//----- Fin destructeur
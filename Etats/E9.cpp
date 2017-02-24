/*************************************************************************
TPComp
E9.cpp  -  Implémentation de E9
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe E9 (fichier E9.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../Constante.h"
#include "../Expression.h"

#include "E9.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void E9::Transition(Automate* const automate, Symbole * s)
{
     #if DEBUG
    this->print();
    cout << endl;
    s->print();
    cout << endl;
    #endif
    
    switch((int)(*s))
    {
        case PLUS :
        case FOIS :
        case PFER : 
        case DOLL :
            automate->Reduction(3);    
            break;
        default :
            throw PROBLEME;
    }
}

//----- Constructeur
E9::E9() : Etat("E9")
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
E9::~E9()
{}// Bloc vide
//----- Fin destructeur
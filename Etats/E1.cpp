/*************************************************************************
TPComp
E1.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe E1 (fichier E1.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../Constante.h"
#include "../Expression.h"

#include "E1.h"
#include "E4.h"
#include "E5.h"


//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void E1::Transition(Automate* const automate, Symbole * s)
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
            automate->Decalage(s, new E4());
            break;
        case FOIS : 
            automate->Decalage(s, new E5());
            break;
        case DOLL :
            automate->Accepter();
            break;
        default : 
            throw PROBLEME;
    }
}

//----- Constructeur
E1::E1() : Etat("E1")
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
E1::~E1()
{}// Bloc vide
//----- Fin destructeur

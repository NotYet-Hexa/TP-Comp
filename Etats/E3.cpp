/*************************************************************************
TPComp
E3.cpp  -  Implémentation de E3
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe E3 (fichier E3.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "E3.h"
#include "../Expression.h"
#include "../Constante.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void E3::Transition(Automate* const automate, Symbole * s)
{
    this->print();
    s->print();
    cout<<endl;
    
    switch((int)(*s))
    {
        case PLUS :
            automate->Reduction(1);
            break;
        case FOIS :
            automate->Reduction(1);
            break; 
        case PFER :
            automate->Reduction(1);
            break;
        case DOLL :
            automate->Reduction(1);
            break;
        default : 
            cout << "problem";
    }
}

//----- Constructeur
E3::E3() : Etat("E3")
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
E3::~E3()
{}// Bloc vide
//----- Fin destructeur
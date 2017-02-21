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
#include "../Constante.h"
#include "../Expression.h"

#include "E3.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void E3::Transition(Automate* const automate, Symbole * s)
{
     #if DEBUG
    this->print();
    cout<<endl;
    s->print();
    cout<<endl;
    #endif
    
    switch((int)(*s))
    {
        case PLUS :
        case FOIS :
        case PFER :
        case DOLL :
            automate->Reduction(1);
            break;
        default : 
            cout << PROBLEME << endl;
            exit(0);
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
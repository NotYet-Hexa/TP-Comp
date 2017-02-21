/*************************************************************************
TPComp
E8.cpp  -  Implémentation de E8
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe E8 (fichier E8.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../Constante.h"
#include "../Expression.h"

#include "E8.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void E8::Transition(Automate* const automate, Symbole * s)
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
            automate->Reduction(3);    
            break;
        default : 
            cout << PROBLEME << endl;
            exit(0);
    }
}
//----- Constructeur
E8::E8() : Etat("E8")
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
E8::~E8()
{}// Bloc vide
//----- Fin destructeur
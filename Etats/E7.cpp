/*************************************************************************
TPComp
E7.cpp  -  Implémentation de E7
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe E7 (fichier E7.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "E7.h"
#include "../Constante.h"
#include "../Expression.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void E7::Transition(Automate* const automate, Symbole * s)
{
    this->print();
    s->print();
    cout<<endl;
    switch((int)(*s))
    {
        case PLUS :
            automate->Reduction(3); 
            break;
        case FOIS :
                //decalage 
            break;
        case PFER : 
            automate->Reduction(3);
            break;
        case DOLL :
            automate->Reduction(3);    
            break;
        default : 
            cout << "problème" << endl;
            exit(0);
    }
}


//----- Constructeur
E7::E7() : Etat("E7")
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
E7::~E7()
{}// Bloc vide
//----- Fin destructeur
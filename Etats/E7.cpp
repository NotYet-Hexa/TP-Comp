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
#include "../Constante.h"
#include "../Expression.h"

#include "E5.h"
#include "E7.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void E7::Transition(Automate* const automate, Symbole * s)
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
            automate->Reduction(3); 
            break;
        case FOIS :
            automate->Decalage(s, new E5());
            break;
        case PFER : 
            automate->Reduction(3);
            break;
        case DOLL :
            automate->Reduction(3);    
            break;
        default : 
            cout << PROBLEME << endl;
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
/*************************************************************************
TPComp
E6.cpp  -  Implémentation de E6
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe E6 (fichier E6.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../Constante.h"
#include "../Expression.h"

#include "E4.h"
#include "E5.h"
#include "E6.h"
#include "E9.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void E6::Transition(Automate* const automate, Symbole * s)
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
        case PFER : 
            automate->Decalage(s, new E9());
            break;
        default : 
            cout << PROBLEME << endl;
            exit(0);
    }
}
//----- Constructeur
E6::E6() : Etat("E6")
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
E6::~E6()
{}// Bloc vide
//----- Fin destructeur
/*************************************************************************
TPComp
E2.cpp  -  Implémentation de E2
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe E2 (fichier E2.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../Constante.h"
#include "../Expression.h"

#include "E2.h"
#include "E3.h"
#include "E6.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void E2::Transition(Automate* const automate, Symbole * s)
{
    #if DEBUG
    this->print();
    cout << endl;
    s->print();
    cout << endl;
    #endif
    
    switch((int)(*s))
    {
        case EXPR : 
            {
                Expression * ex = (Expression*)(s);
                if(ex->evalue)
                {
                    automate->Decalage(s, new E6());
                }
                else
                {
                    automate->Decalage(s, new E3());
                }
            }
            break;
        case POUV : 
            automate->Decalage(s, new E2());
            break;
        default : 
            throw PROBLEME;
    }
}
//----- Constructeur
E2::E2() : Etat("E2")
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
E2::~E2()
{}// Bloc vide
//----- Fin destructeur
/*************************************************************************
TPComp
E5.cpp  -  Implémentation de E5
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe E5 (fichier E5.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../Constante.h"
#include "../Expression.h"

#include "E2.h"
#include "E3.h"
#include "E5.h"
#include "E8.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void E5::Transition(Automate* const automate, Symbole * s)
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
                    automate->Decalage(s, new E8());
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
            cout << PROBLEME << endl;
            exit(0);
    }
}

//----- Constructeur
E5::E5() : Etat("E5")
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
E5::~E5()
{}// Bloc vide
//----- Fin destructeur
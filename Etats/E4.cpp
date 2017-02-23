/*************************************************************************
TPComp
E4.cpp  -  Implémentation de E4
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe E4 (fichier E4.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../Constante.h"
#include "../Expression.h"

#include "E2.h"
#include "E3.h"
#include "E4.h"
#include "E7.h"


//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void E4::Transition(Automate* const automate, Symbole * s)
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
                    automate->Decalage(s, new E7());
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
E4::E4() : Etat("E4")
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
E4::~E4()
{}// Bloc vide
//----- Fin destructeur
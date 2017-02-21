/*************************************************************************
TPComp
E0.cpp  -  Implémentation de E0
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe E0 (fichier E0.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../Constante.h"
#include "../Expression.h"


#include "E0.h"
#include "E1.h"
// #include "E2.h"
#include "E3.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

bool E0::Transition(Automate* const automate, Symbole * s)
{
    this->print();
    cout<<((Expression)(*s)).GetValeur()<<" : "<<((Expression)(*s)).evalue<<endl;
    switch((int)(*s))
    {
        case EXPR : 
            {
                Expression * ex = (Expression*)(s);
                if(ex->evalue)
                {
                    automate->Decalage(s, new E1());
                }
                else
                {
                    automate->Decalage(s, new E3());
                }
            }
            break;
        case POUV : 
            // cout << "POUV";
            // automate->Decalage(s, new E2());
            break;
        default : 
            cout << "problème" << endl;
            // cout << (int)(*s);
            exit(0);
    }
}

//----- Constructeur
E0::E0() : Etat("E0")
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
E0::~E0()
{}// Bloc vide
//----- Fin destructeur
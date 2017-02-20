/*************************************************************************
TPComp
Automate.cpp  -  Implémentation de Automate
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Automate (fichier Automate.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Automate.h"
#include "Expression.h"
#include "Constante.h"
#include "Lexer.h"
#include "Etat.h"
#include "Etats/E0.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Automate::EmpilerSymbole(Symbole* s)
{
    pileSymbole.push(s);
}

Symbole* Automate::DepilerSymbole()
{
    Symbole* tmp = pileSymbole.top();
    pileSymbole.pop();
    return tmp;
}

void Automate::EmpilerEtat(Etat* e)
{
    pileEtat.push(e);
}

Etat* Automate::DepilerEtat()
{
    Etat* tmp = pileEtat.top();
    pileEtat.pop();
    return tmp;
}

int Automate::Run()
{
    while(!accepter)
    {
        Etat* courant = pileEtat.top();
        Symbole* symboleSuivant = lexer->Lecture();
        courant->Transition(this, symboleSuivant);
    }
}

void Automate::Accepter()
{
    accepter = true;
}

void Automate::Decalage(Symbole* s, Etat* e)
{
    pileSymbole.push(s);
    pileEtat.push(e);
}

void Automate::Reduction(int n, Symbole* s)
{
    for(int i = 0; i < n; i++)
    {
        delete(pileEtat.top());
        pileEtat.pop();
    }
    if(n==1)
    {
        //rien a faire
    }
    else if(n==3)
    {
        Expression* ex;
        Symbole* tmp = DepilerSymbole();
        if((int)*tmp == EXPR)
        {
            int resultTmp;
            Symbole* operateur = DepilerSymbole();
            Expression* tmp2 = (Expression*)DepilerSymbole();
            // Soit E + E ou E * E
            switch((int)(*operateur))
            {
                case PLUS :
                    resultTmp = ((Expression*)tmp)->GetValeur() + tmp2->GetValeur();
                    break;
                case FOIS :
                    resultTmp = ((Expression*)tmp)->GetValeur() * tmp2->GetValeur();
                    break;
            }
            ex = new Expression(resultTmp);
        }
        else
        { //doit etre une paranthese
            ex = (Expression*)DepilerSymbole();
            DepilerSymbole();
        }
        EmpilerSymbole(ex);
    }
    else
    {
        cout << "problem" << endl;
    }
    // lexer-> pas compris
}

//----- Constructeur
Automate::Automate(Lexer& l): accepter(false)// pileSymbole(), pileEtat()
{
    lexer = &l;
    EmpilerEtat((Etat*)new E0());
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Automate::~Automate()
{}// Bloc vide
//----- Fin destructeur
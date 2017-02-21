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
        // cout<<"Symbole lu :";
        // symboleSuivant->print();
        // cout<<endl;
        // cout<<"caster en expr:";
        // ((Expression*)symboleSuivant)->print();
        // cout<<endl;
        courant->Transition(this, symboleSuivant);
    }
    return ((Expression *)(pileSymbole.top()))->GetValeur();
}

void Automate::Accepter()
{
    accepter = true;
}

void Automate::Decalage(Symbole* s, Etat* e)
{
    pileSymbole.push(s);
    pileEtat.push(e);
    lexer->Decalage();
}

void Automate::Reduction(int n)
{
    Expression* ex;
    for(int i = 0; i < n; i++)
    {
        delete pileEtat.top();
        pileEtat.pop();
    }
    if(n==1)
    {
        Expression* tmp = (Expression*)DepilerSymbole();
        ex = new Expression(tmp->GetValeur()); 
        ex->evalue = true;
    }
    else if(n==3)
    {
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
            ex = new Expression(resultTmp, true);
        }
        else
        { //doit etre une paranthese
            Expression* tmp = (Expression*)DepilerSymbole();
            ex = new Expression(tmp->GetValeur()); 
            ex->evalue = true;
            Symbole * pfer = DepilerSymbole();
            delete pfer;
        }
    }
    else
    {
        cout << PROBLEME << endl;
    }
    // on met dans le pointeur du lexer l'expression qu'on vient de calculer
    // de telle sorte que le prochain symbole lu sera l'expression que l'on vient de calculer
    // cout << ex->GetValeur() << endl;
    lexer->Insert((Symbole*)ex);
    // cout << ex->GetValeur() << endl;
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
{
    while(!pileEtat.empty())
    {
        Etat* top = pileEtat.top();
        pileEtat.pop();
        delete top;
    }

    while (!pileSymbole.empty() )
    {
        pileSymbole.pop();
    }
}// Bloc vide
//----- Fin destructeur
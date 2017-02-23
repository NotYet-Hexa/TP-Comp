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

//----- Nouvelle méthode
void Automate::EmpilerSymbole(Symbole* s)
{
    pileSymbole.push(s);
}
//----- Fin de EmpilerSymbole

//----- Nouvelle méthode
Symbole* Automate::DepilerSymbole()
{
    Symbole* tmp = pileSymbole.top();
    pileSymbole.pop();
    //On retourne le symbole dépilé
    return tmp;
}
//----- Fin de DepilerSymbole

//----- Nouvelle méthode
void Automate::EmpilerEtat(Etat* e)
{
    pileEtat.push(e);
}
//----- Fin de EmpilerEtat

//----- Nouvelle méthode
Etat* Automate::DepilerEtat()
{
    Etat* tmp = pileEtat.top();
    pileEtat.pop();
    //On retourne l'état dépilé
    return tmp;
}
//----- Fin de DepilerEtat

//----- Nouvelle méthode
int Automate::Run()
{
    // Tant que l'expression n'a pas été accepter par l'analyseur on 
    // coninue de faire des transition
    while(!accepter)
    {
        // On récupère l'éttat en haut de la pile d'état, c'est l'état
        // dit courant.
        Etat* courant = pileEtat.top();
        // On lit le symbole sur la tête de lecture, potentiellement 
        // c'est une expression qui vient d'être calculé
        Symbole* symboleSuivant = lexer->Lecture();
        // On fait la transition de l'état courant 
        courant->Transition(this, symboleSuivant);
    }
    // Si le mot est accepté on retourne la valeur de l'expression calulée
    return ((Expression *)(pileSymbole.top()))->GetValeur();
}
//----- Fin de Run

//----- Nouvelle méthode
void Automate::Accepter()
{
    accepter = true;
}

//----- Fin de Accepter

//----- Nouvelle méthode
void Automate::Decalage(Symbole* s, Etat* e)
{
    // On place le symbole qui vient d'être lu sur la pile de symbole  
    pileSymbole.push(s);
    // On place le nouvelle état courant sur la pile d'état 
    pileEtat.push(e);
    // Et on décale la tête de lecture 
    lexer->Decalage();
}
//----- Fin de Decalage

//----- Nouvelle méthode
void Automate::Reduction(int n)
{
    Expression* ex;
    // On dépile autant d'état que indiqué
    for(int i = 0; i < n; i++)
    {
        delete pileEtat.top();
        pileEtat.pop();
    }
    
    // S'il n'y a qu'un état à dépiler alors la reduction à été faite par 
    // l'une des deux règle:
    // E' -> E
    // E -> val  
    if(n==1)
    {
        // On récupère le symbole en haut de la pile, et comme on sait que
        // c'est une expression il n' a qu'a indiqué qu'elle a été évaluée
        Expression* tmp = (Expression*)DepilerSymbole();
        ex = new Expression(tmp->GetValeur()); 
        ex->evalue = true;
    }
    else if(n==3)
    {
        // Sinon c'est l'une des tois règles:
        // E -> E + E
        // E -> E * E
        // E -> ( E ) 
        Symbole* tmp = DepilerSymbole();
        if((int)*tmp == EXPR)
        {
            // C'est donc l'une des deux règles:
            // E -> E + E
            // E -> E * E
            // Dans ce cas on doit calculé l'expression
            int resultTmp;
            Symbole* operateur = DepilerSymbole();
            Expression* tmp2 = (Expression*)DepilerSymbole();
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
        {   // C'est donc la règles:
            // E -> ( E )
            // Donc on dépile les deux derniers symboles et on rempile l'expretion
            // évaluée puisqu'il n'y a pas de calcul à faire
            Expression* tmp = (Expression*)DepilerSymbole();
            ex = new Expression(tmp->GetValeur(), true);
            DepilerSymbole();
        }
    }
    else
    {
        // Sinon la reduction ne corespond à aucune règle connue
        cout << PROBLEME << endl;
    }
    // Enfin on fqit en sort que lq prochaine lecture pqr l'état courant soit 
    // l'expression que l'on vient de créer pour faire la bonne transition
    lexer->Insert((Symbole*)ex);
}
//----- Fin de Reduction

//----- Constructeur
Automate::Automate(Lexer& l): accepter(false)
{
    lexer = &l;
    // On empile l'état zéro qui est l'état initial 
    EmpilerEtat((Etat*)new E0());
}
//----- Fin constructeur

//----- Destructeur
Automate::~Automate()
{
    // On detruit les deux derniers état dans la pile ou les état empilé
    // non detruit du fait d'une erreur de sytaxe pour notre analyseur
    while(!pileEtat.empty())
    {
        Etat* top = pileEtat.top();
        pileEtat.pop();
        delete top;
    }

    // On vide la pile de symbole 
    while (!pileSymbole.empty() )
    {
        pileSymbole.pop();
    }
}
//----- Fin destructeur
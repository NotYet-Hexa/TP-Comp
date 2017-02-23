/*************************************************************************
TPComp
Expression.h  -  description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Expression (fichier Expression.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systéme
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Expression.h"
#include "Constante.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

/// Affiche les informations sur l'expression : sa valeur et si celle-ci est évalué
void Expression::print()
{
    cout << "EXP :";
    cout << valeur;
    cout << " : ";
    cout << evalue;
}

/// Retourne la valeur de l'expression
int Expression::GetValeur()
{
    return this->valeur;
}

//----- Constructeur
Expression::Expression(int val, bool eval):Symbole(EXPR), valeur(val), evalue(eval)
{
}
//----- Fin constructeur

Expression::Expression(const Expression& exp):Symbole(EXPR), valeur(exp.valeur), evalue(exp.evalue)
{
    cout << "copie" << endl;
}
//----- Destructeur
Expression::~Expression()
{}
//----- Fin destructeur
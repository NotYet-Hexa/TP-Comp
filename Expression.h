/*************************************************************************
TPComp
Expression.h  -  description
 -------------------
 début                : 15/02/2017
 copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
 *************************************************************************/

//---------- Interface de la classe Expression (fichier Expression.h) ------
#if ! defined ( EXPRESSION_H )
#define EXPRESSION_H

//--------------------------------------------------- Interfaces utilisées

#include "Symbole.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Expression:
//


class Expression : public Symbole {

    public:

        int GetValeur();
        virtual void print();
        bool evalue;

        Expression(int val, bool eval = false);
        Expression(const Expression& exp);
        ~Expression();

    private: 

        int valeur;
};
//------------------------------------------------------------------------

#endif // if ! defined EXPRESSION_H

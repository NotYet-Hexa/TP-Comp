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

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Expression:
//


class Expression : public Symbole {
    private: 

        int valeur;

    public:

    Expression();
    
    ~Expr();
    
};
//------------------------------------------------------------------------

#endif // if ! defined EXPRESSION_H

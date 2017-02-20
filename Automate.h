/*************************************************************************
TPComp
Automate.h  -  Interface de Automate
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe Automate (fichier Automate.h) ------
#if ! defined ( AUTOMATE_H )
#define AUTOMATE_H


//--------------------------------------------------- Interfaces utilisées

#include <stack>

#include "Expression.h"
// #include "Etat.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Automate:
//

//------------------------------------------------------------------------

class Automate{
    
    public:
        // void EmpilerExpression();
        // Expression* DepilerExpression();

        // void EmpilerEtat();
        // Etat* DepilerEtat();

        Automate();

    private:
        // std::stack<Expression*> pileExpression;
        // std::stack<Etat*> pileEtat;
        ~Automate();
};

#endif // if ! defined AUTOMATE_H
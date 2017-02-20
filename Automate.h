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

#include "Symbole.h"
#include "Etat.h"
#include "Lexer.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Automate:
//

//------------------------------------------------------------------------
class Etat;

class Automate{
    
    public:
        void EmpilerSymbole(Symbole* s);
        Symbole* DepilerSymbole();

        void EmpilerEtat(Etat* e);
        Etat* DepilerEtat();

        void Accepter();
        void Decalage(Symbole* s, Etat* e);
        void Reduction(int n, Symbole* s);

        int Run();

        Automate(Lexer& l);

    private:
        Lexer* lexer;
        std::stack<Symbole*> pileSymbole;
        std::stack<Etat*> pileEtat;

        bool accepter;

        ~Automate();
};

#endif // if ! defined AUTOMATE_H
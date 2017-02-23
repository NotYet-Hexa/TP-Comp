/*************************************************************************
TPComp
Lexer.h  -  Interface de Lexer
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe Lexer (fichier Lexer.h) ------
#if ! defined ( LEXER_H )
#define LEXER_H


//--------------------------------------------------- Interfaces utilisées

#include <list>
#include "Symbole.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Lexer:
// Permet de naviguer dans l'expression aisément

//------------------------------------------------------------------------

class Lexer{
    public:
        void Decalage();
        Symbole* Lecture();

        void Insert(Symbole* s);

        Lexer(std::list<Symbole *> symboles);
        ~Lexer();

    private:
        std::list<Symbole *> listeDeSymbole;
        std::list<Symbole *>::iterator teteDeLecture;
        
};

#endif // if ! defined LEXER_H
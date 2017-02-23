/*************************************************************************
TPComp
Etat.h  -  description
 -------------------
 début                : 15/02/2017
 copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
 *************************************************************************/

//---------- Interface de la classe Etat (fichier Etat.h) ------
#if ! defined ( ETAT_H )
#define ETAT_H

#include <string>

//--------------------------------------------------- Interfaces utilisées
#include "Symbole.h"
#include "Automate.h"


//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Etat:
//

//------------------------------------------------------------------------

class Automate;

class Etat {

    protected:
        
        std::string name;

    public:

        void print() const;
        virtual void Transition(Automate* const automate, Symbole * s) = 0;

        Etat(std::string name);
        virtual ~Etat();
};

#endif // if ! defined ETAT_H
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

class Etat {

    protected: 
        
        std::string name;

    public:

        Etat(std::string name);
        
        virtual ~Etat();

        void print() const;

        virtual bool transition(Automate & automate, Symbole * s) = 0;

};
#endif // if ! defined ETAT_H
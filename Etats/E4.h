/*************************************************************************
TPComp
E4.h  -  Interface de E4
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe E4 (fichier E4.h) ------
#if ! defined ( E4_H )
#define E4_H


//--------------------------------------------------- Interfaces utilisées

#include "../Etat.h"
#include "../Automate.h"
#include "../Symbole.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe E4:
//

//------------------------------------------------------------------------

class E4 : public Etat{
    public:
        
        virtual void Transition(Automate* const automate, Symbole * s);

        E4();
        ~E4();
};

#endif // if ! defined E4_H
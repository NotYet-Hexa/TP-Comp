/*************************************************************************
TPComp
E7.h  -  Interface de E7
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe E7 (fichier E7.h) ------
#if ! defined ( E7_H )
#define E7_H


//--------------------------------------------------- Interfaces utilisées

#include "../Etat.h"
#include "../Automate.h"
#include "../Symbole.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe E7:
//

//------------------------------------------------------------------------

class E7: public Etat{
    public:
        E7();
        ~E7();
        virtual void Transition(Automate* const automate, Symbole * s);

       


};

#endif // if ! defined E7_H
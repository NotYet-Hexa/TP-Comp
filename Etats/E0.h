/*************************************************************************
TPComp
E0.h  -  Interface de E0
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe E0 (fichier E0.h) ------
#if ! defined ( E0_H )
#define E0_H


//--------------------------------------------------- Interfaces utilisées
#include "../Etat.h"
#include "../Automate.h"
#include "../Symbole.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe E0:
//

//------------------------------------------------------------------------

class E0 : public Etat{
    public:
        E0();
        ~E0();
        virtual void Transition(Automate* const automate, Symbole * s);

    private:
        
};

#endif // if ! defined E0_H
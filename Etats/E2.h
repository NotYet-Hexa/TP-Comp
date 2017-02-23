/*************************************************************************
TPComp
E2.h  -  Header de E2
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe E2 (fichier E2.h) ------
#if ! defined ( E2_H )
#define E2_H


//--------------------------------------------------- Interfaces utilisées
#include "../Etat.h"
#include "../Automate.h"
#include "../Symbole.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe E2:
//

//------------------------------------------------------------------------

class E2 : public Etat{
    public:

        E2();
        ~E2();
    
        virtual void Transition(Automate* const automate, Symbole * s);
};

#endif // if ! defined E2_H
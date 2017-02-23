/*************************************************************************
TPComp
E6.h  -  Interface de E6
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe E6 (fichier E6.h) ------
#if ! defined ( E6_H )
#define E6_H


//--------------------------------------------------- Interfaces utilisées
#include "../Etat.h"
#include "../Automate.h"
#include "../Symbole.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe E6:
//

//------------------------------------------------------------------------

class E6 : public Etat{
    public:
        
        virtual void Transition(Automate* const automate, Symbole * s);
        
        E6();
        ~E6();
};

#endif // if ! defined E6_H
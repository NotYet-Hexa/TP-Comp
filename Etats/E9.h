/*************************************************************************
TPComp
E9.h  -  Interface de E9
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe E9 (fichier E9.h) ------
#if ! defined ( E9_H )
#define E9_H


//--------------------------------------------------- Interfaces utilisées
#include "../Etat.h"
#include "../Automate.h"
#include "../Symbole.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe E9:
//

//------------------------------------------------------------------------

class E9 : public Etat{
    public:
        
        virtual void Transition(Automate* const automate, Symbole * s);
        
        E9();
        ~E9();
};

#endif // if ! defined E9_H
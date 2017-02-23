/*************************************************************************
TPComp
E5.h  -  Interface de E5
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe E5 (fichier E5.h) ------
#if ! defined ( E5_H )
#define E5_H


//--------------------------------------------------- Interfaces utilisées
#include "../Etat.h"
#include "../Automate.h"
#include "../Symbole.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe E5:
//

//------------------------------------------------------------------------

class E5 : public Etat{
    public:
       
        virtual void Transition(Automate* const automate, Symbole * s);

         E5();
        ~E5();
};

#endif // if ! defined E5_H
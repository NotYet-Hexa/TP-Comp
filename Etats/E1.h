/*************************************************************************
TPComp
E1.h  -  Header de E1
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe E1 (fichier E1.h) ------
#if ! defined ( E1_H )
#define E1_H


//--------------------------------------------------- Interfaces utilisées
#include "../Etat.h"
#include "../Automate.h"
#include "../Symbole.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe E1:
//

//------------------------------------------------------------------------

class E1 : public Etat{
    public:
        E1();
        ~E1();
        virtual void Transition(Automate* const automate, Symbole * s);

        
};

#endif // if ! defined E1_H
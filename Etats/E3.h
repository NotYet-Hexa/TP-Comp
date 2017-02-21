/*************************************************************************
TPComp
E3.h  -  Header de E3
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe E3 (fichier E3.h) ------
#if ! defined ( E3_H )
#define E3_H


//--------------------------------------------------- Interfaces utilisées
#include "../Etat.h"
#include "../Automate.h"
#include "../Symbole.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe E3:
//

//------------------------------------------------------------------------

class E3 : public Etat{
    public:
        E3();
        ~E3();
        virtual void Transition(Automate* const automate, Symbole * s);

    private:
       
};

#endif // if ! defined E3_H
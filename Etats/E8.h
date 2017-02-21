/*************************************************************************
TPComp
E8.h  -  Interface de E8
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe E8 (fichier E8.h) ------
#if ! defined ( E8_H )
#define E8_H


//--------------------------------------------------- Interfaces utilisées
#include "../Etat.h"
#include "../Automate.h"
#include "../Symbole.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe E8:
//

//------------------------------------------------------------------------

class E8 : public Etat{
    public:
        E8();
        ~E8();
        virtual void Transition(Automate* const automate, Symbole * s);
        

};

#endif // if ! defined E8_H
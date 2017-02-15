/*************************************************************************
TPComp
Symbole.h  -  description
 -------------------
 début                : 15/02/2017
 copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
 *************************************************************************/

//---------- Interface de la classe Symbole (fichier Symbole.h) ------
#if ! defined ( SYMBOLE_H )
#define SYMBOLE_H



//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Symbole:
//

//------------------------------------------------------------------------


class Symbole {

    protected: 
    
        int ident;
    public:
    
        void print();

        operator int() const; 

        Symbole(int id);

        virtual ~Symbole();

};


#endif // if ! defined SYMBOLE_H

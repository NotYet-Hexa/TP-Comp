// Constantes du TP 

#if ! defined ( CONSTANT_H )
#define CONSTANT_H

// identifiant des symbole terminaux et non terminaux 
const int EXPR = 1;
const int PLUS = 2;
const int FOIS = 3;
const int POUV = 4;
const int PFER = 5;
const int DOLL = 6;


// code ASCII des caractère:

const int INT_ZERO = (int)('0');
const int INT_NEUF = (int)('9');
const int INT_PLUS = (int)('+');
const int INT_FOIS = (int)('*');
const int INT_POUV = (int)('(');
const int INT_PFER = (int)(')');

// message affiché en cas d'erreur de syntaxe
const char PROBLEME[] = "Erreur de syntaxe";

#endif // if ! defined CONSTANT_H
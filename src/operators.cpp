#include<iostream>

#include"Tableau.hpp"
#include"operators.hpp"


std::ostream &operator<<(std::ostream &flux, Tableau tab){       // associe l'opérateur de flux à la fonction afficher de la classe tableau.
    tab.afficher(flux);
    return flux;
}
    

#include<iostream>

#include"Case.hpp"



Case::Case() : c_x(0), c_y(0), c_e(0)    // Initialisation de l'objet case avec toutes les valeurs à 0.
{
}

Case::Case(int x, int y, int e) : c_x(x), c_y(y), c_e(e)    // Surcharge du constructeur en donnant des valeurs aux attributs.
{
}

Case::Case(Case const& aCopier) : c_x(aCopier.c_x), c_y(aCopier.c_y), c_e(aCopier.c_e)      // Copie complete d'une case.
{
}

int Case::getX()const{             

    return c_x;
}

int Case::getY()const{

    return c_y;
}

int Case::getE(){

    return c_e;
}

Case& Case::changementEtat(int e){           // Fonction changeant la valeur de l'attribut e.

    c_e = e;
    return *this;
}

void Case::afficher(std::ostream &flux)const{        // Affiche la valeur e de la case.
    flux <<"|"<< c_e;
}

Case& Case::operator=(Case const& a){
    if(this != &a){
        c_x = a.c_x;
        c_y = a.c_y;
        c_e = a.c_e;
    }
    return *this;
}

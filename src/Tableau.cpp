#include<iostream>
#include<cstdlib>

#include"Case.hpp"
#include"Tableau.hpp"



Tableau::Tableau(){                                     // initialise un tableau de 400 avec 0 comme toute valeur de e.

    for(int j=0 ;j<20; j++){
        for(int i=0;i<20;i++){
                int coord=20*j+i;

                if(j==0 || j==19 || i==0 || i==19){     // Donne la valeur 2 aux cases en bordure.
                    tab[coord] = Case(i,j,2);
                }
                else{
                    tab[coord] = Case(i,j);             // Donne la valeur 0 pour toutes les autres
                }          
        }
    }
}

Tableau::Tableau(Tableau const& aCopier){
    
    for(int coord=0; coord<400; coord++){
        tab[coord] = aCopier.tab[coord];
    }
}

Tableau& Tableau::perturbation(int x, int y){           // Change l'état de la case aux coordonnées en attribut.

    int coord = 20*y+x;
    tab[coord].changementEtat(1);
    return *this;
}

bool Tableau::testVivant(Case const& a){           // Change les états de façon aléatoire des cases adjacente à une case de valeur 1
    int const x(a.getX()), y(a.getY());
    tab[20*y+x].changementEtat(0);
    int compteurVoisin(0);
    for(int j=y-1; j<y+2; j++){               
        for(int i=x-1; i<x+2; i++){
            if(tab[20*j+i].getE() == 1){
                compteurVoisin ++;
            }
        }
    }
    tab[20*y+x].changementEtat(1);
    if(compteurVoisin == 2 || compteurVoisin == 3){
        return true;
    }
    else{
        return false;
    }
}

bool Tableau::testMort(Case const& a){           // Change les états de façon aléatoire des cases adjacente à une case de valeur 1
    int const x(a.getX()), y(a.getY());
    int compteurVoisin(0);
    for(int j=y-1; j<y+2; j++){               
        for(int i=x-1; i<x+2; i++){
            if(tab[20*j+i].getE() == 1){
                compteurVoisin ++;
            }
        }
    }
    if(compteurVoisin == 3){
        return true;
    }
    else{
        return false;
    }
}

Tableau Tableau::update(){
    Tableau temp(*this);
    for(int k=0; k<400; k++){
        if(tab[k].getE()==1){
            if(!(temp.testVivant(tab[k]))){
                tab[k].changementEtat(0);
            }
        }
        if(tab[k].getE()==0){
            if(temp.testMort(tab[k])){
                tab[k].changementEtat(1);
            }
        }
    }
    return *this;
}

 void Tableau::afficher(std::ostream &flux){

    for(int j=0 ;j<20; j++){
        for(int i=0;i<20;i++){
            int coord(20*j+i);
                tab[coord].afficher(flux);
        }
        std::cout << "|" << std::endl;
    }
}

Tableau& Tableau::operator=(Tableau const& a){

    if(this != &a){
        
        for(int coord = 0; coord<400; coord++){
            tab[coord] = a.tab[coord];
        }
    }
    return *this;
}



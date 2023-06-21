#include<iostream>
#include<cstdlib>
#include<ctime>

#include"Case.hpp"
#include"Tableau.hpp"
#include"operators.hpp"

int main(){
    srand((unsigned int)time(0));
    Tableau tab;
    tab.perturbation(10,10);
    tab.perturbation(11,10);
    tab.perturbation(10,11);
    tab.perturbation(11,11);
    tab.perturbation(9,11);
    //tab.perturbation(11,9);
    tab.perturbation(12,10);
    std::cout << tab << std::endl;

    for(int k=0; k<10;  k++){
        tab = tab.update();
        std::cout <<tab<< std::endl;
    }
    
    return 0;
}
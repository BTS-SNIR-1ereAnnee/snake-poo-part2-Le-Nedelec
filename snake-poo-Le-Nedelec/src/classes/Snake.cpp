#include "Point.h"
#include "Board.h"
#include "Snake.h"
#include <iostream>

//Base constructeur
Snake::Snake(){

this->m_index = 0;

}

//Accesseur du tableau serpent
Point Snake::getSnake() const {

    return this->m_serpent[20];

}

//Accesseur de l'index
int Snake::getIndex() const {

    return this->m_index;

}

//setter de l'index (endroit d'ajout de point dans serpent)
void Snake::setIndex(int x){

    this->m_index = x ;    

}

/*
 * Affiche le serpent
 */
void Snake::afficherSnake(){

    for(int i = 0; i < getIndex(); i++){
    
        m_serpent[i].drawPoint();
    
    }

}

/*
 * Ajoute un point au corp du serpent
 */
void Snake::ajouterPoint(Point p){
        
    this->m_serpent[getIndex()] = p;
    this->m_index += 1;
    
}

/*
 * Les points autres que la tête obtienne les coordonnées du point suivant
 */
void Snake::deplacementSnake(Point p){

    for(int i = getIndex()-1; i > 0; i--){
    
        m_serpent[i].erasePoint();
        m_serpent[i] = m_serpent[i-1];
        
    }
    
    m_serpent[0] = p;
    
}

/*
 * affiche les coordonnées des points stockés dans serpent 
 */
void Snake::debugSnake(){

   for(int i = 0; i < getIndex(); i++){
     
     m_serpent[i].debug();
    
    }
       

}

//Basic destructeur
Snake::~Snake(){

}

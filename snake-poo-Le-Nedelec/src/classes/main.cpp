/*
 Projet: snake
 Auteur: Sylvain Guilbert
*/
#include <iostream>
#include "Point.h"
#include "Board.h"
#include "Snake.h"


using namespace std;

//void verifLimite()

int main()
{
    const int X_MAX = 20;
    const int Y_MAX = 30;
    Snake serpent;
    
     // pointeurs sur l'unique instance de la classe UniqueObject
    Board *fenetre;
    // initialisation des pointeurs
    fenetre = Board::getInstance ();
    
    // Création du corp du serpent (p, p2, p3)
    Point p(10,10);
    Point p2(10,11);
    Point p3(10,12);
    // Mise en place des points dans le tableau 
    // de type Snake de nom serpent 
    serpent.ajouterPoint(p);
    serpent.ajouterPoint(p2);
    serpent.ajouterPoint(p3);
    // Affichage des trois points (début de partie)
    serpent.afficherSnake();
    
    // condition de sortie 
    char sortie = '0';
    
    // Corp des commandes (jeu actuel)
    do 
    {
        // Entrer utilisateur 
        cin >> sortie;
        // prend en paramètre l'entrer utilisateur
        switch(sortie){
        
            // case 1: permet le déplacement à gauche
            case '1':
                p.erasePoint(); // Retire l'affichage du point
                p.moveLeft(); // modifie les coordonnées pour que le point move left
                serpent.deplacementSnake(p); // déplacement du corp du serpent
                serpent.afficherSnake(); // affichage du corp
                //serpent.debugSnake();
                break;
                
            // case 2: permet le déplacment vers le bas
            case '2':
                p.erasePoint();
                p.moveDown(); // modifie les coordonnées pour que le point move down
                serpent.deplacementSnake(p);
                serpent.afficherSnake();
                //serpent.debugSnake();
                break;
                
            // case 3: permet le déplacement vers la droite 
            case '3':
                p.erasePoint();
                p.moveRight(); //modifie les coordonnées pour que le point move right
                serpent.deplacementSnake(p);
                serpent.afficherSnake();
                //serpent.debugSnake();
                break; 
                
            // case 5: permet le déplacement vers le haut
            case '5':
                p.erasePoint();
                p.moveUp(); // modifie les coordonnées pour que le point move up
                serpent.deplacementSnake(p);
                serpent.afficherSnake();
                //serpent.debugSnake();
                break;
            
        }
    
    // condition de sortie = q
    }while(sortie != 'q');
    
    // permet l'affichage des étoiles (*)
    getchar();
    // déstruction de la fenètre, fin du programme
    fenetre->kill();
   
    return 0;
}

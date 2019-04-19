#include <iostream>
#include <fstream>
#include <string>
#include <allegro.h>
#include "Sommet.h"
#include "Arete.h"
#include "Graphe.h"




int main()/// bb
{
    allegro_init();
    install_keyboard();
    //set_gfx_mode(GFX_AUTODETECT_WINDOWED,1000,800,0,0);
    BITMAP *buffer;
    //buffer=create_bitmap(SCREEN_W,SCREEN_H);
    //clear_bitmap(buffer);
    Graphe test;
    Graphe vide_P1;
    Graphe vide_P2;
    Pareto G1;
    ///
    test.remplir("broadway","0");

    vide_P1.Kruskal(test,1);
    vide_P2.Kruskal(test,2);
    G1.comptageBinaire(test.GetOrdre());



    //vide_P1.affichage(buffer,300,0);
    //vide_P2.affichage(buffer,600,0);
    //test.affichage(buffer,0,0);

    //blit(buffer,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    //clear_bitmap(buffer);
    //while(!key[KEY_F1])
    //{
    //}
    return 0;
}END_OF_MAIN();

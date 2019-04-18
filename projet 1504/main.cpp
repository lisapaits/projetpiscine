#include <iostream>
#include <fstream>

#include <allegro.h>
#include "Sommet.h"
#include "Arete.h"
#include "Graphe.h"



int main()
{
    allegro_init();
    install_keyboard();
    //set_gfx_mode(GFX_AUTODETECT_WINDOWED,1000,800,0,0);
    BITMAP *buffer;
    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(buffer);
    Graphe test;
    Graphe vide_P1;
    vide_P1.Kruskal();///
    test.remplir("broadway","0");


    //test.affichage(buffer);
   // blit(buffer,screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    clear_bitmap(buffer);
    //while(!key[KEY_F1])
    //{

    //}
    return 0;
}END_OF_MAIN();

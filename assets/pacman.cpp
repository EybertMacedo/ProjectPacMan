#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
const float FPS = 12;
const int SCREEN_W = 1184; 
const int SCREEN_H = 448;   


struct Info{
    double dist;
    int x;
    int y;
    char seta;
};
bool sominicial=true;

double distancia(int x1,int y1,int x2,int y2){

    return abs(sqrt((x2 - x1)*(x2 - x1) +  (y2 - y1)*(y2 - y1)));

}


int intencion = 0;
int anterior = 0;

enum MYKEYS{
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};


char MAPA[14][37]={
"111111111111111111111111111111111111",
"122222222222222222222222222222222221",
"121121211121211111111111211001121121",
"122221212121222222222222210000122221",
"111121211121211111211111210000121111",
"000021222221211111212222211111120000",
"111121111111211111211111212222121111",
"122222222222211111222221222112222221",
"121112112111211111211111211111121121",
"122222112222222222222222222222222221",
"111111111111111111111111111111111111",
};
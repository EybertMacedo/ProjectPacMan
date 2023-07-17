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

int bola=170;
int k=0,l=0;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *mapa   = NULL;
ALLEGRO_BITMAP *ulost  = NULL;
ALLEGRO_BITMAP *lost = NULL;
ALLEGRO_BITMAP *bolas   = NULL;
ALLEGRO_BITMAP *pacman   = NULL;
ALLEGRO_BITMAP *pac_up   = NULL;
ALLEGRO_BITMAP *pac_left   = NULL;
ALLEGRO_BITMAP *pac_down   = NULL;
ALLEGRO_BITMAP *pac_right   = NULL;
ALLEGRO_BITMAP *shutup   = NULL;
ALLEGRO_BITMAP *aux   = NULL; 
ALLEGRO_BITMAP *blinky   = NULL;
ALLEGRO_BITMAP *ghostyellow = NULL;
ALLEGRO_BITMAP *ghostgreen = NULL;
ALLEGRO_BITMAP *blue = NULL;
ALLEGRO_SAMPLE *sample = NULL;
ALLEGRO_SAMPLE *win = NULL;
ALLEGRO_SAMPLE *death = NULL;
ALLEGRO_SAMPLE *beggining = NULL;
ALLEGRO_FONT *font = NULL;

int ONE_BLOCK_SIZE = 32;
int i = 3 , j = 2 ; 
int r = 1, t = 27; 
int aX = 1, aY = 28; 
int vX = 1, vY = 29; 
int g = 1, h = 30;


bool gameover = false; 
bool playwaka = false;
bool acabar = false;


int posy = i*ONE_BLOCK_SIZE;
int posx = j*ONE_BLOCK_SIZE;

int bY = g*ONE_BLOCK_SIZE;
int bX = h*ONE_BLOCK_SIZE;

int blueX = t*ONE_BLOCK_SIZE;
int blueY = r*ONE_BLOCK_SIZE;

int yellowX = aY * ONE_BLOCK_SIZE;
int yellowY = aX * ONE_BLOCK_SIZE;

int greenX = vY *ONE_BLOCK_SIZE;
int greenY = vX *ONE_BLOCK_SIZE;


int lastRandomPos = -1;
int lastyellowPos = -1;
int lastbluePos = -1;
int lastgreenPos = -1;
int randomIndex = -1;




int lastmouth, sim=0;


bool redraw = true;
bool salir = false;

int ulx=g; 
int uly=h;

int lastyellowx=aX , lastyellowy=aY, lastbluex=r, lastbluey=t, lastgreenx=vX, lastgreeny=vY;
int lastpacmanx = i, lastpacmany = j, lastvermelhox=g, lastvermelhoy=h;

void blinkyMove(char M[][37],int &x, int &y, int &bX, int &bY) {

                
               
				if((x==8) && (y==11) && (j<=y)) { 
					ulx=x;
					uly=y;
					y--;
					bX = y*ONE_BLOCK_SIZE;
					return;
				}else if((x==8) && (y==11) && (j>=y)) {
					ulx=x;
					uly=y;
					y++;
					bX = y*ONE_BLOCK_SIZE;
					return;
				}
				Info arr[4]; 
				arr[0].dist= distancia(x+1,y,i,j); arr[0].x=x+1; arr[0].y=y;arr[0].seta='S';
				arr[1].dist= distancia(x,y-1,i,j); arr[1].x=x; arr[1].y=y-1;arr[1].seta='A';
				arr[2].dist= distancia(x-1,y,i,j); arr[2].x=x-1; arr[2].y=y;arr[2].seta='W';
				arr[3].dist= distancia(x,y+1,i,j); arr[3].x=x; arr[3].y=y+1;arr[3].seta='D';

				double less=600;
				int which=600;
				for(int c=0;c<4;c++){ 
						if((arr[c].dist<less) && (M[arr[c].x][arr[c].y]!='1')){
							if((arr[c].x!=ulx) || (arr[c].y!=uly)){
							  less=arr[c].dist;
							  which=c;
							}
						}
				}
				ulx=x;
				uly=y;


				if(which==0) {
					x++;
					bY = x*ONE_BLOCK_SIZE;
				}

				else if(which==2) {
					x--;
					bY = x*ONE_BLOCK_SIZE;
				}

				else if(which==3) {
					y++;
					bX = y*ONE_BLOCK_SIZE;
				}

				else if(which==1) {
					y--;
					bX = y*ONE_BLOCK_SIZE;
				}

				if(x == 6 && y == -1){
					x = 6;
					y = 23;
					bX = y*ONE_BLOCK_SIZE;
					bY = x*ONE_BLOCK_SIZE;
				}

				else if(x == 6 && y == 39){
					x = 6;
					y = -1;
					bX = y*ONE_BLOCK_SIZE;
					bY = x*ONE_BLOCK_SIZE;
				}
				

}

void semiSmart(char M[][37],int &x, int &y, int &gposX, int &gposY, int &lastThisPos) {

   
    
    int auxX = x;
    int auxY = y;


               
                if(i > x && M[auxX+1][y] != '1') {
                    if(lastThisPos == 0) return; 
                    lastThisPos = 1;
                    x++;
                    gposY = x*ONE_BLOCK_SIZE;
                }

                else if(i < x && M[auxX-1][y] != '1') {
                    if(lastThisPos == 1) return;
                    lastThisPos = 0;
                    x--;
                    gposY = x*ONE_BLOCK_SIZE;
                }

                else if(j > y && M[x][auxY+1] != '1') {
                    if(lastThisPos == 3) return;
                    lastThisPos = 2;
                    y++;
                    gposX = y*ONE_BLOCK_SIZE;
                }

                else if(j < y && M[x][auxY-1] != '1') {
                    if(lastThisPos == 2) return;
                    lastThisPos = 3;
                    y--;
                    gposX = y*ONE_BLOCK_SIZE;
                }

                else if(x == 6 && y == -1){
                    x = 6;
                    y = 23;
                    gposX = y*ONE_BLOCK_SIZE;
                    gposY = x*ONE_BLOCK_SIZE;
                }

                else if(x == 6 && y == 39){
                    x = 6;
                    y = -1;
                    gposX = y*ONE_BLOCK_SIZE;
                    gposY = x*ONE_BLOCK_SIZE;
                }


}

void randomMove(char M[][37],int &x, int &y, int &gposX, int &gposY, int phantom){

    int auxX = x;
    int auxY = y;

    srand(time(NULL));
    randomIndex= rand()%4;
    
    if(phantom == 1)
        srand(time(NULL));
    randomIndex = rand()%4;

    if(phantom == 2)
        srand(time(NULL));
    randomIndex = rand()%4;



    if(auxX == 6 && auxY == -1){
        x = 6;
        y = 39;
        gposX = y*ONE_BLOCK_SIZE;
        gposY = x*ONE_BLOCK_SIZE;
        return;
    }

    else if(auxX == 6 && auxY == 23){
        x = 6;
        y = 0;
        gposX = y*ONE_BLOCK_SIZE;
        gposY = x*ONE_BLOCK_SIZE;
        return;
    }

    if(randomIndex == 0 && M[auxX-1][y] != '1'){
        if(lastRandomPos == 1) return;
        lastRandomPos = 0;
        x--;
        gposY = x*ONE_BLOCK_SIZE;
    }

    else if(randomIndex == 1 && M[auxX+1][y] != '1'){
        if(lastRandomPos == 0) return;
        lastRandomPos = 1;
        x++;
        gposY = x*ONE_BLOCK_SIZE;
    }

    else if(randomIndex == 2 && M[x][auxY+1] != '1'){
        if(lastRandomPos == 3) return;
        lastRandomPos = 2;
        y++;
        gposX = y*ONE_BLOCK_SIZE;
    }

    else if(randomIndex == 3 && M[x][auxY-1] != '1'){
        if(lastRandomPos == 2) return;
        lastRandomPos = 3;
        y--;
        gposX = y*ONE_BLOCK_SIZE;
    }

    else
        semiSmart(M,x,y,gposX,gposY, randomIndex);

}
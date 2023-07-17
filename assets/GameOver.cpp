if(redraw && al_is_event_queue_empty(event_queue)){

            redraw = false;

			
            
            al_clear_to_color(al_map_rgb(0,0,0));
			
			
			
			
			if(!gameover)
				al_draw_bitmap(mapa,0,0,0);
			else{			
				al_draw_bitmap(ulost,350,0,0);
				
				al_destroy_sample(sample);
				al_play_sample(death, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
				al_rest(0.3);
				acabar=true;
				al_rest(0.3);
			}
			
			
			
            
			al_draw_textf(font, al_map_rgb(200, 200, 200), 0, 505, 0, "Score: %d", puntos);


            if (!acabar){
                for(k=0; k <37; k++){
                for (l=0; l<37; l++){
					if(bola == 0)
						continue;
                    else if(MAPA[k][l] == '2')
                        al_draw_bitmap(bolas,l*32,k*32,0);
                }
            }          
			al_draw_bitmap(pacman,posx,posy,0);
            al_draw_bitmap(ghostyellow,yellowX,yellowY,0);
            al_draw_bitmap(blinky,bX,bY,0);
            al_draw_bitmap(ghostgreen,greenX,greenY,0);
            al_draw_bitmap(blue, blueX,blueY,0);
			}

			
			randomMove(MAPA,r,t,blueX,blueY,0);
			
			if(contador >=70)
				randomMove(MAPA,aX,aY,yellowX,yellowY,1);
            
			if(contador >=140)
				randomMove(MAPA,vX,vY,greenX,greenY,2);
            
			if(contador >= 26)
				blinkyMove(MAPA,g,h,bX,bY);
			

            
            al_flip_display();

        }
		
		if(playwaka){
			al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
			playwaka = false;
		}
		
		if (sominicial){
            al_play_sample(beggining, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            sominicial=false;
			al_rest(3.1);
			playwaka = true;
        }
		
		
		
		
		
			if( (g==i && h==j) || (i==r && j==t) || (i==aX && j==aY) || (i==vX && j==vY)){
				gameover=true;
			}

        
        else if ((lastpacmanx==g && lastpacmany==h && i==ulx && j==uly) || 
                  (lastpacmanx==r && lastpacmany==t && i==lastbluex && j==lastbluey) ||
                  (lastpacmanx==aX && lastpacmany==aY && i==lastyellowx && j==lastyellowy) ||
                  (lastpacmanx==vX && lastpacmany==vY && i==lastgreenx && j==lastgreeny) ){
                    gameover=true;
                }
				
		if(acabar){
			al_destroy_bitmap(pacman);
			al_destroy_bitmap(bolas);
			al_destroy_bitmap(blinky);
			al_destroy_bitmap(blue);
			al_destroy_bitmap(ghostyellow);
			al_destroy_bitmap(ghostgreen);
            al_rest(3.92);
            return 0;
            }
			

		if(bola==0){
            al_destroy_sample(sample);
            al_play_sample(win, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            al_rest(4.8);
            return 0;
        }
       
    
        
        lastpacmanx=i; lastpacmany=j;
        lastvermelhox=g; lastvermelhoy=h;
        lastyellowx=aX; lastyellowy=aY;
        lastgreenx=vX; lastgreeny=vY;
        lastbluex=r; lastbluey=t;
		
		
    }
	
	

    al_destroy_bitmap(mapa);
    al_destroy_font(font);
    al_destroy_bitmap(pacman);
    al_destroy_bitmap(bolas);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_sample(sample);
    al_destroy_bitmap(blinky);
    al_destroy_bitmap(blue);
    al_destroy_bitmap(ghostyellow);
    al_destroy_bitmap(ghostgreen);
	al_destroy_bitmap(lost);

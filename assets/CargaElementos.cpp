bool comecou;

int inicializa() {
    if(!al_init())
    {
        cout << "Fallo al inicializar allegro" << endl;
        return 0;
    }
    if(!al_install_keyboard())
    {
        cout << "Fallo al inicializar teclado" << endl;
        return 0;
    }
    timer = al_create_timer(0.8 / FPS);
    if(!timer)
    {
        cout << "Fallo al inicializar temporizador" << endl;
        return 0;
    }

   if(!al_install_audio()){
      fprintf(stderr, "Fallo al inicializar audio!\n");
      return -1;
   }

   if(!al_init_acodec_addon()){
      fprintf(stderr, "Fallo al inicializar audio codecs!\n");
      return -1;
   }

   if (!al_reserve_samples(2)){
      fprintf(stderr, "Fallo al reservar samples!\n");
      return -1;
   }
    win = al_load_sample("assets/sounds/you win.wav" );
    death = al_load_sample("assets/sounds/wasted.wav" );

    beggining = al_load_sample("assets/sounds/beggining.wav" );
    if(!win){
        printf("Winning audio clip sample not loaded! \n");
        return -1;
    }
    if(!death){
        printf("Death clip sample not loaded! \n");
        return -1;
    }
    if(!beggining){
        printf("Beggining clip sample not loaded! \n");
        return -1;
    }
    
    sample = al_load_sample("assets/sounds/waka.wav" ); 

   if (!sample){
      printf( "Audio clip sample not loaded!\n" );
      return -1;
   }
   
	

    if(!al_init_image_addon())
    {
        cout <<"Falla al iniciar al_init_image_addon!" << endl;
        return 0;
    }

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        cout << "Falla al inicializar a tela" << endl;
        al_destroy_timer(timer);
        return 0;
    }

	
    mapa = al_load_bitmap("assets/maps/map.png");
    if(!mapa)
    {
        cout << "Falla al cargar el mapa!" << endl;
        al_destroy_display(display);
        return 0;
    }
    al_draw_bitmap(mapa,0,0,0);
	
	
	ulost = al_load_bitmap("assets/maps/ulost.png");
    if(!ulost)
    {
        cout << "Falla al cargar el mapa 2!" << endl;
        al_destroy_display(display);
        return 0;
    }
	
	lost = al_load_bitmap("assets/maps/mapmorte.bmp");
    if(!lost)
    {
        cout << "Falla al cargar la imagen mapmorte.bmp!" << endl;
        al_destroy_display(display);
        return 0;
    }
    

    pacman = al_load_bitmap("assets/characters/pacman/pacman.png");
    pac_up = al_load_bitmap("assets/characters/pacman/pac_up.png");
    pac_down = al_load_bitmap("assets/characters/pacman/pac_down.png");
    pac_left = al_load_bitmap("assets/characters/pacman/pac_left.png");
    pac_right = al_load_bitmap("assets/characters/pacman/pac_right.png");
	shutup = al_load_bitmap("assets/characters/pacman/shutup.png");
	blinky = al_load_bitmap("assets/characters/ghosts/blinky.png");
	blue = al_load_bitmap("assets/characters/ghosts/blue.png");
	ghostyellow = al_load_bitmap("assets/characters/ghosts/yellow.png");
	ghostgreen = al_load_bitmap("assets/characters/ghosts/green.png");

    if(!pacman)
    {
        cout << "Falla al cargar el pacman!" << endl;
        al_destroy_display(display);

        return 0;
    }
    al_draw_bitmap(pacman,posx,posy,0);

     if(!blinky)
    {
        cout << "Falla al cargar el Blinky!" << endl;
        al_destroy_display(display);

        return 0;
    }
    al_draw_bitmap(blinky,bX,bY,0);

    if(!blue)
    {
        cout << "Falla al cargar el fantasma blue!" << endl;
        al_destroy_display(display);

        return 0;
    }
    al_draw_bitmap(blue,blueX,blueY,0);

    if(!ghostyellow)
    {
        cout << "Falla al cargar el fantasma yellow!" << endl;
        al_destroy_display(display);

        return 0;
    }
    al_draw_bitmap(ghostyellow,yellowX,yellowY,0);

    if(!ghostgreen)
    {
        cout << "Falla al cargar el fantasma green!" << endl;
        al_destroy_display(display);

        return 0;
    }
    al_draw_bitmap(ghostgreen,greenX,greenY,0);


    bolas = al_load_bitmap("assets/maps/bolas.png");
    if(!bolas)
    {
        cout << "Falla al cargar las bolas!" << endl;
        al_destroy_display(display);
        return 0;
    }
    al_draw_bitmap(bolas,k*32,l*32,0);

    al_init_font_addon();
    al_init_ttf_addon();

    if (!al_init_ttf_addon())
    {
        cout<< "Falla al inicializar add-on allegro_ttf."<<endl;;
        return -1;
    }

      font = al_load_font("/usr/share/fonts/truetype/liberation/LiberationMono-Bold.ttf", 28, 0);
      if (!font)
    {
        font = al_load_font("C:/Windows/Fonts/OCRAEXT.ttf", 28, 0);
    }
      if (!font)
    {
        al_destroy_display(display);
        cout<< "Falla al cargar font."<<endl;
        return -1;
    }

    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        cout << "Falla al criar a fila de eventos" << endl;
        al_destroy_display(display);
        al_destroy_timer(timer);
        return 0;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
    al_start_timer(timer);

    return 1;
}

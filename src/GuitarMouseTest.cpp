#include <allegro.h>
#include <stdio.h>
#include <conio.h>
#define WEIGHT 680
#define HEIGHT 420
void playSong(char song) {

    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Erro na inicialização do som\n%s\n", allegro_error);
    }

    if(song == 'e') {
        SAMPLE *song = load_wav("E1.wav");
        play_sample(song, 200, 150, 1000,0);
    }else if(song == 'B') {
        SAMPLE *song = load_wav("B2.wav");
        play_sample(song, 200, 150, 1000,0);

    }else if(song == 'G') {
        SAMPLE *song = load_wav("G3.wav");
        play_sample(song, 200, 150, 1000,0);

    }else if(song == 'D') {
        SAMPLE *song = load_wav("D4.wav");
        play_sample(song, 200, 150, 1000,0);

    }else if(song == 'A') {
        SAMPLE *song = load_wav("A5.wav");
        play_sample(song, 200, 150, 1000,0);

    }else if(song == 'E') {
        SAMPLE *song = load_wav("E6.wav");
        play_sample(song, 200, 150, 1000,0);
    }

}

void setup_window() {

        set_color_depth(32);
        set_gfx_mode(GFX_AUTODETECT_WINDOWED, WEIGHT, HEIGHT, 0, 0);
        BITMAP *buffer = create_bitmap(WEIGHT, HEIGHT);

        //rectfill(buffer, 2, 2, WEIGHT-4, HEIGHT-4, 0xC0C0C0);
           //Cor dentro do display
       //rectfill(buffer, 30, 30, WEIGHT-30, HEIGHT-30,  0x008080);
        BITMAP *fundo = load_bitmap("fundo.BMP",NULL);
        BITMAP *cursor = load_bitmap("cursor.BMP", NULL);


        while(!key[KEY_ESC]){
            if( key[KEY_A])
                playSong('e');
            if( key[KEY_S] )
                playSong('B');
            if( key[KEY_D] )
                playSong('G');
            if( key[KEY_H] )
                playSong('D');
            if( key[KEY_J] )
                playSong('A');
            if( key[KEY_K] )
                playSong('E');


        if(mouse_x >= 0 && mouse_x < 100
           && mouse_y >= 0 && mouse_y < 100)
        {
            rectfill(buffer, 0, 100, 0, 100, makecol(255,255,0));
     //       rectfill(buffer, 2, 2, WEIGHT-30, HEIGHT-10,  0xFFFFFF);
            rectfill(buffer,0,100,0,100,makecol(255,200,200));
          /* Função do botão*/
            if(mouse_b == 1 )
          {
             playSong('e');
          }
          if(mouse_b == 2)
          {
              textout_ex(buffer, font, "Nota ' e ' a ser pressionada!", 50, 50, makecol(255,255,255), -1);
          }
        }
        else if(mouse_x >= 100 && mouse_x < 200 && mouse_y >= 100 && mouse_y < 200){
                         if(mouse_b == 1 ){
                            playSong('B');
                         }
                        else if(mouse_b == 2){
                            textout_ex(buffer, font, "Nota ' B ' a ser pressionada!", 150, 150, makecol(255,255,255), -1);
                }
        }
        else if(mouse_x >= 200 && mouse_x < 300 && mouse_y >= 200 && mouse_y < 300){
            if(mouse_b == 1){
                playSong('G');
            }
            else if(mouse_b == 2){
              textout_ex(buffer, font, "Nota ' G ' a ser pressionada!", 250, 250, makecol(255,255,255), -1);
            }
        }
        else if(mouse_x >= 300 && mouse_x < 400 && mouse_y >= 300 && mouse_y <= 400){
            if(mouse_b == 1){
                playSong('D');
            }
            else if(mouse_b == 2){
                 textout_ex(buffer, font, "Nota ' D ' a ser pressionada!", 350, 350, makecol(255,255,255), -1);
            }
        }
        else if(mouse_x >= 400 && mouse_x < 500 && mouse_y >= 100 && mouse_y < 200){
            if(mouse_b == 1){
                playSong('A');
            }
            else if(mouse_b == 2){
                  textout_ex(buffer, font, "Nota ' A ' a ser pressionada!", 450, 150, makecol(255,255,255), -1);
            }
        }
        else if(mouse_x >= 400 && mouse_x < 500 && mouse_y >= 200 && mouse_y < 300){
            if(mouse_b == 1){
                playSong('E');
            }
            else if(mouse_b == 2){
                 textout_ex(buffer, font, "Nota ' E ' a ser pressionada!", 450, 250, makecol(255,255,255), -1);
            }
        }

        //LOCALIZACAO DAS NOTAS
        textout_ex(buffer, font, "e", 50, 50, makecol(255,0,0), -1);
        textout_centre_ex(buffer,font,"B", 150, 150, makecol(255,0,0), -1);
        textout_centre_ex(buffer,font,"G", 250, 250, makecol(255,0,0), -1);

         textout_centre_ex(buffer,font,"D", 350, 350, makecol(255,0,0), -1);
         textout_ex(buffer, font, "A", 450, 150, makecol(255,0,0), -1);
         textout_ex(buffer, font, "E", 450, 250, makecol(255,0,0), -1);

        //DRAW
        draw_sprite(buffer, cursor, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);
        //draw_sprite(fundo,screen,WEIGHT,HEIGHT);
         //Testando os audios
        clear(buffer);
        //LIMPA O BUFFER E "RECOLORE" A TELA
        rectfill(buffer, 2, 2, WEIGHT-4, HEIGHT-4, 0xC0C0C0);
       // rectfill(fy,2, 2, WEIGHT-4, HEIGHT-4, 0xC0C0C0);
        rectfill(buffer, 30, 30, WEIGHT-30, HEIGHT-30,  0x008080);


    }
   // blit(fundo,buffer,0,0,0,0,WEIGHT,HEIGHT);
    blit(buffer,screen,0,0,0,0,WEIGHT,HEIGHT);
        destroy_bitmap(cursor);
        destroy_bitmap(buffer);
           //Cor fora do display
}

	   //Função q definirá os botões na tela deve ser chamada aqui

	   // Funções on-click chamadas aqui
            // Funções on-click chamarão a função playSong() passando a nota como parametro

int main()
{
    allegro_init();
    install_mouse();
    install_timer();
	install_keyboard();
    setup_window();
	return 0;
}
END_OF_MAIN();

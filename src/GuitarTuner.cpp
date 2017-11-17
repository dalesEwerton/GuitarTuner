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

void play_app(){
        //Inicializando o buffer
        set_color_depth(32);
        set_gfx_mode(GFX_AUTODETECT_WINDOWED, WEIGHT, HEIGHT, 0, 0);
        BITMAP *buffer = create_bitmap(WEIGHT, HEIGHT);

        //Carregando as imagens
        BITMAP *background = load_bitmap("background.bmp",NULL);
        BITMAP *cursor = load_bitmap("cursor.BMP", NULL);

        //Repetição da rotina de afinação
        while(!key[KEY_ESC]){
        /*Afinação das cordas via teclado*/
            if( key[KEY_S])
                playSong('e');

            if( key[KEY_B] )
                playSong('B');

            if( key[KEY_G] )
                playSong('G');

            if( key[KEY_D] )
                playSong('D');

            if( key[KEY_A] )
                playSong('A');

            if( key[KEY_E] )
                playSong('E');

        /*Coordenadas x e y, definidas pelos limites
        afinaçao via mouse*/
        if(mouse_x >= 170 && mouse_x < 250
           && mouse_y >= 50 && mouse_y < 130) {
            if(mouse_b == 1 ) {
             playSong('e');
          }
            else if(mouse_b == 2) {
              textout_ex(buffer, font, "Nota ' e ' a ser pressionada!", 170, 30, makecol(0,0,255), -1);
          }
        }
        else if(mouse_x >= 280 && mouse_x < 360 && mouse_y >= 70 && mouse_y < 130){
                         if(mouse_b == 1 ){
                            playSong('A');
                         }
                        else if(mouse_b == 2){
                            textout_ex(buffer, font, "Nota ' A ' a ser pressionada!", 170, 30, makecol(0,0,255), -1);
                }
        }
        else if(mouse_x >= 380 && mouse_x < 460 && mouse_y >= 70 && mouse_y < 130){
            if(mouse_b == 1){
                playSong('D');
            }
            else if(mouse_b == 2){
              textout_ex(buffer, font, "Nota ' D ' a ser pressionada!", 170, 30, makecol(0,0,255), -1);
            }
        }

        else if(mouse_x >= 170 && mouse_x < 250 && mouse_y >= 280 && mouse_y <= 370){
            if(mouse_b == 1){
                playSong('E');
            }
            else if(mouse_b == 2){
                 textout_ex(buffer, font, "Nota ' E ' a ser pressionada!", 170, 30, makecol(0,0,255), -1);
            }
        }

        else if(mouse_x >= 290 && mouse_x < 350 && mouse_y >= 300 && mouse_y < 370){
            if(mouse_b == 1){
                playSong('B');
            }
            else if(mouse_b == 2){
                  textout_ex(buffer, font, "Nota ' B ' a ser pressionada!", 170, 30, makecol(0,0,255), -1);
            }
        }

        else if(mouse_x >= 390 && mouse_x < 450 && mouse_y >= 300 && mouse_y < 370){
            if(mouse_b == 1){
                playSong('G');
            }
            else if(mouse_b == 2){
                 textout_ex(buffer, font, "Nota ' G ' a ser pressionada!", 170, 30, makecol(0,0,255), -1);
            }
        }

        draw_sprite(buffer, cursor, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        /*limpa o buffer para o próximo loop*/
        clear(buffer);
        //LIMPA O BUFFER E "RECOLORE" A TELA
        rectfill(buffer, 2, 2, WEIGHT-4, HEIGHT-4, 0xC0C0C0);

        rectfill(buffer, 30, 30, WEIGHT-30, HEIGHT-30,  0x008080);

        blit(background,buffer,0,0,0,0,WEIGHT,HEIGHT);

    }
    /*liberar memoria */
        destroy_bitmap(cursor);
        destroy_bitmap(buffer);
        destroy_bitmap(background);
}


int main()
{
    allegro_init();
    set_window_title("Guitar Tuner");
    install_mouse();
    install_timer();
	install_keyboard();
    play_app();
	return 0;
}
END_OF_MAIN();

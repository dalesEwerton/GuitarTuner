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

            //Fecha a janela ao apertar 'esc' POR ENQUANTO
    while ( !key[KEY_ESC] ) {

        //Testando os audios
        if( key[KEY_A] )
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

       //Cor fora do display
	   rectfill(buffer, 2, 2, WEIGHT-4, HEIGHT-4, 0xC0C0C0);
	   //Cor dentro do display
	   rectfill(buffer, 30, 30, WEIGHT-30, HEIGHT-30,  0x008080);
	   blit(buffer, screen, 0, 0, 0, 0, WEIGHT, HEIGHT);

	   //Função q definirá os botões na tela deve ser chamada aqui

	   // Funções on-click chamadas aqui
            // Funções on-click chamarão a função playSong() passando a nota como parametro


    }

	destroy_bitmap(buffer);
}


int main()
{

    allegro_init();
	install_keyboard();
    setup_window();


	return 0;
}
END_OF_MAIN();

#include <allegro.h>
#define WEIGHT 680
#define HEIGHT 420

void setup_window() {

	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, WEIGHT, HEIGHT, 0, 0);

	BITMAP *buffer = create_bitmap(WEIGHT, HEIGHT);

            //Fecha a janela ao apertar 'esc' POR ENQUANTO
    while ( !key[KEY_ESC] ) {

       //Cor fora do display
	   rectfill(buffer, 2, 2, WEIGHT-4, HEIGHT-4, 0xC0C0C0);
	   //Cor dentro do display
	   rectfill(buffer, 30, 30, WEIGHT-30, HEIGHT-30,  0x008080);

	   blit(buffer, screen, 0, 0, 0, 0, WEIGHT, HEIGHT);
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

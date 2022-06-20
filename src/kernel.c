#include "io/io.h"
#include "graphics/graphics.h"
#include "io/keyboard.h"
#include "system/interrupts.h"
#include "system/timer.h"
#include "views/home_view.h"
#include "system/scheduler.h"
#include "system/memory.h"


#define RUN 1
#define WIDTH 1920
#define HEIGHT 1080
#define MIN 0
#define MAX 1080
#define STEP_SIZE 20


int length_of_array(const char *);

int m = 0;
int counter = 0;

int step_flag = 0;


struct Henk {
    int x;
    int y;
    int width;
    int height;
};  


struct Henk rectangle;


void verplaats(struct Henk *p, int stepx, int stepy)
{
    moveRect(p->x, p->y, p->width, p->height, STEP_SIZE, 1, 0x0F);

    if (p->x < MIN) {
        step_flag = 0;
    } else if (p->x > MAX) {
        step_flag = 1;
    }

    switch (step_flag)
    {
        case 0: 
            p->x = p->x + stepx;
        break;
        case 1:
            p->x = p->x - stepx;
        break;
    }
    
    p->y = p->y + stepy;
}



/**
 * @brief Hoofdfunctie
 */
void main()
{
    uart_init(1);
    graphics_init();
    // init_memory();
    // init_scheduler();
    // init_screen();

    // load_timer_app();

    // draw_string(400, 800, "Nog een test", 0x0f, 9);

    // load_timer_app();

    // timer_load(0);
    // timer_init();

    home_screen_init();

    while (RUN) {
        home_screen_draw();      

        // if (m <= MIN) {
        //     m += STEP_SIZE;
        // } else if (m >= MAX) {
        //     m += -STEP_SIZE;
        // }

        // counter++;

        // clear_screen(0x00);
        
        // check_key();
        // key_pressed("print");
    }
}   
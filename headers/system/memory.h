#ifndef __SYSTEM__MEMORY__
#define __SYSTEM__MEMORY__


#define SCREEN_WIDTH    1920
#define SCREEN_HEIGHT   1080


/**
 * @brief Structure voor het opslaan van informatie over een pixel van het scherm
 * 
 */
#pragma pack(1)
struct Pixel 
{
    unsigned int x;
    unsigned int y;
    unsigned long address;
    unsigned char curcolor;
};

extern volatile struct Pixel *screen_buffer[SCREEN_WIDTH][SCREEN_HEIGHT];


void memory_push(unsigned int, unsigned long, unsigned int);
void memory_push_with_process_id(unsigned int, unsigned long, unsigned int, unsigned int);
struct MemoryBlock *memory_load_with_process_id(unsigned int, unsigned int);
struct MemoryBlock *memory_free(unsigned int);
unsigned int count_process_by_process_id(unsigned int);
void stack_push(unsigned int, unsigned long);
struct MemoryBlock *stack_pop();
void pixel_buffer_set(unsigned int, unsigned int, unsigned int, unsigned char);
struct Pixel *pixel_buffer_get(unsigned int, unsigned int);


#endif  
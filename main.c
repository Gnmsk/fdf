#include "fdf.h"
#include <stdio.h>

int keyboard(int key)
{
    if (key == 53)
    {
        exit(0);
    }
    else
        write(1, "PRESS ESC", 9);
    return (0);
}

int main(void)
{
    void *a;
    void *win;
    char name[] = "new window";
    int i;
    int j;
    
    i = 0;
    a = mlx_init();
    win = mlx_new_window(a, 1000, 1000, name);
    while (i < 100)
    {
        j = 0;
        while(j < 100)
        {
            mlx_pixel_put(a, win, i, j, 0xFFFFFF);
            j++;
        }
        i++;
    }
    mlx_string_put(a, win, i, j, 0xFFFFFF, "text");
    mlx_hook(win, 2, 0, keyboard, 0);
    mlx_loop(a);
    return (0);
}
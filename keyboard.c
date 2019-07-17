#include "fdf.h"

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

#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.141

void koch(float x1, float y1,
          float x2, float y2, int depth)
{
    float dx, dy;
    float x3, y3, x4, y4;
    float x5, y5;

    if(depth == 0)
    {
        line(x1, y1, x2, y2);
        return;
    }


    dx = (x2 - x1) / 3.0;
    dy = (y2 - y1) / 3.0;

    x3 = x1 + dx;
    y3 = y1 + dy;

    x4 = x1 + 2 * dx;
    y4 = y1 + 2 * dy;



    x5 = x3 + dx * cos(PI / 3)
            + dy * sin(PI / 3);

    y5 = y3 - dx * sin(PI / 3)
            + dy * cos(PI / 3);


    koch(x1, y1, x3, y3, depth - 1);

    koch(x3, y3, x5, y5, depth - 1);

    koch(x5, y5, x4, y4, depth - 1);

    koch(x4, y4, x2, y2, depth - 1);
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");


    koch(150, 300, 490, 300, 3);


    getch();
    closegraph();

    return 0;
}

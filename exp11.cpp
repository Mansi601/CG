
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int maxx, maxy, midx, midy;

int x1 = 50, y1 = -100;
int x2 = 60, y2 = -90;

void axis()
{
    setcolor(WHITE);
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
}


int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    maxx = getmaxx();
    maxy = getmaxy();

    midx = maxx/2;
    midy = maxy/2;
    
    axis();
    bar3d(midx+x1, midy+y1, midx+x2, midy+y2, 40, 1);

    float sx, sy;
    printf("Enter sx and sy: ");
    scanf("%f%f", &sx, &sy);
    x1 = x1*sx;
    y1 = y1*sy;
    x2 = x2*sx;
    y2 = y2*sy;

    float angle, rad;
    float nx1, ny1, nx2, ny2;
    printf("Enter angle: ");
    scanf("%f", &angle);

    rad = angle * PI / 180;

    nx1 = x1*cos(rad) - y1*sin(rad);
    ny1 = x1*sin(rad) + y1*cos(rad);

    nx2 = x2*cos(rad) - y2*sin(rad);
    ny2 = x2*sin(rad) + y2*cos(rad);

    x1 = nx1;
    y1 = ny1;
    x2 = nx2; 
    y2 = ny2;

    y1 = -y1 ;
    y2 = -y2 ;

    float shx, shy;
    printf("Enter shx and shy: ");
    scanf("%f%f", &shx, &shy);
    int tx1 , tx2 , ty1 , ty2;

    tx1 = x1 + shx*y1;
    ty1 = y1 + shy*x1;

    tx2 = x2 + shx*y2;
    ty2 = y2 + shy*x2;

    x1 = tx1;
    x2 = tx2;
    y1 = ty1;
    y2 = ty2;

    int tx, ty;
    printf("Enter tx and ty: ");
    scanf("%d%d", &tx, &ty);

    y1 = y1+ty;
    x1 = x1+tx;
    x2 = x2+tx;
    y2 = y2+ty;

    axis();
   bar3d(midx+x1, midy+y1, midx+x2, midy+y2, 40, 1);

    getch();
    closegraph();

    return 0;
}

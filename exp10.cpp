
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int maxx, maxy, midx, midy;

int x1 = 100, y1 = -150;
int x2 = 140, y2 = -110;

void axis()
{
    setcolor(WHITE);
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
}

void original()
{
    setcolor(WHITE);
    bar3d(midx+x1, midy+y1,
          midx+x2, midy+y2, 30, 1);
}

void translation()
{
    int tx, ty;

    cleardevice();
    axis();
    original();

    printf("Enter tx and ty: ");
    scanf("%d%d", &tx, &ty);

    getch();

    setcolor(YELLOW);

    bar3d(midx+x1+tx, midy+y1+ty,
          midx+x2+tx, midy+y2+ty, 30, 1);

    getch();
}

void scaling()
{
    float sx, sy;

    cleardevice();
    axis();
    original();

    printf("Enter sx and sy: ");
    scanf("%f%f", &sx, &sy);

    getch();

    setcolor(YELLOW);

    bar3d(midx+x1*sx, midy+y1*sy,
          midx+x2*sx, midy+y2*sy, 30, 1);

    getch();
}

void rotation()
{
    float angle, rad;
    float nx1, ny1, nx2, ny2;

    cleardevice();
    axis();
    original();

    printf("Enter angle: ");
    scanf("%f", &angle);

    rad = angle * PI / 180;

    nx1 = x1*cos(rad) - y1*sin(rad);
    ny1 = x1*sin(rad) + y1*cos(rad);

    nx2 = x2*cos(rad) - y2*sin(rad);
    ny2 = x2*sin(rad) + y2*cos(rad);

    getch();

    setcolor(YELLOW);

    bar3d(midx+nx1, midy+ny1,
          midx+nx2, midy+ny2, 30, 1);

    getch();
}

void reflection()
{
    int nx1, ny1, nx2, ny2;

    cleardevice();
    axis();
    original();

    nx1 = x1;
    ny1 = -y1;

    nx2 = x2;
    ny2 = -y2;

    getch();

    setcolor(YELLOW);

    bar3d(midx+nx1, midy+ny1,
          midx+nx2, midy+ny2, 30, 1);

    getch();
}

void shearing()
{
    float shx, shy;
    float nx1, ny1, nx2, ny2;

    cleardevice();
    axis();
    original();

    printf("Enter shx and shy: ");
    scanf("%f%f", &shx, &shy);

    nx1 = x1 + shx*y1;
    ny1 = y1 + shy*x1;

    nx2 = x2 + shx*y2;
    ny2 = y2 + shy*x2;

    getch();

    setcolor(YELLOW);

    bar3d(midx+nx1, midy+ny1,
          midx+nx2, midy+ny2, 30, 1);

    getch();
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    maxx = getmaxx();
    maxy = getmaxy();

    midx = maxx/2;
    midy = maxy/2;

    translation();
    rotation();
    scaling();
    shearing();
    reflection();

    cleardevice();
    axis();


    getch();
    closegraph();

    return 0;
}

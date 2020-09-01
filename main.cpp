#include "TimeTick.h"

void Display(int StartX, int StartY, COLORREF WordColor = BLUE, COLORREF BackgroundColor = WHITE);

int main()
{
    initgraph(WIDTH, HEIGHT);
    Display(30, 10, YELLOW);
    //system("pause");
    return 0;
}


void Display(int StartX, int StartY, COLORREF WordColor, COLORREF BackgroundColor)
{
    while (true)
    {
        setfillcolor(BackgroundColor);
        bar(0, 0, WIDTH, HEIGHT);
        setfillcolor(WordColor);
        drawTime(StartX, StartY);
        Sleep(995);
        cleardevice();
        if (_kbhit())
        {
            break;
        }
    }
}

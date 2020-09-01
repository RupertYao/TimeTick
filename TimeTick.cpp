#include "TimeTick.h"

void drawTime(int StartX, int StartY)
{
    time_t t = time(NULL);
    tm tmp;
    localtime_s(&tmp, &t);
    char TStr[10];
    strftime(TStr, sizeof(TStr), "%H-%M-%S", &tmp);
    drawTimeString(StartX, StartY, TStr);
}

void drawTimeString(int StartX, int StartY, const char TStr[])
{
    int len = strlen(TStr);
    int tmpX, tmpY;
    for (int i = 0; i < len; i++)
    {
        tmpX = StartX + i * (WORD_SIZE + SPACE_BETWEEN_WORD + 2 * LINE_WIDTH);
        tmpY = StartY;
        if (TStr[i] >= '0' && TStr[i] <= '9')
        {
            drawNumber(tmpX, StartY, TStr[i]);
        }
        else
        {
            fillcircle(tmpX + LINE_WIDTH + WORD_SIZE / 2, tmpY + LINE_WIDTH + WORD_SIZE / 2, LINE_WIDTH / 2);
            circle(tmpX + LINE_WIDTH + WORD_SIZE / 2, tmpY + LINE_WIDTH + WORD_SIZE / 2, LINE_WIDTH / 2);
            fillcircle(tmpX + LINE_WIDTH + WORD_SIZE / 2, tmpY + LINE_WIDTH * 2 + 3 * WORD_SIZE / 2, LINE_WIDTH / 2);
            circle(tmpX + LINE_WIDTH + WORD_SIZE / 2, tmpY + LINE_WIDTH * 2 + 3 * WORD_SIZE / 2, LINE_WIDTH / 2);
        }
    }
}

void drawNumber(int StartX, int StartY, char numChar)
{
    int X = StartX;
    int Y = StartY;
    /*
          a
        -----
      f|     |b
       |  g  |
        -----
      e|     |c
       |     |
        -----
          d
    */
    //�ƶ���a����ʼλ��
    X = X + LINE_WIDTH;
    // a ��
    if (numChar == '0' || numChar == '2'
        || numChar == '3' || numChar == '5'
        || numChar == '6' || numChar == '7'
        || numChar == '8' || numChar == '9')
    {
        bar(X, Y, X + WORD_SIZE, Y + LINE_WIDTH);
    }
    //�Ƶ�b����ʼλ��
    X = X + WORD_SIZE;
    Y = Y + LINE_WIDTH;
    // b ��
    if (numChar == '0' || numChar == '1'
        || numChar == '2' || numChar == '3'
        || numChar == '4' || numChar == '7'
        || numChar == '8' || numChar == '9')
    {
        bar(X, Y, X + LINE_WIDTH, Y + WORD_SIZE);
    }
    //�ƶ���c����ʼλ��
    Y = Y + WORD_SIZE + LINE_WIDTH;
    // c ��
    if (numChar == '0' || numChar == '1'
        || numChar == '3' || numChar == '4'
        || numChar == '5' || numChar == '6'
        || numChar == '7' || numChar == '8'
        || numChar == '9')
    {
        bar(X, Y, X + LINE_WIDTH, Y + WORD_SIZE);
    }
    //�ƶ���d����ʼλ��
    Y = Y + WORD_SIZE + LINE_WIDTH;
    // d ��
    if (numChar == '0' || numChar == '2'
        || numChar == '3' || numChar == '5'
        || numChar == '6' || numChar == '8'
        || numChar == '9')
    {
        bar(X - WORD_SIZE, Y - LINE_WIDTH, X, Y);
    }
    //�ƶ���e����ʼλ��
    X = X - WORD_SIZE;
    Y = Y - LINE_WIDTH;
    // e ��
    if (numChar == '0' || numChar == '2'
        || numChar == '6' || numChar == '8')
    {
        bar(X - LINE_WIDTH, Y - WORD_SIZE, X, Y);
    }
    //�ƶ���f����ʼλ��
    Y = Y - WORD_SIZE - LINE_WIDTH;
    // f ��
    if (numChar == '0' || numChar == '4'
        || numChar == '5' || numChar == '6'
        || numChar == '8' || numChar == '9')
    {
        bar(X - LINE_WIDTH, Y - WORD_SIZE, X, Y);
    }
    // g ��
    if (numChar == '2' || numChar == '3'
        || numChar == '4' || numChar == '5'
        || numChar == '6' || numChar == '8'
        || numChar == '9')
    {
        bar(X, Y, X + WORD_SIZE, Y + LINE_WIDTH);
    }
}
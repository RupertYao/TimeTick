#ifndef TIMETICK_H
#define TIMETICK_H

#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>

#define WIDTH 500
#define HEIGHT 300
#define WORD_SIZE 30
#define SPACE_BETWEEN_WORD 20
#define LINE_WIDTH 4

void drawNumber(int StartX, int StartY, char numChar);
void drawTimeString(int StartX, int StartY, const char TStr[]);
void drawTime(int StartX, int StartY);

#endif
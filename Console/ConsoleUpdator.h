#pragma once

#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _WINDOWS_
#include <Windows.h>
#endif

enum CURSOR_POSITION
{
	x = 1,
	y
};

void
SetCursor(int x, int y)
{
	COORD cursor;
	cursor.X = x;
	cursor.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

int
GetCursor(CURSOR_POSITION t)
{
	CONSOLE_SCREEN_BUFFER_INFO console_info;
	switch (t)
	{
	case CURSOR_POSITION::x:
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_info);
		return console_info.dwCursorPosition.Y;

	case CURSOR_POSITION::y:
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_info);
		return console_info.dwCursorPosition.Y;
	}

	return -1;
}
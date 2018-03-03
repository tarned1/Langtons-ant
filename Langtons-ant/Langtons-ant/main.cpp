#include<iostream>
#include<Windows.h>
#include<conio.h>

using namespace std;

#define SIZE_X 500
#define SIZE_Y 500

struct ant {
	int antX;
	int antY;
	int before;
};

void print_board(bool[][SIZE_Y]);
void print_char(bool[][SIZE_Y], int, int);
void gotoxy(int, int);

int main()
{
	bool array[SIZE_X][SIZE_Y] = { 0 };

	ant tant;
	tant.antX = SIZE_X / 2;
	tant.antY = SIZE_Y / 2;
	tant.before = 0;
	while (1)
	{
		Sleep(1);
		gotoxy(tant.antY, tant.antX);
		if (!array[tant.antX][tant.antY])
		{
			array[tant.antX][tant.antY] = 1;
			print_char(array, tant.antX, tant.antY);
			if (!tant.before)
			{
				--tant.antX;
				if (!tant.antX)
				{
					tant.antX = SIZE_X - 1;
					tant.antY = SIZE_Y - tant.antY;
				}
				tant.before = 3;
			}
			else if (tant.before == 3)
			{
				--tant.antY;
				if (!tant.antY)
				{
					tant.antY = SIZE_Y - 1;
					tant.antX = SIZE_X - tant.antX;
				}
				tant.before = 2;
			}
			else if (tant.before == 2)
			{
				++tant.antX;
				if (tant.antX == SIZE_X)
				{
					tant.antX = 0;
					tant.antY = SIZE_Y - tant.antY;
				}
				tant.before = 1;
			}
			else if (tant.before == 1)
			{
				++tant.antY;
				if (tant.antY == SIZE_Y)
				{
					tant.antY = 0;
					tant.antX = SIZE_X - tant.antX;
				}
				tant.before = 0;
			}
		}
		else
		{
			array[tant.antX][tant.antY] = 0;
			print_char(array, tant.antX, tant.antY);
			if (!tant.before)
			{
				++tant.antX;
				if (tant.antX == SIZE_X)
				{
					tant.antX = 0;
					tant.antY = SIZE_Y - tant.antY;
					tant.before = 1;
				}
				tant.before = 1;
			}
			else if (tant.before == 3)
			{
				++tant.antY;
				if (tant.antY == SIZE_Y)
				{
					tant.antY = 0;
					tant.antX = SIZE_X - tant.antX;
				}
				tant.before = 0;
			}
			else if (tant.before == 2)
			{
				--tant.antX;
				if (!tant.antX)
				{
					tant.antX = SIZE_X - 1;
					tant.antY = SIZE_Y - tant.antY;
				}
				tant.before = 3;
			}
			else if (tant.before == 1)
			{
				--tant.antY;
				if (!tant.antY)
				{
					tant.antY = SIZE_Y - 1;
					tant.antX = SIZE_X - tant.antX;
				}
				tant.before = 2;
			}
		}
	}

	return 0;
}
void print_char(bool array[][SIZE_Y], int x, int y)
{
	if (array[x][y])
		cout << '#';
	else
		cout << ' ';
}
void print_board(bool array[][SIZE_Y])
{
	for (int i = 0; i < SIZE_X; ++i)
	{
		for (int j = 0; j < SIZE_Y; ++j)
		{
			if (!array[i][j])
				cout << ' ';
			else
				cout << '#';
		}
		cout << endl;
	}
}
void gotoxy(int column, int line)
{
	COORD coord;
	coord.Y = column;
	coord.X = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
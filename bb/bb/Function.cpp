#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

void Draw(int arr[4][4]);
void action(int arr[4][4], int row, int col);

void Function(int arr[4][4])
{
	srand(time(0));
	int x = 0, y = 0, count = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			x = rand() % 4;
			y = rand() % 4;
			while (arr[y][x] != 0)
			{
				x = rand() % 4;
				y = rand() % 4;
			}
			if (count < 16 && arr[y][x] == 0)
			{
				arr[y][x] = count;
				count++;
			}
		}
	}
	Draw(arr);
}

void Draw(int arr[4][4])
{
	while (true)
	{
		int row, col, check = 1, count = 0;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(h, { 0,0 });
		cout << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j] == check)
				{
					check++;
					count++;
				}
				if (arr[i][j] == 0)
				{
					cout << " " << "\t";
					row = i;
					col = j;
				}
				else
					cout << " " << arr[i][j] << '\t';
			}
			cout << endl << endl;
		}
		if (count == 15)
		{
			SetConsoleTextAttribute(h, 10);
			cout << "\t\tYou win\n";
			SetConsoleTextAttribute(h, 7);
			return;
		}
		SetConsoleCursorPosition(h, { 0,0 });
		for (short i = 0; i < 9; i++)
		{
			for (short j = 0; j < 28; j++)
			{
				if (i % 2 == 0 || j == 0 || j == 7 || j == 14 || j == 21 || j == 27)
				{
					SetConsoleCursorPosition(h, { j,i });
					cout << char(219);
				}
			}
		}
		action(arr, row, col);
	}
}

void action(int arr[4][4], int row, int col)
{
	int key;
	key = getch();
	if (key == 115 && row > 0)
	{
		arr[row][col] = arr[row - 1][col];
		arr[row - 1][col] = 0;
		row--;
	}
	if (key == 100 && col > 0)
	{
		arr[row][col] = arr[row][col - 1];
		arr[row][col - 1] = 0;
		col--;
	}
	if (key == 119 && row < 3)
	{
		arr[row][col] = arr[row + 1][col];
		arr[row + 1][col] = 0;
		row++;
	}
	if (key == 97 && col < 3)
	{
		arr[row][col] = arr[row][col + 1];
		arr[row][col + 1] = 0;
		col++;
	}
	Sleep(150);
}


#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

void Draw(int arr[9][9]);

void Function(int arr[9][9])
{
	int x, y, count = 0;
	for (int i = 0; i < 9; i++)
	{	
		for (int j = 0; j < 9; j++)
		{
			if (i % 2 == 0 || j % 2 == 0)
			{
				arr[i][j] = 20;
			}
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			while (arr[y][x] != 0)
			{
				x = rand() % 9;
				y = rand() % 9;
			}
			if (count < 16)
			{
				arr[x][y] = count;
				count++;
			}
		}
	}
	Draw(arr);
}

void Draw(int arr[9][9])
{
	for (int i = 0; i < 9; i++)
	{		
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 20)
			{
				cout << char(219);
			}
			else
			{
				cout << arr[i][j];
			}
		}
		cout << endl;
	}
}
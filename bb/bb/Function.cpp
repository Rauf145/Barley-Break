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
		system("cls");
		SetConsoleTextAttribute(h, 7);
		SetConsoleCursorPosition(h, { 0,1 });
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
		if (count == 15)
		{
			SetConsoleTextAttribute(h, 10);
			cout << "\n\t\tYou win\n";
			SetConsoleTextAttribute(h, 7);
			return;
		}
		action(arr, row, col);
	}
}

void action(int arr[4][4], int row, int col)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int key, time, x1 = 0, y1 = 0, diff = 0;
	key = getch();
	if (key == 67 || key == 99) // chit code
	{
		time = clock();
		while (diff < 200)
		{
			diff = clock() - time;
			if (kbhit())
				key = getch();
			if (key == 72 || key == 104)
			{
				time = clock();
				while (diff < 200)
				{
					diff = clock() - time;
					if (kbhit())
						key = getch();
					if (key == 73 || key == 105)
					{
						time = clock();
						while (diff < 200)
						{
							diff = clock() - time;
							if (kbhit())
								key = getch();
							if (key == 84 || key == 116)
							{
								SetConsoleTextAttribute(h, 12);
								cout << "\nChit code activeted\n";
								while (true)
								{
									SetConsoleTextAttribute(h, 12);
									cout << "Enter coord(y,x): \n";
									SetConsoleTextAttribute(h, 7);
									cin >> y1 >> x1;
									if (x1 >= 1 && x1 <= 4 && y1 >= 1 && y1 <= 4)
									{
										arr[row][col] = arr[y1 - 1][x1 - 1];		
										row = y1 - 1;
										col = x1 - 1;
										arr[row][col] = 0;
										break;
									}
									else
										cout << "Error\n";
								}
								break;
							}
						}
						break;
					}
				}
				break;
			}
		}
	}
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


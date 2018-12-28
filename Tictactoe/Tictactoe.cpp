// Tictactoe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

//Arrays
char player1[50];
char player2[50];
char square[3][3] = { '1','2','3','4','5','6','7','8','9' };
char previoussquare[3][3] = { '1','2','3','4','5','6','7','8','9' };

//Function prototype
void input();
void board();
void play();
int checkwin();

int main()
{
	int mode;
	cout << "Welcome To Tic-tac-toe game! Play with your way!" << endl
		 << "If you find any problem, please contact vienhay123@gmail.com" << endl
		 << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): ";
	cin >> mode;
	if (mode==1)
	{
		play();
	}
	else
	{
	}
	return 0;
}

void input()
{
	cout << "Enter Player 1 Name: ";
	cin >> player1;
	cout << "Enter Player 2 Name: ";
	cin >> player2;
}

void board()
{
	system("cls");
	cout << "\nTic Tac Toe\n";
	cout << player1 << " - " << player2 << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << square[i][j] << " | ";
		}
		cout << endl;
	}
	/*cout << square[0][0] << "|" << square[0][1] << "|" << square[0][2] << endl;
	cout << square[1][0] << "|" << square[1][1] << "|" << square[1][2] << endl;
	cout << square[2][0] << "|" << square[2][1] << "|" << square[2][2] << endl;*/
}

void play()
{
	input();
	board();
	int player = 1, choice, i;
	char mark;
	do
	{
		board();
		player = (player % 2) ? 1 : 2;
		cout << "Enter a number: ";
		cin >> choice;
		mark = (player == 1) ? 'X' : 'O';
		if (choice == 1)
		{
			if (square[0][0] != 'X' && square[0][0] != 'O')
			{
				square[0][0] = mark;
				player++;
			}
		}
		else if (choice == 2)
		{
			if (square[0][1] != 'X' && square[0][1] != 'O')
			{
				square[0][1] = mark;
				player++;
			}
		}
		else if (choice == 3)
		{
			if (square[0][2] != 'X' && square[0][2] != 'O')
			{
				square[0][2] = mark;
				player++;
			}
		}
		else if (choice == 4)
		{
			if (square[1][0] != 'X' && square[1][0] != 'O')
			{
				square[1][0] = mark;
				player++;
			}
		}
		else if (choice == 5)
		{
			if (square[1][1] != 'X' && square[1][1] != 'O')
			{
				square[1][1] = mark;
				player++;
			}
		}
		else if (choice == 6)
		{
			if (square[1][2] != 'X' && square[1][2] != 'O')
			{
				square[1][2] = mark;
				player++;
			}
		}
		else if (choice == 7)
		{
			if (square[2][0] != 'X' && square[2][0] != 'O')
			{
				square[2][0] = mark;
				player++;
			}
		}
		else if (choice == 8)
		{
			if (square[2][1] != 'X' && square[2][1] != 'O')
			{
				square[2][1] = mark;
				player++;
			}
		}
		else if (choice == 9)
		{
			if (square[2][2] != 'X' && square[2][2] != 'O')
			{
				square[2][2] = mark;
				player++;
			}
		}
		board();
		i = checkwin();
		if (i == 1)
		{
			cout << player1 << " win" << endl;
		}
		else if (i == 2)
		{
			cout << player2 << " win" << endl;
		}
		else
		{
			cout << "Game draw" << endl;
		}
	} while (i==-1);

}

int checkwin()
{
	if (square[0][0]=='X' && square[0][1] == 'X' && square[0][2 ] == 'X' || square[1][0] == 'X' && square[1][1] == 'X' && square[1][2] == 'X' || square[2][0] == 'X' && square[2][1] == 'X' && square[2][2] == 'X' ||
		square[0][0] == 'X' && square[1][0] == 'X' && square[2][0] == 'X' || square[0][1] == 'X' && square[1][1] == 'X' && square[2][1] == 'X' || square[0][2] == 'X' && square[1][2] == 'X' && square[2][2] == 'X' ||
		square[0][0] == 'X' && square[1][1] == 'X' && square[2][2] == 'X' || square[0][2] == 'X' && square[1][1] == 'X' && square[2][0] == 'X')
	{
		return 1;
	}
	else if (square[0][0] == 'O' && square[0][1] == 'O' && square[0][2] == 'O' || square[1][0] == 'O' && square[1][1] == 'O' && square[1][2] == 'O' || square[2][0] == 'O' && square[2][1] == 'O' && square[2][2] == 'O' ||
		square[0][0] == 'O' && square[1][0] == 'O' && square[2][0] == 'O' || square[0][1] == 'O' && square[1][1] == 'O' && square[2][1] == 'O' || square[0][2] == 'O' && square[1][2] == 'O' && square[2][2] == 'O' ||
		square[0][0] == 'O' && square[1][1] == 'O' && square[2][2] == 'O' || square[0][2] == 'O' && square[1][1] == 'O' && square[2][0] == 'O')
	{
		return 2;
	}
	else if (square[0][0] != '1' && square[0][1] != '2' && square[0][2] != '3' && square[1][0] != '4' && square[1][1] != '5' && square[1][2] != '6' && square[2][0] != '7' && square[2][1] != '8' && square[2][2] != '9')
	{
		return 0;
	}
	return -1;
}

void newgame()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			square[i][j] = previoussquare[i][j];
		}
		cout << endl;
	}
}
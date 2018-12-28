// Tictactoe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

//Arrays
char player1[50];
char player2[50];
char square[3][3] = { '1','2','3','4','5','6','7','8','9' };
char mark = 'X';
int player = 1;

//Function prototype
void inputName();
void printBoard();
void playGame();
int checkWin();
void resetGame();

int main()
{
	int mode;
	char n;
	cout << "Welcome To Tic-tac-toe game! Play with your way!" << endl
		 << "If you find any problem, please contact vienhay123@gmail.com" << endl
		 << "SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME): ";
	cin >> mode;
	
	if (mode==1)
	{
		do
		{
			playGame();
			cout << "Do you want to continue (y/ n)?: ";
			cin >> n;
			resetGame();
		} while (n == 'y');
	}
	else
	{
	}
	system("pause");
	return 0;
}

//Input player name
void inputName()
{
	cout << "Enter player 1 Name: ";
	cin >> player1;
	cout << "Enter player 2 Name: ";
	cin >> player2;
}

//Display a board
void printBoard()
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
}

void playGame()
{
	inputName();
	printBoard();
	
	int choice, row, column;

	do
	{
		printBoard();
		mark = (player % 2) ? 'X' : 'O';
		cout << "Enter a number: ";
		cin >> choice;
		row = choice / 10 - 1;
		column = choice % 10 - 1;
		if (row < 3 && column < 3)
		{
			if (square[row][column] != 'X' && square[row][column] != 'O')
			{
				square[row][column] = mark;
				player++;
			}
		}
		
		printBoard();
		if (checkWin() == 1)
		{
			(mark == 'X') ? cout << player1 : cout << player2;
			cout << " win!" << endl;
		}
		else
		{
			cout << "Game draw!" << endl;
		}
	} while (checkWin()==-1);

}

int checkWin()
{
	for (int i = 0; i < 3; i++)
	{
		if ((square[i][0] == mark && square[i][1] == mark && square[i][2] == mark)|| (square[0][i] == mark && square[1][i] == mark && square[2][i] == mark))
		{
			return 1;
		}
		if (square[1][1] == mark)
		{
			if ((square[0][0] == mark && square[2][2]==mark)||square[0][2] == mark && square[2][0] == mark)
			{
				return 1;
			}
		}
	}
	if (player == 10)
		return 2;
	return -1;
}

void resetGame()
{
	player = 1;
	char previoussquare[3][3] = { '1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			square[i][j] = previoussquare[i][j];
		}
		cout << endl;
	}
}
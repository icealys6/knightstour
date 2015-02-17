#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <Windows.h>
using namespace std;

char chessboard[8][8];
vector<int>validchoices;
int last_pos_y;
int last_pos_x;


time_t mySeed;

void count_possibles(int checknumofmoves_Y, int checknumofmoves_X, int* totalnumofmovesforsquare, int index)
{
	if (checknumofmoves_Y - 2 >= 0 && checknumofmoves_X + 1 <= 7
		&& chessboard[checknumofmoves_Y - 2][checknumofmoves_X + 1] == '*')
	{
		totalnumofmovesforsquare[index] += 1;
	}
	if (checknumofmoves_Y - 2 >= 0 && checknumofmoves_X - 1 >= 0
		&& chessboard[checknumofmoves_Y - 2][checknumofmoves_X - 1] == '*')
	{
		totalnumofmovesforsquare[index] += 1;
	}
	if (checknumofmoves_Y - 1 >= 0 && checknumofmoves_X + 2 <= 7
		&& chessboard[checknumofmoves_Y - 1][checknumofmoves_X + 2] == '*') 
	{
		totalnumofmovesforsquare[index] += 1;
	}
	if (checknumofmoves_Y + 1 <= 7 && checknumofmoves_X + 2 <= 7
		&& chessboard[checknumofmoves_Y + 1][checknumofmoves_X + 2] == '*')
	{
		totalnumofmovesforsquare[index] += 1;
	}
	if (checknumofmoves_Y + 2 <= 7 && checknumofmoves_X + 1 <= 7
		&& chessboard[checknumofmoves_Y + 2][checknumofmoves_X + 1] == '*')
	{
		totalnumofmovesforsquare[index] += 1;
	}
	if (checknumofmoves_Y + 2 <= 7 && checknumofmoves_X - 1 >= 0
		&& chessboard[checknumofmoves_Y + 2][checknumofmoves_X - 1] == '*')
	{
		totalnumofmovesforsquare[index] += 1;
	}
	if (checknumofmoves_Y + 1 <= 7 && checknumofmoves_X - 2 >= 0
		&& chessboard[checknumofmoves_Y + 1][checknumofmoves_X - 2] == '*')
	{
		totalnumofmovesforsquare[index] += 1;
	}
	if (checknumofmoves_Y - 1 >= 0 && checknumofmoves_X - 2 >= 0
		&& chessboard[checknumofmoves_Y - 1][checknumofmoves_X - 2] == '*')
	{
		totalnumofmovesforsquare[index] += 1;
	}
}

void moveknight(int pos_y, int pos_x)
{
	int totalnumofmovesforsquare[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	int checknumofmoves_Y;
	int checknumofmoves_X;

	if (pos_y - 2 >= 0 && pos_x + 1 <= 7 && chessboard[pos_y - 2][pos_x + 1] == '*')
	{
		count_possibles(pos_y - 2, pos_x + 1, totalnumofmovesforsquare, 0);
	}
	if (pos_y - 2 >= 0 && pos_x - 1 >= 0 && chessboard[pos_y - 2][pos_x - 1] == '*')
	{
		count_possibles(pos_y - 2, pos_x - 1, totalnumofmovesforsquare, 1);
	}
	if (pos_y - 1 >= 0 && pos_x + 2 <= 7 && chessboard[pos_y - 1][pos_x + 2] == '*')
	{
		count_possibles(pos_y - 1, pos_x + 2, totalnumofmovesforsquare, 2);
	}
	if (pos_y + 1 <= 7 && pos_x + 2 <= 7 && chessboard[pos_y + 1][pos_x + 2] == '*')
	{
		count_possibles(pos_y + 1, pos_x + 2, totalnumofmovesforsquare, 3);
	}
	if (pos_y + 2 <= 7 && pos_x + 1 <= 7 && chessboard[pos_y + 2][pos_x + 1] == '*')
	{
		count_possibles(pos_y + 2, pos_x + 1, totalnumofmovesforsquare, 4);
	}
	if (pos_y + 2 <= 7 && pos_x - 1 >= 0 && chessboard[pos_y + 2][pos_x - 1] == '*')
	{
		count_possibles(pos_y + 2, pos_x - 1, totalnumofmovesforsquare, 5);
	}
	if (pos_y + 1 <= 7 && pos_x - 2 >= 0 && chessboard[pos_y + 1][pos_x - 2] == '*')
	{
		count_possibles(pos_y + 1, pos_x - 2, totalnumofmovesforsquare, 6);
	}
	if (pos_y - 1 >= 0 && pos_x - 2 >= 0 && chessboard[pos_y - 1][pos_x - 2] == '*')
	{
		count_possibles(pos_y - 1, pos_x - 2, totalnumofmovesforsquare, 7);
	}

	int lowestnumber = 8;

	for (int i = 0; i < 8; i++)
	{

		if (totalnumofmovesforsquare[i] < lowestnumber && totalnumofmovesforsquare[i] != 0)
		{
			lowestnumber = totalnumofmovesforsquare[i];
		}
	}

	for (int i = 0; i < 8; i++)
	{

		if (lowestnumber == totalnumofmovesforsquare[i])
		{
			validchoices.push_back(i);

		}
	}
	if (validchoices.size() == 1)
	{
		switch (validchoices.at(0))
		{
		case 0: {pos_y = pos_y - 2;
			pos_x = pos_x + 1;
			break; }
		case 1: {pos_y = pos_y - 2;
			pos_x = pos_x - 1;
			break; }
		case 2: {pos_y = pos_y - 1;
			pos_x = pos_x + 2;
			break; }
		case 3: {pos_y += 1;
			pos_x += 2;
			break; }
		case 4: {pos_y += 2;
			pos_x += 1;
			break; }
		case 5: {pos_y += 2;
			pos_x -= 1;
			break; }
		case 6: {pos_y += 1;
			pos_x -= 2;
			break; }
		case 7: {pos_y -= 1;
			pos_x -= 2; }
		}
	}
	else if (validchoices.size() > 1)
	{
		
		int tiebreaker;
		do{
			tiebreaker = rand() % 8;
		} while (totalnumofmovesforsquare[tiebreaker] != lowestnumber);


		switch (tiebreaker)
		{
		case 0: {pos_y = pos_y - 2;
			pos_x = pos_x + 1;
			break; }
		case 1: {pos_y = pos_y - 2;
			pos_x = pos_x - 1;
			break; }
		case 2: {pos_y = pos_y - 1;
			pos_x = pos_x + 2;
			break; }
		case 3: {pos_y += 1;
			pos_x += 2;
			break; }
		case 4: {pos_y += 2;
			pos_x += 1;
			break; }
		case 5: {pos_y += 2;
			pos_x -= 1;
			break; }
		case 6: {pos_y += 1;
			pos_x -= 2;
			break; }
		case 7: {pos_y -= 1;
			pos_x -= 2; }
		}

	}
	else if (validchoices.size() == 0)
		return;

	system("CLS");
	validchoices.clear();

	
	chessboard[pos_y][pos_x] = 'X';
	last_pos_y = pos_y;
	last_pos_x = pos_x;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << chessboard[i][j];
		}
		cout << endl;
	}
	chessboard[last_pos_y][last_pos_x] = 'O';

	Sleep(1000);
	system("CLS");

	
	
	moveknight(pos_y, pos_x);
}

int main()
{
	mySeed = time(NULL);
	
	srand(mySeed);
	int pos_y = 0;
	int pos_x = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			chessboard[i][j] = '*';
		}
	}

	chessboard[pos_y][pos_x] = 'O';

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << chessboard[i][j];
		}
		cout << endl;
	}
	
	Sleep(1000);
	system("CLS");
	moveknight(pos_y, pos_x);

	return 0;
}
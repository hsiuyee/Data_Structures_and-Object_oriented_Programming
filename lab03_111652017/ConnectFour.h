#ifndef __CONNECTFOUR_H__
#define __CONNECTFOUR_H__

enum Grid
{
	Empty,
	PlayerA,
	PlayerB,
};

enum Status
{
	Playing,
	Draw,
	PlayerAWin,
	PlayerBWin,
};

class ConnectFour
{
private:
	Grid m_board[6][7];

public:
	ConnectFour();

	void Place(int column, int turns);
	Status GetGameStatus();
	void PrintBoard();
	void PrintWinner();

};

#endif // __CONNECTFOUR_H__
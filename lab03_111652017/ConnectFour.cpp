#include "ConnectFour.h"
#include <iostream>
using namespace std;

ConnectFour::ConnectFour()
{
	// TODO: Initialize an empty board.
	for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            m_board[i][j] = Empty;
        }
    }
}

void ConnectFour::Place(int column, int turns)
{
	// TODO: Place a piece into the column.
	if (GetGameStatus() != Playing) {
        return; 
    }
	Grid player = (turns % 2 == 0) ? PlayerA : PlayerB;
	for (int i = 5; i >= 0; --i) {
        if (m_board[i][column] == Empty) {  
            m_board[i][column] = player;  
            return; 
        }
    }
}

Status ConnectFour::GetGameStatus()
{
	// TODO: Get the current status.
    // 水平方向
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j <= 3; ++j) {
            if (m_board[i][j] != Empty &&
                m_board[i][j] == m_board[i][j + 1] &&
                m_board[i][j] == m_board[i][j + 2] &&
                m_board[i][j] == m_board[i][j + 3]) {
                return (m_board[i][j] == PlayerA) ? PlayerAWin : PlayerBWin;
            }
        }
    }

    // 垂直方向
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (m_board[i][j] != Empty &&
                m_board[i][j] == m_board[i + 1][j] &&
                m_board[i][j] == m_board[i + 2][j] &&
                m_board[i][j] == m_board[i + 3][j]) {
                return (m_board[i][j] == PlayerA) ? PlayerAWin : PlayerBWin;
            }
        }
    }

    // 左上右下對角線
    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 3; ++j) {
            if (m_board[i][j] != Empty &&
                m_board[i][j] == m_board[i + 1][j + 1] &&
                m_board[i][j] == m_board[i + 2][j + 2] &&
                m_board[i][j] == m_board[i + 3][j + 3]) {
                return (m_board[i][j] == PlayerA) ? PlayerAWin : PlayerBWin;
            }
            // cout << m_board[i][j] << " ";
        }
        // cout << "\n";
    }
    // 另一條對角線
    for (int i = 0; i <= 2; ++i) {
        for (int j = 3; j < 7; ++j) {
            if (m_board[i][j] != Empty &&
                m_board[i][j] == m_board[i + 1][j - 1] &&
                m_board[i][j] == m_board[i + 2][j - 2] &&
                m_board[i][j] == m_board[i + 3][j - 3]) {
                return (m_board[i][j] == PlayerA) ? PlayerAWin : PlayerBWin;
            }
            // cout << m_board[i][j] << " ";
        }
        // cout << "\n";
    }

    // 檢查空位置
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (m_board[i][j] == Empty) {
                return Playing;  
            }
        }
    }

    // 其餘為平局
    return Draw;
}

void ConnectFour::PrintBoard()
{
	// TODO: Print the board.
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            switch (m_board[i][j]) {
                case Empty:
                    cout << "=";
                    break;
                case PlayerA:
                    cout << "o";
                    break;
                case PlayerB:
                    cout << "x";
                    break;
            }
        }
        cout << endl;
    }
}

void ConnectFour::PrintWinner()
{
	// TODO: Use GetGameStatus() to print the winner.
    Status status = GetGameStatus();

    switch (status) {
        case PlayerAWin:
            cout << "PlayerA win!" << endl;
            break;
        case PlayerBWin:
            cout << "PlayerB win!" << endl;
            break;
        case Draw:
            cout << "Draw." << endl;
            break;
        default:
            break;
    }
}

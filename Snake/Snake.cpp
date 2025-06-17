#include "Snake.h"

#include <iostream>

Snake::Snake() : m_board()
{
	_initBoard();
}

void Snake::_updateSnake()
{

}

void Snake::_initSnake()
{
	m_snakeSize = INIT_SNAKE_SIZE;
	m_board[8][1] = SNAKE_SQUARE;
	m_board[8][2] = SNAKE_SQUARE;
	m_board[8][3] = SNAKE_SQUARE;
	m_board[8][4] = SNAKE_SQUARE;

}

void Snake::_initBoard()
{
	_initSnake();
	//TODO: add init for fruit at	[8][13]
	for (int i = 0; i < m_board.size(); ++i)
	{
		for (int j = 0; j < m_board[0].size(); ++j)
		{
			// init boarders.
			if (0 == i || m_board.size() - 1 == i || 0 == j || m_board[0].size() - 1 == j)
			{
				m_board[i][j] = BOARDER_SQUARE;
			}
			else 
			{
				if ('\0' == m_board[i][j])
				{
					m_board[i][j] = EMPTY_SQUARE;
				}
			}
		}
	}
}



void Snake::printBoard() const
{
	//system("cls");
	for (int i = 0; i < m_board.size(); ++i)
	{
		for (int j = 0; j < m_board[0].size(); ++j)
		{
			if (SNAKE_SQUARE == m_board[i][j])
			{
				// check if end of snake.
				if (j + 1 != m_board[0].size() && SNAKE_SQUARE != m_board[i][j + 1])
				{
					std::cout << m_board[i][j] << " ";
				}
				else
				{
					std::cout << m_board[i][j] << "-";
				}
			}
			else
			{
				std::cout << m_board[i][j] << " ";
			}
		}
		std::cout << std::endl;
	}
}
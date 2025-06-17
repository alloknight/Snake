#include "Snake.h"

#include <iostream>
#include <vector>
#include <windows.h>

Snake::Snake() : m_board()
{
	_initBoard();
}

void Snake::_updateSnake(int direction)
{
	// TODO take direction in conserderation.
	unsigned int new_head_row = m_snake_head_location.first;
	unsigned int new_head_col = m_snake_head_location.second + 1;

	// make the first square empty.
	*m_snake[0] = EMPTY_SQUARE;

	// remove the square fron snake.
	m_snake.erase(m_snake.begin());

	// make the new square a snake square.
	m_board[new_head_row][new_head_col] = SNAKE_SQUARE;

	// add the new square as new head.
	m_snake.push_back(&m_board[new_head_row][new_head_col]);

	// update the snake_head.
	m_snake_head_location.first = new_head_row;
	m_snake_head_location.second = new_head_col;
}

void Snake::_initSnake()
{
	m_snake.push_back(&m_board[8][1]);
	m_snake.push_back(&m_board[8][2]);
	m_snake.push_back(&m_board[8][3]);
	m_snake.push_back(&m_board[8][4]);
	m_snake_head_location.first = 8;
	m_snake_head_location.second = 4;

	for (auto& mem : m_snake)
	{
		*mem = SNAKE_SQUARE;
	}
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
	system("cls");
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

bool Snake::_isGameOver() const
{
	// Check boarders.
	if (m_snake_head_location.first >= m_board.size() - 1 || m_snake_head_location.second >= m_board[0].size() - 1)
	{
		return true;
	}
	return false;
}

void Snake::play()
{
	while (!_isGameOver())
	{
		Sleep(100);
		printBoard();
		_updateSnake(0);
	}
}
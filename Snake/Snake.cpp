#include "Snake.h"
#include "CharReader.h"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <windows.h>

Snake::Snake()
{
	_initBoard();
}

char Snake::_opposite_direction(char direction) const
{
	switch (direction)
	{
	case(UP_KEY):
		return DOWN_KEY;
	case(DOWN_KEY):
		return UP_KEY;
	case(LEFT_KEY):
		return RIGHT_KEY;
	case(RIGHT_KEY):
		return LEFT_KEY;
	default:
		throw std::runtime_error("Invalid Direction");
	}
}

void Snake::_updateSnake(char direction)
{
	// if the direction is the same, or opposite, then ignore. 
	if (direction != m_direction && direction != _opposite_direction(m_direction))
	{
		//switch (direction)
		//{
		//case(UP_KEY):
		//	;
		//case(DOWN_KEY):
		//	return UP_KEY;
		//case(LEFT_KEY):
		//	return RIGHT_KEY;
		//case(RIGHT_KEY):
		//	return LEFT_KEY;
		//default:
		//	throw std::runtime_error("Invalid Direction");
		//}
	}

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

void Snake::_updateDirection()
{
	char key = getKeyPressed();
	if (key == 'w' || key == 'a' || key == 's' || key == 'd') {
		m_direction = key;
	}
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
	// TODO: add if snake ate itself.
	return false;
}

void Snake::play()
{
	while (!_isGameOver())
	{
		Sleep(100); // Make refresh rate slower.
		printBoard();
		_updateDirection();
		_updateSnake();
	}
}
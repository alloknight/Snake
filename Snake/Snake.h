#pragma once
#include <iostream>
#include <array>


typedef enum BOARD_STATS
{
	LENGTH = 15,
	WIDTH = 15,
	INIT_SNAKE_SIZE = 4,
	SNAKE_SQUARE = 'O',
	BOARDER_SQUARE = 'X',
	EMPTY_SQUARE = ' ',
	FRUIT_SQUARE = '#'
}board_stats_t;

static class Snake {
public:
	Snake();
	void printBoard() const;
private:
	void _initBoard();
	void _updateSnake();
	void _initSnake();
private:
	std::array<std::array<char, LENGTH>, WIDTH> m_board;
	unsigned int m_snakeSize;
	unsigned int m_points;
};
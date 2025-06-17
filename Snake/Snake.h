#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <utility>


typedef enum BOARD_STATS
{
	LENGTH = 15,
	WIDTH = 15,
	INIT_SNAKE_SIZE = 4,
	SNAKE_SQUARE = 'O',
	BOARDER_SQUARE = 'X',
	EMPTY_SQUARE = ' ',
	FRUIT_SQUARE = '#',
	UP_KEY = 'w',
	DOWN_KEY = 's',
	LEFT_KEY = 'a',
	RIGHT_KEY = 'd',
}board_stats_t;

static class Snake {
public:
	Snake();
	void printBoard() const;
	void play();
private:
	void _initBoard();
	void _updateDirection();
	void _updateSnake(char direction);
	void _initSnake();
	bool _isGameOver() const;
	char _opposite_direction(char direction) const;
private:
	std::array<std::array<char, LENGTH>, WIDTH> m_board;
	std::vector<char *> m_snake;
	std::pair<unsigned int, unsigned int>  m_snake_head_location;
	unsigned int m_points;
	char m_direction;
};
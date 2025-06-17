#include <conio.h>

char getKeyPressed()
{
	if (_kbhit())
	{
		return(_getch());
	}	
	return '/0';
}


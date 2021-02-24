#include "slide_line.h"

/**
  * slide_line - slide line
  * @line: line to slide
  * @size: size of line
  * @direction: left or right
  *
  * Return: 1 success, 0 failure
  */

int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL)
	{
		return (0);
	}
	if (direction == SLIDE_LEFT)
	{
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		return (1);
	}
	return (0);
}

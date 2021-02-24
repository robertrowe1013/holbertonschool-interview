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
	int i;
	int idx = 0;
	int linesize = size;

	if (line == NULL)
	{
		return (0);
	}
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < linesize; i++)
		{
			if (line[i] != 0)
			{
				if (line[i] == line[idx])
				{
					line[i] = line[idx];
				}
			}
		}
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		return (1);
	}
	return (0);
}

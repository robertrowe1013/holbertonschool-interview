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
	int linesize = size;

	if (line == NULL)
		return (0);
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		merge_left(line, size);
		slide_left(line, size);
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		merge_right(line, size);
		slide_right(line, size);
		return (1);
	}
	return (0);
}

void shift_left(int *line, int size)
{
	int i, idx;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
		{
			idx = i + 1;
			while (line[idx] == 0)
				idx += 1;
			line[i] = line[idx];
			line[idx] = 0;
		}
	}
}

void merge_left(int *line, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}
}

void shift_right(int *line, int size)
{
	int i, idx;

	for (i = size -1; i > 0; i--)
	{
		if (line[i] == 0)
		{
			idx = i - 1;
			while (line[idx] == 0)
				idx -= 1;
			line[i] = line[idx];
			line[idx] = 0;
		}
	}
}

void merge_right(int *line, int size)
{
	int i;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}
}
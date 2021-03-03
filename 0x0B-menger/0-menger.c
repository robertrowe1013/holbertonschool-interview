#include "menger.h"

/**
  * menger - draw a sierpinski carpet
  * @level: fractal level
  *
  */

void menger(int level)
{
	if (level == 0)
		printf("#\n");
	if (level == 1)
		printf("###\n# #\n###\n");
}


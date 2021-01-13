#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
  * cascade - spread sand
  * @grid1: grid with overflow
  */

void cascade(int grid1[3][3])
{
	int overflowFlag = 0;
	int i;
	int j;
	int tempGrid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				tempGrid[i][j] += grid1[i][j] - 4;
				if (j > 0)
				{
					tempGrid[i][j - 1] += 1;
					if (tempGrid[i][j - 1] > 3)
						overflowFlag = 1;
				}
				if (j < 3)
				{
					tempGrid[i][j + 1] += 1;
					if (tempGrid[i][j + 1] > 3)
						overflowFlag = 1;
				}
				if (i > 0)
				{
					tempGrid[i - 1][j] += 1;
					if (tempGrid[i - 1][j] > 3)
						overflowFlag = 1;
				}
				if (i < 3)
				{
					tempGrid[i + 1][j] += 1;
					if (tempGrid[i + 1][j] > 3)
						overflowFlag = 1;
				}
			}
			else
			{
				tempGrid[i][j] += grid1[i][j];
				if (tempGrid[i][j] > 3)
					overflowFlag = 1;
			}		
		}
	}
	if (overflowFlag == 1)
	{
		printf("=\n");
		print_grid(tempGrid);
		cascade(tempGrid);
	}
}

/**
  * sandpiles_sum - sandpiles sum
  * @grid1: grid1
  * @grid2: grid2
  */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;
	int overflowFlag = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3)
				overflowFlag = 1;
		}
	}
	if (overflowFlag == 1)
	{
		printf("=\n");
		print_grid(grid1);
		cascade(grid1);
	}
}


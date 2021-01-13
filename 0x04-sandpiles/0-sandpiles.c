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


/** sandpiles_sum - sandpiles sum
  * @grid1: grid 1
  * @grid2: grid 2
  */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i;
    int j;
    int gridSum[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0, j < 3, j++)
        {
            gridSum[i][j] = grid1[i][j] + grid2[i][j]
        }
    }
    print_grid(gridSum);
}
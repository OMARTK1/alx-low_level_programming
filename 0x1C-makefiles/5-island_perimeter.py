#!/usr/bin/python3
"""It defines the perimeter of an island measuring function"""


def island_perimeter(grid):
    """It returns the perimiter of the island

    And the grid represents water by 0 and land by 1.

    Args:
        grid (list): The list of list of integers representing the island
    Returns:
        The perimeter of that island defined by the grid.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for p in range(height):
        for q in range(width):
            if grid[p][q] == 1:
                size += 1
                if (q > 0 and grid[p][q - 1] == 1):
                    edges += 1
                if (p > 0 and grid[p - 1][q] == 1):
                    edges += 1
    return size * 4 - edges * 2

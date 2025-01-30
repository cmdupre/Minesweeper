#include "Engine.h"

int Engine::GetIndex(const wxPoint& cell, int horizontalMax, int verticalMax)
{
	if (horizontalMax < 1 || horizontalMax > 99999)
		return 0;

	if (cell.x < 0 || cell.y < 0)
		return 0;

	if (cell.x >= horizontalMax || cell.y >= verticalMax)
		return 0;

	return (cell.y * horizontalMax) + cell.x;
}

wxPoint Engine::GetCell(int index, int horizontalMax, int verticalMax)
{
	if (index < 0)
		return wxPoint(0, 0);

	if (index >= (horizontalMax * verticalMax))
		return wxPoint(0, 0);

	int x = index % horizontalMax;
	int y = index / verticalMax;	// ignore fraction

	return wxPoint(x, y);
}

std::vector<wxPoint> Engine::GetNeighbors(const wxPoint& selected, int horizontalMax, int verticalMax)
{
	std::vector<wxPoint> neighbors;
	neighbors.reserve(9);

	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			wxPoint neighbor = wxPoint(selected.x + x, selected.y + y);

			if (neighbor == selected ||
				neighbor.x < 0 || neighbor.x >= horizontalMax ||
				neighbor.y < 0 || neighbor.y >= verticalMax)
				continue;

			neighbors.emplace_back(neighbor);
		}
	}

	return neighbors;
}
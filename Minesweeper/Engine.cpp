#include "Engine.h"

int Engine::GetIndex(const wxPoint& cell, int horizontalMax)
{
	return (cell.y * horizontalMax) + cell.x;
}
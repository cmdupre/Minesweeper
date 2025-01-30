#pragma once

#include "wx/wx.h"

class Engine
{
public:
	static int GetIndex(const wxPoint& cell, int horizontalMax, int verticalMax);
	static wxPoint GetCell(int index, int horizontalMax, int verticalMax);
	static std::vector<wxPoint> GetNeighbors(const wxPoint& selected, int horizontalMax, int verticalMax);
};
#pragma once

#include "wx/wx.h"

class Engine
{
public:
	static int GetIndex(const wxPoint& cell, int horizontalMax);
};
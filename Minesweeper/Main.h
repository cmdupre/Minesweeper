#pragma once

#include "wx/wx.h"

class Main : public wxFrame
{
	wxDECLARE_EVENT_TABLE();

	static const int s_MineCount = 10;
	static const int s_xMax = 10;
	static const int s_yMax = 10;
	static constexpr int s_Max = s_xMax * s_yMax;
	std::vector<wxButton*> m_Buttons;
	std::vector<bool> m_MineField;
	bool m_FirstClick = true;

	wxPoint GetPoint(int index);
	int GetIndex(wxPoint point);
	void Sweep(int index, int iterations);
	std::vector<wxPoint> GetNeighbors(wxPoint selected);
	void OnButtonClicked(wxCommandEvent& e);

public:
	Main();
	~Main();

	// wxFrame deletes copy constructor and operator overload
};


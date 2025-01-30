#pragma once

#include "wx/wx.h"
#include "unordered_set"

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

	int GetIndex(const wxPoint& cell);
	wxPoint GetCell(int index);
	std::vector<wxPoint> GetNeighbors(const wxPoint& selected);
	void Sweep(int index, std::unordered_set<int>& checked);
	void OnButtonClicked(wxCommandEvent& e);

public:
	Main();
	~Main();

	// wxFrame deletes copy constructor and operator overload
};


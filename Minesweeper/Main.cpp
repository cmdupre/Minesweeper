#include "Main.h"
#include "Engine.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)

	// using Bind() for buttons

wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxDefaultPosition, wxSize(400, 400))
{
	// wx handles wx-object deletes

	// initialize mine field
	m_MineField.reserve(s_Max);
	for (int i = 0; i < s_Max; i++)
		m_MineField.emplace_back(false);

	// build gui
	m_Buttons.reserve(s_Max);
	wxGridSizer* sizer = new wxGridSizer(s_xMax, s_yMax, 0, 0);
	for (int i = 0; i < s_Max; i++)
	{
		m_Buttons.emplace_back(new wxButton(this, i));
		m_Buttons[i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClicked, this);
		sizer->Add(m_Buttons[i], 1, wxEXPAND | wxALL);
	}

	this->SetSizer(sizer);
	sizer->Layout();
}

Main::~Main()
{
	// nop
}

void Main::OnButtonClicked(wxCommandEvent &event)
{
	event.Skip();

	wxObject* eventObject = event.GetEventObject();

	if (!eventObject || !eventObject->IsKindOf(CLASSINFO(wxButton)))
		return;

	int index = event.GetId();

	if (m_FirstClick)
	{
		m_FirstClick = false;

		srand(time(0));
		int mineCount = 0;
		while (mineCount < s_MineCount)
		{
			int mineIndex = rand() % 99;

			if (m_MineField[mineIndex] || mineIndex == index)
				continue;

			m_MineField[mineIndex] = true;
			++mineCount;
		}
	}

	if (m_MineField[index])
	{
		wxMessageBox("BOOOOOOOOM!!! You lose.");
		return;
	}

	std::unordered_set<int> checked;

	Sweep(index, checked);

	// can get current button from event
	//wxButton* eventButton = static_cast<wxButton*>(eventObject);
	//eventButton->SetLabelText(std::to_string(mineCount));
	//eventButton->Disable();
}

wxPoint Main::GetCell(int index)
{
	return Engine::GetCell(index, s_xMax, s_yMax);
}

int Main::GetIndex(const wxPoint& cell)
{
	return Engine::GetIndex(cell, s_xMax, s_yMax);
}

void Main::Sweep(int index, std::unordered_set<int>& checked)
{
	if (checked.find(index) != checked.end())
		return;

	checked.insert(index);

	wxPoint selected = GetCell(index);
	std::vector<wxPoint> neighbors = GetNeighbors(selected);

	int mineCount = 0;
	for (const auto& neighbor : neighbors)
	{
		int neighborIndex = GetIndex(neighbor);

		if (m_MineField[neighborIndex])
			++mineCount;
	}

	m_Buttons[index]->Disable();

	if (mineCount > 0)
	{
		m_Buttons[index]->SetLabelText(std::to_string(mineCount));
		return;
	}
	
	for (const auto& neighbor : neighbors)
		Sweep(GetIndex(neighbor), checked);
}

std::vector<wxPoint> Main::GetNeighbors(const wxPoint& selected)
{
	return Engine::GetNeighbors(selected, s_xMax, s_yMax);
}
#include "App.h"

// ask wx to generate WinMain
wxIMPLEMENT_APP(App);

App::App() : m_Main(new Main())
{
}

App::~App()
{
	// wx handles delete main
}

bool App::OnInit()
{
	m_Main->Show();
	SetTopWindow(m_Main);
	return true;
}
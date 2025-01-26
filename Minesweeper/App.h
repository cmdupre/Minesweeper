#pragma once

#include "wx/wx.h"
#include "Main.h"

class App : public wxApp
{
    Main* m_Main = nullptr;
    virtual bool OnInit();

public:
    App();
    ~App();

    // wxApp deletes copy constructor and operator overload
};


#pragma once

#include <string>

namespace tb2d
{
    class TB2D_window
    {
    private:
        

    public:
        TB2D_window()
        {

        }

        void createWindow(const std::string & name, int argc, char** argv);
    };

    typedef TB2D_window GameWindow;
}
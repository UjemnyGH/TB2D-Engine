#pragma once

namespace tb2d
{
    class TB2D_time
    {
    private:
        float lastFrame, currentFrame, deltaFrame;

    public:
        float GetTime();
        float GetDeltaTime();

    };

    typedef TB2D_time Time;
}
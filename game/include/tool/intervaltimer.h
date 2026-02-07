#pragma once
#include <functional>

class IntervalTimer {

private:
    int framePerSecond;
    int frameCounter;
    bool timerGo;

    bool runnable;

public:
    IntervalTimer(int framePerSecond);
    IntervalTimer();
    
    void run(std::function<void()> fn);
    void go();
    void stop();

    bool canRun();

    void setFramePerSecond(int num);

};

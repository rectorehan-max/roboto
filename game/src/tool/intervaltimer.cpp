#include "tool/intervaltimer.h"

IntervalTimer::IntervalTimer(int framePerSecond) :
            framePerSecond(framePerSecond) {

    frameCounter = 0;
    timerGo = false;
    runnable = false;
}

IntervalTimer::IntervalTimer() {
    framePerSecond = 0;
    frameCounter = 0;
    timerGo = false;
    runnable = false;
}

void IntervalTimer::run(std::function<void()> fn) {
    if (!timerGo) return;

    frameCounter++;

    if (frameCounter >= framePerSecond) {
        fn();
        runnable = true;
        frameCounter = 0;
    } else {
        runnable = false;
    }
}

void IntervalTimer::go() {
    timerGo = true;
}

void IntervalTimer::stop() {
    timerGo = false;
}

void IntervalTimer::setFramePerSecond(int num) {
    framePerSecond = num;
}

bool IntervalTimer::canRun() {
    return runnable;
}


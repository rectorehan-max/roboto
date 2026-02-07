#pragma once
#include <functional>

class CooldownTimer {

public:
    CooldownTimer();
    CooldownTimer(int cooldown); 
   
    void update();
    void run(std::function<void()> fn);

    void setCooldown(int cooldown);
    bool isReady();

private:
    int cooldown;
    int cooldownframe;
    bool cooldownend;

};

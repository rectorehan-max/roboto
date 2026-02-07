#include "tool/cooldown.h"

CooldownTimer::CooldownTimer(int cooldown) : 
                             cooldown(cooldown),
                             cooldownframe(cooldown),
                             cooldownend(true) {}

CooldownTimer::CooldownTimer() : cooldownend(true) {
    cooldown = 0;
    cooldownframe = 0;
}

void CooldownTimer::update() {
    if (!cooldownend) {
        cooldownframe++;
 
        if (cooldownframe >= cooldown) {
            cooldownend = true;
        }
    }
}

void CooldownTimer::run(std::function<void()> fn) {
    if (!cooldownend) return;

    fn();
    cooldownend = false;
    cooldownframe = 0;
}

void CooldownTimer::setCooldown(int cooldown) {
    this->cooldown = cooldown;
}

bool CooldownTimer::isReady() {
    return cooldownend;
}

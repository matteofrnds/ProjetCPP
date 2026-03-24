
#pragma once


class Mascotte
{
public:
    Mascotte();
    void display(int prestigeLevel) const;
    bool enable = true;
    void toggle() { enable = !enable; }
};
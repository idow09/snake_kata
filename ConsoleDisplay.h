#ifndef IDOSNAKE_CONSOLEDISPLAY_H
#define IDOSNAKE_CONSOLEDISPLAY_H


#include "Display.h"

class ConsoleDisplay : public Display {
public:
    void Clear() override;

    void Draw(Symbol symbol) override;
};

#endif //IDOSNAKE_CONSOLEDISPLAY_H

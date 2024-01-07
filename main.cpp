//#include "HEAD.h"
#include "Game.h"
#include "Widget.h"

int main()
{
    Widget w(1200, 800);
    w.init();
    w.run();
    w.close();
    return 0;
}

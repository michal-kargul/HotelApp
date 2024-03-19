#include "Menu.h"

Menu::Menu(MenuType mt) : mt(mt)
{
    switch (mt)
    {
    case MenuType::Main:
        mapSize = mainMenuMap.size();
        mapPtr = reinterpret_cast<int*>(&mainMenuMap);
        break;
    case MenuType::Decision:
        mapSize = decisionMenuMap.size();
        mapPtr = reinterpret_cast<int*>(&decisionMenuMap);
        break;
    }
}

#include "core/launcher.h"
#include <crtdbg.h>

//#define TEST

#ifndef TEST

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Core::Launcher engine;

    return engine.exec();
}

#else

#endif
#include "core/launcher.h"

int main()
{
    Core::Launcher* engine = new Core::Launcher();

    return engine ? engine->exec() : 1;
}
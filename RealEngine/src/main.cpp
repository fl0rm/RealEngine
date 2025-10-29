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

#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>

int main(int argc, char *argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    SDL_Window* window = SDL_CreateWindow("OpenGL", 800, 600, SDL_WINDOW_OPENGL);

    SDL_GLContext context = SDL_GL_CreateContext(window);
    
    SDL_Event windowEvent;
    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_EVENT_QUIT) break;

        }

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DestroyContext(context);

    SDL_Quit();
    return 0;
}

#endif
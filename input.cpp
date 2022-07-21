#include "engine.h"
#include <iostream>

void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            m_Window.close();
            return;
        }
        if (event.type == Event::KeyReleased) {
            switch (event.key.code) {
            case Keyboard::Key::Escape:
                m_Window.close();
                return;
            case Keyboard::Key::Return:
                m_Playing = true;
                break;
            case Keyboard::Key::Q:
                m_Character1 = !m_Character1;
                break;
            case Keyboard::Key::E:
                m_SplitScreen = !m_SplitScreen;
                break;
            default:
                break;
            }
        }
        if (m_Thomas.handleInput(event)) {
            //play a jump sound
            std::cout << "Thomas jump\n" << std::flush;
        }
        if (m_Bob.handleInput(event)) {
            //play a jump sound
            std::cout << "Bob jump\n" << std::flush;
        }
    }
}

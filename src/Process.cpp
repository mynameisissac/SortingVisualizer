//
// Created by kshou on 2021/12/23.
//

#include "Process.h"
using namespace sf;

const int WINDOW_WIDTH = 512;
const int WINDOW_HEIGHT = 512;

Process::Process()
{
    resolution = Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.create(VideoMode(resolution.x, resolution.y), "Sorting Visualizer", Style::Close | Style::Titlebar);

}


// the main game loop end until the window is closed
void Process::run()
{
    // keep handling input and drawing while the Process is running
    while (window.isOpen()) {
        handleInput();
        draw();
    }

}

// two-buffering drawing
void Process::draw()
{

    window.clear(Color::White);

    window.display();       // swap the back buffer and front buffer
}
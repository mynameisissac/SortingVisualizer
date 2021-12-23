//
// Created by kshou on 2021/12/23.
//

#ifndef SORTINGVISUALIZER_PROCESS_H
#define SORTINGVISUALIZER_PROCESS_H
#include <SFML/Graphics.hpp>

// the flow of the whole program as an object
class Process {
    private:
        // window
        sf::RenderWindow window;
        sf::Vector2i resolution;

    public:
        Process();      // default constructor

        void handleInput();
        void draw();

        // the main loop of the program
        void run();

};


#endif //SORTINGVISUALIZER_PROCESS_H

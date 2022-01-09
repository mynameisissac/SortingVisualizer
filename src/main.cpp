#include "Engine.h"

int SizeOfArray = 1000;     // default initialization of SizeOfArray

int main()
{
    // start an array sorting visualizer with giving a size
    Engine engine(SizeOfArray);
    engine.run();      // the program will finish when run() finish

    return 0;
}

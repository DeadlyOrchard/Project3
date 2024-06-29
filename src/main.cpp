#include "ItemTracker.hpp"
#include <string>

int main()
{
    std::string filePath { "CS210_Project_Three_Input_File.txt" };
    char delimeter { '\n' };
    ItemTracker tracker { filePath, delimeter };
    tracker.run();
    return 0;
}
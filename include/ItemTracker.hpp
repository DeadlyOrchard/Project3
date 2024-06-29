#pragma once
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

class ItemTracker
{
private:
    const int MENU_WIDTH { 48 };
    const std::vector<std::string> MENU_OPTIONS
    {
        "Frequency of a single item",
        "Frequency of all items",
        "Histogram of all items",
        "Exit"
    };
    std::map<std::string, int> m_items;
public:
    ItemTracker(const std::string t_recordsFileName, const char t_delimeter);
    void run();
};

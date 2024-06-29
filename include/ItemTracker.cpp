#include "ItemTracker.hpp"
ItemTracker::ItemTracker(const std::string t_recordsFileName, const char t_delimeter)
{
    // open file for reading
    std::ifstream readRecords(t_recordsFileName);
    if (!readRecords.is_open())
    {
        std::cout << "Could not open file to read from: " << t_recordsFileName << std::endl;
        return;
    }

    // read data
    std::string item;
    while (getline(readRecords, item, t_delimeter))
    {
        ++m_items[item];
    }
    readRecords.close(); // close file

    // save data in .dat file
    // open file for writing
    std::ofstream writeRecords("freqency.dat");
    if (!writeRecords.is_open())
    {
        std::cout << "Could not open file to write to: frequency.dat" << std::endl;
    }

    // write data
    for (const auto& [key, value] : m_items)
    {
        std::string line = key + " " + std::to_string(value) + '\n';
        writeRecords << line;
    }
    writeRecords.close(); // close file
}

void ItemTracker::run()
{
    bool running = true;
    std::cin.exceptions(std::ios_base::failbit);
    std::cout << std::left; // left align

    // core loop
    while (running)
    {
        // center prompt
        std::string prompt { "What would you like to do?" };
        char paddingChar = '-';
        int paddingWidth = (MENU_WIDTH - prompt.length()) / 2;
        std::string padding(paddingWidth, paddingChar);
        prompt = padding + prompt + padding;
        std::cout << ' ' << prompt << '\n'; // add a space for formatting

        // print borderChar at beginning and end for right and left borders
        char borderChar = '|';
        for (int i = 0; i < MENU_OPTIONS.size(); ++i)
        {
            // tab is still technically one char, using std::string(5, ' ') as a replacement
            std::string option = std::string(5, ' ') + std::to_string(i + 1) + " - " + MENU_OPTIONS[i];
            std::cout << borderChar << std::setw(MENU_WIDTH) << option << borderChar << '\n';
        }

        // bottom border
        std::cout << ' ' << std::string(MENU_WIDTH, paddingChar) << "\n\n";

        prompt = "Option number: ";
        std::cout << prompt;
        int selectedOption;
        // get input & validate it
        try
        {
            std::cin >> selectedOption;
        }
        catch (std::ios_base::failure& e)
        {
            // clear err bits, ignore input, and print err msg
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a number 1-4" << std::endl;
            continue;
        }

        std::cout << std::endl; // flush stream before handling the selected option
        std::string selectedItem; // used in option 1
        switch(selectedOption)
        {
        case 1: // Frequency of a single item
            std::cout << "Item name: ";
            /*  since, 
                we're returning 0 for any keys not in the map,
                and selectItem is a string,
                no input validating necessary   */
            std::cin >> selectedItem;

            if (m_items.count(selectedItem) != 0)
                std::cout << selectedItem << " - " << m_items[selectedItem] << '\n';
            else
                std::cout << selectedItem << " - 0\n";
            break;

        case 2: // Frequency of all items
            for (const auto& [key, value] : m_items)
                std::cout << key << " - " << value << '\n';
            break;

        case 3: // Histogram of all items
            for (const auto& [key, value] : m_items)
                std::cout << key << " - " << std::string(value, '*') << '\n';
            break;

        case 4: // Exit
            running = false;
            break;

        }
    }
}
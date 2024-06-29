# The Problem
- The scenario given for the problem is a grocer wanting to track how many products of each product type are being sold each day.
- Rather than tediously giving the computer input throughout the day, the grocer wants a program that reads from a .txt file (a list of sold products) to find this information.
- To ensure the data gathered by the program is not corrupted or lost, the grocer also wants the program to create a file to backup the data on the hard drive.

### Project Strengths
- My biggest strength on this project was enforcing locality of behavior with the scope of the project in mind. Because the grocer doesn't require the functionality to create a chart/table, storing the gathered data in a map was quite trivial. 

### Project Weaknesses
- My biggest weakness on this project was iterating over a map. I wasn't 100% sure which method of iteration,
    - `for (const auto& [key, value] : t_map)` (C++17)
    - `for (auto mapItem : t_map)` (C++11)
    - `for (auto i = t_map.begin(); i != t_map.end(); ++i)` (C++99)
- While I don't love using the auto keyword, it seemed best to use the C++17 way of doing things for readability and security.

### Project Challenges
- I was stumped for a while near the beginning of the project because the `ItemTracker` couldn't open the text file. I knew that the program would look in the current directory for the file, but I assumed the current directory for the program would be the directory that the file is in. Come to find out, the current directory is the directory from which the program is ran. So passing the command, `.\bin\main.exe` in order to run the program resulted in a file does not exist type err. 
- I fixed this by having two terminals open while debugging. One terminal was used for building the project by running `.src\build.bat` while the other was used for running the executable from the `bin` subdirectory.

### Transferable Skills
- Reading/writing from/to files is useful in almost any program. After all, it's the simplest method of create save game functionality for a game engine. Similarly, any time a program needs to offload memory to switch to some other context of functionality, writing the context of the program to a file ensures that the offloaded memory can still be found later.

### Maintainability
- The entire program can be boiled down into two stages of functionality. 
- This makes the program very simple to understand because the two stages of functionality are independent of each other. Of course, the first stage must happen before the second, but the functionality is independent. 
    - If someone wants to include some other method of viewing the data, they know to make changes within the second stage. 
    - Similarly, if someone wants to include some other calculation of the raw data (such as mean/average), they know to make changes within the first stage.
        - Note that in order to view such a calculation, changes must be made to the second stage in order to provide access of the data to the user.

#### Stages
1. Gather data.
    - Read through the `.txt` file line by line. Store the line as a key in a map and increment the value corresponding to that key once for each time that key is seen.
    - Store the contents of the map in a `.dat` file by iterating through each key and value.
2. Deliver data in different formats depending on the user's selection from four options
    1. Frequency of a single item
        - Get input from user.
        - Output the value corresponding to that input in the map. 
            - Note that keys which don't exist in the map will have a corresponding value of zero.
    2. Frequency of all items
        - Output contents of the map by iterating through each key and value.
    3. Histogram of all items
        - Output contents of the map by iterating through each key and value.
            - Instead of printing a number for the value, print the same number of some character (i.e. Radishes ***, not Radishes 3).
    4. Exit
        - End Program

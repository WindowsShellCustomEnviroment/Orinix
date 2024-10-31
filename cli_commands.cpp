#include <iostream>
#include <string>
#include "cli_commands.h"
#include <windows.h>
#include <unistd.h>
#include "aurora.h"
#include <filesystem>
#include <dirent.h>


void executeCommand(const std::string& command) {
    if (command == "hello") {
        std::cout << "Hello, User!" << std::endl;
    } else if (command == "help") {
        std::cout << " " << std::endl;
        std::cout << "Available commands:" << std::endl;
        std::cout << "shutdwn = Shuts down Orinix" << std::endl;
        std::cout << "hello = A test command" << std::endl;
        std::cout << "credits = Displays credits of the person that made Orinix" << std::endl;
        std::cout << "nav = Changes the working directory, like cd" << std::endl;
        std::cout << "show = Displays all files and folders in the current working directory" << std::endl;
        std::cout << "clearscr = Clears the screen" << std::endl;
        std::cout << "aurora = Launches the aurora notepad" << std::endl;
        std::cout << " " << std::endl;
    } else if (command == "clearscr") {
        std::cout << "\033[2J\033[H";
    } else if (command == "credits") {
        std::cout << " " << std::endl;
        std::cout << "Orinix V1.0" << std::endl;
        std::cout << "Developed by Orion - 30/10/24" << std::endl;
        std::cout << " " << std::endl;
    } else if (command == "aurora") {
        launchNotepad();
    } else if (command.rfind("nav", 0) == 0) { // Check if the command starts with "nav"
        std::string path = command.substr(4); // Extract the path after "nav "
        if (chdir(path.c_str()) == 0)
            std::cout << "Changed directory to: " << path << std::endl;
    } else if (command == "show") {
        DIR* dir;
        struct dirent* ent;

        // Open the current directory
        if ((dir = opendir(".")) != nullptr) {
            std::cout << " " << std::endl;
            std::cout << "Contents of the current directory:\n";
            // Read entries from the directory
            while ((ent = readdir(dir)) != nullptr) {
                // Skip the '.' and '..' entries
                if (std::string(ent->d_name) != "." && std::string(ent->d_name) != "..") {
                    std::cout << ent->d_name << "\n";  // Print each file/directory name
                }
            }
            std::cout << " " << std::endl;
        }
            closedir(dir);  // Close the directory
    } else {
        std::cout << "Unknown command: " << command << std::endl;
    }
}

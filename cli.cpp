#include <iostream>
#include <string>
#include "cli_commands.h"
#include "cli.h"

void startCLI() {
    std::cout << "\033[2J\033[H";
    #define BOLD "\033[1m"
    #define RESET "\033[0m"
    #define MAGENTA "\033[35m"
    std::string command;
    std::cout << BOLD <<  MAGENTA << "==============================" << std::endl;
    std::cout << BOLD <<  MAGENTA << "|                            |" << std::endl;
    std::cout << BOLD <<  MAGENTA << "|         Orinix CLI         |" << std::endl;
    std::cout << BOLD <<  MAGENTA << "|       Developed By Orion   |" << std::endl;
    std::cout << BOLD <<  MAGENTA << "|                            |" << std::endl;
    std::cout << BOLD <<  MAGENTA << "==============================" << std::endl;
    std::cout << " " << std::endl;
    std::cout << " " << std::endl;
    std::cout << RESET << " " << std::endl;
    while (true) {
        // I was too lazy to come up with my own command label, so im borrowing from linux.
        std::cout << BOLD << "$ ";
        std::getline(std::cin, command);

        if (command == "shutdwn") {
            break;
        }

        executeCommand(command); // Call the command execution function
    }
}

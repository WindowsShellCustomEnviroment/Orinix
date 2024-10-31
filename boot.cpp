#include <iostream>
#include <chrono>
#include <thread>
#include "cli.h"

void showLoadingBar(int totalSteps) {
    int barWidth = 50; // How fat the loading bar is (In this case it's microscopic in comparison to CaseOh)

    for (int i = 0; i <= totalSteps; ++i) {
        int progress = (i * barWidth) / totalSteps;

        std::cout << "\r["; // Carriage return to overwrite the line
        for (int j = 0; j < barWidth; ++j) {
            if (j < progress) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }

        std::cout << "] " << (i * 100) / totalSteps << "%";
        std::cout.flush();

        // Faking the code doing stuff because this is a fake boot (hehe)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << std::endl;
}


int main() {
    // C O L O R S (The only thing you see when your on drugs and the one thing C comments lack)
    const std::string WHITE = "\033[97m";
    const std::string GREEN = "\033[92m";
    const std::string RESET = "\033[0m";

    // Text, there's nothing more to it, it's just text
    std::cout << WHITE << "[" << GREEN << "OK" << WHITE << "] Starting C++ Engine" << RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << WHITE << "[" << GREEN << "OK" << WHITE << "] Starting Driver Service" << RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(4));
    std::cout << WHITE << "[" << GREEN << "OK" << WHITE << "] Intializing Drivers for your hardware" << RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "\033[2J\033[H";
    std::cout << WHITE << "Booting Orinix" << RESET << std::endl;
    int totalSteps = 100;
    showLoadingBar(totalSteps);
    startCLI();
}

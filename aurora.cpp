// NotepadCLI.cpp
#include "aurora.h"
#include <iostream>
#include <fstream>
#include "cli.h"
NotepadCLI::NotepadCLI() {
    // Constructor - does nothing special here
}

void NotepadCLI::showMenu() {
    std::cout << "\033[2J\033[H";
    std::cout << "Aurora Notepad\n";
    std::cout << "1. Create new note\n";
    std::cout << "2. Open existing note\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}

void NotepadCLI::createNote() {
    std::cout << "\033[2J\033[H";
    std::string filename, content;
    std::cout << "Enter filename for new note: ";
    std::cin >> filename;
    std::ofstream file(filename.c_str());
    std::cout << "\033[2J\033[H";
    if (file.is_open()) {
        std::cout << "Start writing your note (type 'exit' to finish):\n";
        std::cin.ignore();  // To clear the newline character left by std::cin

        while (true) {
            std::getline(std::cin, content);
            if (content == "exit") break;
            file << content << "\n";
        }

        file.close();
        std::cout << "Note saved successfully.\n";
    } else {
        std::cerr << "Error creating the file!\n";
    }
}

void NotepadCLI::openNote() {
    std::string filename, line;
    std::cout << "Enter filename to open: ";
    std::cin >> filename;
    std::ifstream file(filename.c_str());

    if (file.is_open()) {
        std::cout << "\nNote Contents:\n";
        while (getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    } else {
        std::cerr << "File not found.\n";
    }
}

// Function to launch the NotepadCLI and handle the menu loop
void launchNotepad() {
    NotepadCLI notepad;
    int choice;
    while (true) {
        notepad.showMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                notepad.createNote();
                break;
            case 2:
                notepad.openNote();
                break;
            case 3:
                std::cout << "Exiting...\n";
                startCLI();
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

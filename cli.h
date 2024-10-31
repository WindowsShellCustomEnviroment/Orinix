#ifndef CLI_H
#define CLI_H

#include <string>

// Function to start the CLI because without it the OS is essentially a cool boot animation template
void startCLI();

// Function to execute commands from the CLI
void executeCommand(const std::string& command);

#endif // CLI_H

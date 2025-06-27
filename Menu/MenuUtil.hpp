#pragma once
#include <iostream>
#include <string>
#include <limits>

// Utility class for menu input/output and common operations
class MenuUtil {
protected:
    void printInfo(const std::string& text) const;    // Print informational message in cyan
    void printSuccess(const std::string& text) const; // Print success message in green
    void printError(const std::string& text) const;   // Print error message in red
    void waitForReturn() const;                        // Pause and wait for user to press Enter
    bool readOption(int& option) const;                // Read integer option from input safely
};

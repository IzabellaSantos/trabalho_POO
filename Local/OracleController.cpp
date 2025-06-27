#include "OracleController.hpp"
#include <ctime>
#include <cstdlib>

// Constructor seeds random generator for price simulation
OracleController::OracleController() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Returns the price for the given date or a fixed price for "today"
double OracleController::getPrice(const std::string &date) const {
    if (date == "today") {
        return 5.50;  // Fixed price for today
    } else {
        unsigned int seed = 0;
        for (char c : date) {
            seed += static_cast<unsigned int>(c);
        }
        double price = 90.0 + (seed % 21);
        return price;
    }
}

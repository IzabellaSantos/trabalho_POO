#ifndef ORACLE_CONTROLLER_HPP
#define ORACLE_CONTROLLER_HPP

#include <string>

// OracleController simulates price quotes retrieval
class OracleController {
public:
    OracleController();

    // Returns the price for a given date (format YYYY-MM-DD or "today")
    virtual double getPrice(const std::string &date) const;
};

#endif

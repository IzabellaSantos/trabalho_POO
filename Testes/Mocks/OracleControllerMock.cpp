#include "../../Local/OracleController.hpp"

class OracleControllerMock : public OracleController {
public:
    double getPrice(const std::string& date) const override {
        return 10.0;  // Fixed mock price
    }
};

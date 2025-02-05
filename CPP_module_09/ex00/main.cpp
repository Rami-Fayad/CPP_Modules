#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>\n";
        return 1;
    }

    BitcoinExchange btc;
    btc.loadDatabase("data.csv");  // Load Bitcoin prices from a database file
    btc.processInputFile(argv[1]); // Process user input file

    return 0;
}

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>

class FileReplacer {
private:
    std::string filename; // Name of the input file
    std::string s1;       // String to be replaced
    std::string s2;       // String to replace with

public:
    // Constructor
    FileReplacer(const std::string &filename, const std::string &s1, const std::string &s2);

    // Main function to process the file
    bool replace();
};

#endif

#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>

// Constructor to initialize the FileReplacer object
FileReplacer::FileReplacer(const std::string &filename, const std::string &s1, const std::string &s2)
    : filename(filename), s1(s1), s2(s2) {}

// Function to process the file
bool FileReplacer::replace() {
    // Open the input file for reading
    std::ifstream inputFile(filename.c_str()); // Convert std::string to const char*
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for reading." << std::endl;
        return false;
    }

    // Open the output file for writing
    std::ofstream outputFile((filename + ".replace").c_str()); // Convert std::string to const char*
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create file " << filename << ".replace for writing." << std::endl;
        return false;
    }

    // Read and process the input file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        // Replace occurrences of s1 with s2 in the current line
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        // Write the modified line to the output file
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
    return true;
}

#include <iostream>
#include <cctype> // for toupper

int main(int argc, char **argv) {
    if (argc == 1) {
        // No arguments provided
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } 
       
        for (int i = 1; i < argc; ++i) {
            for (int j = 0; argv[i][j] != '\0'; ++j) {
                std::cout << (char)std::toupper(argv[i][j]);
            }
            if (i < argc -1)
            std::cout << " " ;
        }
        std::cout << std::endl; // End the line after output
    
    return 0;
}

//
// Created by teufel on 8/29/2019.
//

#ifndef TRIPLETRIAD_KEYBOARD_HPP
#define TRIPLETRIAD_KEYBOARD_HPP

#include <iostream>
#include <cstring>

class Keyboard {
public:
    static int readInteger(std::string& prompt) {
        int ret;
        bool repeat = true;
        std::cout << prompt;
        while (repeat) {
            repeat = false;
            std::cin >> ret;
            if (std::cin.fail()) {
                repeat = true;
                std::cin.clear();
                std::cin.ignore();
            }
        }
        return ret;
    }
    static void readIntegers(const char* prompt, std::vector<int>& toFill) {
        if (std::strlen(prompt) > 0)
            std::cout << prompt << std::flush;

        std::string input_string; input_string.assign("");
        std::getline(std::cin, input_string);

        std::stringstream input_parser_stream(input_string);
        for ( std::string input_element; std::getline(input_parser_stream, input_element, ' '); toFill.push_back(std::stoi(input_element)) );
    }
    static bool readYesNo(std::string& prompt) {
        return Keyboard::readYesNo(prompt.c_str());
    }
    static bool readYesNo(const char* prompt) {
        bool ret = false;
        while(true) {
            if (std::strlen(prompt) > 0)
                std::cout << prompt << std::endl << std::flush;
            std::string line; line.assign("");
            std::cin >> line;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
            }

            char c = line.at(0);
            if ( c == 'Y' || c == 'y' ) {
                ret = true;
                break;
            } else if ( c == 'N' || c == 'n') {
                ret = false;
                break;
            }
        }

        return ret;
    }
};


#endif //TRIPLETRIAD_KEYBOARD_HPP

//
// Created by teufel on 5/7/2021.
//

#include "src/Card.h"

int main(int argc, char** argv) {

    try {
        Card x = Card(10, 0, 1, 1);
        std::cout << x << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    Card y = Card(10, 1, 1, 1);
    std::cout << y << std::endl;

    return 0;
}
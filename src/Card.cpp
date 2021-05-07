//
// Created by teufel on 8/28/2019.
//

#include "Card.h"
#include "Keyboard.hpp"

Card::Card() : top(0), right(0), bottom(0), left(0), sum(0) {}

Card::Card(int top, int right, int bottom, int left)
: top(top), left(left), bottom(bottom), right(right), sum(top+right+bottom+left)
{
    if ( top < Card::MIN_VALUE || top > Card::MAX_VALUE ||
            right < Card::MIN_VALUE || right > Card::MAX_VALUE ||
            bottom < Card::MIN_VALUE || bottom > Card::MAX_VALUE ||
            left < Card::MIN_VALUE || left > Card::MAX_VALUE
    ) {
        throw std::exception();
    }
}

int Card::getTop() const {
    return top;
}

void Card::setTop(int topValue) {
    top = topValue;
}

int Card::getRight() const {
    return right;
}

void Card::setRight(int rightValue) {
    right = rightValue;
}

int Card::getBottom() const {
    return bottom;
}

void Card::setBottom(int bottomValue) {
    bottom = bottomValue;
}

int Card::getLeft() const {
    return left;
}

void Card::setLeft(int leftValue) {
    left = leftValue;
}

int Card::getEdgeSum() const {
    return sum;
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << card.top << " " << card.right << " " << card.bottom << " " << card.left;
    return os;
}

bool Card::operator==(const Card &rhs) const {
    return top == rhs.top &&
           right == rhs.right &&
           bottom == rhs.bottom &&
           left == rhs.left;
}

bool Card::operator!=(const Card &rhs) const {
    return !(rhs == *this);
}

int Card::compareTo(const Card &rhs) const {
    if (sum != rhs.sum)
        return sum - rhs.sum;
    else if (top != rhs.top)
        return top - rhs.top;
    else if (right != rhs.right)
        return right - rhs.right;
    else if (bottom != rhs.bottom)
        return bottom - rhs.bottom;
    else
        return left - rhs.left;
}

int Card::hashCode() const {
    return top * 1000000 + right * 10000 +
        bottom * 100 + right;
}

Card Card::read() {
    const char* prompt = "Enter card (top right bottom left):\0";
    const char input_delimiter = ' ';
    std::string input_string;
    input_string.assign("");
    std::vector<int> num;
    bool good = false;

    while( ! good ) {
        good = true;
        // Get numbers from User.
        Keyboard::readIntegers(prompt, num);
        if (num.size() != 4) {
            std::cout << num.size() << std::endl;
            std::cout << "Invalid card value" << std::endl;
            good = false;
            num.clear();
        }
        for ( const auto& n : num ) {
            if ( n < Card::MIN_VALUE || n > Card::MAX_VALUE ) {
                std::cout << "Invalid card value" << std::endl;
                good = false;
                break;
            }
        }
    }
    return {num[0], num[1], num[2], num[3]};
}

bool Card::isNull() {
    return (sum == 0);
}

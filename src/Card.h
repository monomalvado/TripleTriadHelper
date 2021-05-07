//
// Created by teufel on 8/28/2019.
//

#ifndef TRIPLETRIAD_CARD_H
#define TRIPLETRIAD_CARD_H

#include <ostream>
#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Card {
public:
    const static int MIN_VALUE = 1;
    const static int MAX_VALUE = 10;

    Card();
    Card(int, int, int, int);

    int getTop() const;
    void setTop(int top);
    int getRight() const;
    void setRight(int right);
    int getBottom() const;
    void setBottom(int bottom);
    int getLeft() const;
    void setLeft(int left);
    int getEdgeSum() const;

    friend std::ostream &operator<<(std::ostream &os, const Card &card);
    bool operator==(const Card &rhs) const;
    bool operator!=(const Card &rhs) const;
    bool isNull();

    int compareTo(const Card &rhs) const;
    int hashCode() const;

    static Card read();

private:
    int top;
    int right;
    int bottom;
    int left;
    int sum;
};


#endif //TRIPLETRIAD_CARD_H

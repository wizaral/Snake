#pragma once

struct Coordinate {
    int x, y;
};

Coordinate operator+(const Coordinate &lhs, const Coordinate &rhs);
Coordinate operator-(const Coordinate &lhs, const Coordinate &rhs);

Coordinate &operator+=(Coordinate &lhs, const Coordinate &rhs);
Coordinate &operator-=(Coordinate &lhs, const Coordinate &rhs);

bool operator==(const Coordinate &lhs, const Coordinate &rhs);
bool operator!=(const Coordinate &lhs, const Coordinate &rhs);

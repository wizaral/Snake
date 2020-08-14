#include "coordinate.hpp"

Coordinate operator+(const Coordinate &lhs, const Coordinate &rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}
Coordinate operator-(const Coordinate &lhs, const Coordinate &rhs) {
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

Coordinate &operator+=(Coordinate &lhs, const Coordinate &rhs) {
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}
Coordinate &operator-=(Coordinate &lhs, const Coordinate &rhs) {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

bool operator==(const Coordinate &lhs, const Coordinate &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator!=(const Coordinate &lhs, const Coordinate &rhs) {
    return !(lhs == rhs);
}

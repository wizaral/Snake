#include "field.hpp"

Field::Field(std::size_t height, std::size_t width)
    : height_(height)
    , width_(width)
    , field_(height * width, false) {}

std::size_t Field::height() const {
    return height_;
}

std::size_t Field::width() const {
    return width_;
}

bool Field::operator[](const Coordinate &c) const {
    return field_[access(c, width_)];
}

std::vector<bool>::reference Field::operator[](const Coordinate &c) {
    return field_[access(c, width_)];
}

std::size_t Field::access(const Coordinate &c, std::size_t width) {
    return c.x + c.y * width;
}

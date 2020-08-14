#pragma once
#include <functional>
#include <vector>
#include "body.hpp"

class Field {
protected:
    std::size_t height_, width_;
    std::vector<bool> field_;
public:
    virtual ~Field() = default;
    Field(std::size_t height, std::size_t width);

    std::size_t height() const;
    std::size_t width() const;

    bool operator[](const Coordinate &c) const;
    std::vector<bool>::reference operator[](const Coordinate &c);
private:
    static std::size_t access(const Coordinate &c, std::size_t width);
};

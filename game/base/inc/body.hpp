#pragma once
#include <array>
#include <deque>
#include "coordinate.hpp"
#include "direction.hpp"

class Body {
protected:
    std::deque<Coordinate> body_;
    Direction head_direction_, tail_direction_;

public:
    virtual ~Body() = default;

    template <class It>
    Body(It first, It last)
        : body_(first, last)
        , head_direction_(head(body_))
        , tail_direction_(tail(body_)) {}

    Direction head_direction() const;
    Direction tail_direction() const;
    const std::deque<Coordinate> &body() const;

    virtual Coordinate head() const;
    virtual Coordinate tail() const;

    virtual void step();
    virtual void grow();
    virtual void turn(Direction direction);
    virtual void ultimate();

protected:
    static Direction head(const std::deque<Coordinate> &body);
    static Direction tail(const std::deque<Coordinate> &body);
    static Direction direction(const Coordinate &c);

    inline static constexpr std::array<Coordinate, 4> vectors{
        Coordinate{+0, +1},
        Coordinate{+1, +0},
        Coordinate{-0, -1},
        Coordinate{-1, -0},
    };
};

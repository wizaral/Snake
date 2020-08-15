#pragma once
#include <functional>
#include "body.hpp"

class SwapBody : virtual public Body {
protected:
    enum class HeadPosition {
        Head,
        Tail,
    } position_ = HeadPosition::Head;

public:
    template <class It>
    SwapBody(It first, It last)
        : Body(first, last) {}

    Coordinate head() const override;
    Coordinate tail() const override;

    void step() override;
    void grow() override;
    void ultimate() override;

protected:
    inline static constexpr std::array<void (std::deque<Coordinate>::*)(Coordinate &&), 2> pushes{
        &std::deque<Coordinate>::push_front,
        &std::deque<Coordinate>::push_back,
    };
    inline static constexpr std::array<void (std::deque<Coordinate>::*)(), 2> pops{
        &std::deque<Coordinate>::pop_front,
        &std::deque<Coordinate>::pop_back,
    };
    inline static constexpr std::array<const Coordinate &(std::deque<Coordinate>::*)() const, 2> heads{
        &std::deque<Coordinate>::front,
        &std::deque<Coordinate>::back,
    };
    inline static constexpr std::array<Direction (*)(const std::deque<Coordinate> &), 2> directions{
        &Body::head,
        &Body::tail,
    };
};

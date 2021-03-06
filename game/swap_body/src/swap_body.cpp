#include "swap_body.hpp"

Coordinate SwapBody::head() const {
    return std::invoke(heads[static_cast<int>(position_)], body_);
}

Coordinate SwapBody::tail() const {
    return std::invoke(heads[static_cast<int>(position_) ^ 1], body_);
}

void SwapBody::step() {
    grow();
    std::invoke(pops[static_cast<int>(position_) ^ 1], body_);
    tail_direction_ = directions[static_cast<int>(position_) ^ 1](body_);
}

void SwapBody::grow() {
    std::invoke(pushes[static_cast<int>(position_)], body_, head() + vectors[static_cast<int>(head_direction_)]);
}

void SwapBody::ultimate() {
    position_ = static_cast<HeadPosition>(static_cast<int>(position_) ^ 1);
    head_direction_ = directions[static_cast<int>(position_)](body_);
    tail_direction_ = directions[static_cast<int>(position_) ^ 1](body_);
}

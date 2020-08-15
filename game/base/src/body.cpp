#include "body.hpp"

Direction Body::direction() const {
    return direction_;
}

const std::deque<Coordinate> &Body::body() const {
    return body_;
}

Coordinate Body::head() const {
    return body_.front();
}

Coordinate Body::tail() const {
    return body_.back();
}

void Body::step() {
    grow();
    body_.pop_back(); // no size check
}

void Body::grow() {
    body_.push_front(body_.front() + vectors[static_cast<int>(direction_)]);
}

void Body::turn(Direction direction) {
    direction_ = direction;
}

void Body::ultimate() {}

Direction Body::head(const std::deque<Coordinate> &body) {
    return direction(body[0] - body[1]);
}

Direction Body::direction(const Coordinate &c) {
    return static_cast<Direction>(((c.x + c.y) < 0) * 2 + (c.x != 0));
}

#include "body.hpp"

Direction Body::head_direction() const {
    return head_direction_;
}

Direction Body::tail_direction() const {
    return tail_direction_;
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
    tail_direction_ = tail(body_);
}

void Body::grow() {
    body_.push_front(body_.front() + vectors[static_cast<int>(head_direction_)]);
}

void Body::turn(Direction direction) {
    head_direction_ = direction;
}

void Body::ultimate() {}

Direction Body::head(const std::deque<Coordinate> &body) {
    return direction(body[0] - body[1]);
}

Direction Body::tail(const std::deque<Coordinate> &body) {
    return direction(body.back() - *++body.rbegin());
}

Direction Body::direction(const Coordinate &c) {
    return static_cast<Direction>(((c.x + c.y) < 0) * 2 + (c.x != 0));
}

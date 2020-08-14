#pragma once
#include <functional>
#include "body.hpp"

class DoubleGrowBody : public Body {
public:
    template <class It>
    DoubleGrowBody(It first, It last)
        : Body(first, last) {}

    void grow() override;
};

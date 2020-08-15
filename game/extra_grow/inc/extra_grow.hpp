#pragma once
#include <functional>
#include "body.hpp"

class ExtraGrowBody : public Body {
public:
    template <class It>
    ExtraGrowBody(It first, It last)
        : Body(first, last) {}

    void ultimate() override;
};

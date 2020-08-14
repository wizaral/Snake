#include "direction.hpp"

Direction operator!(Direction d) {
    return static_cast<Direction>(static_cast<int>(d) ^ 2);
}

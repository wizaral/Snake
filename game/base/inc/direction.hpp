#pragma once

enum class Direction {
    Upward,
    Right,
    Down,
    Left,
};

Direction operator!(Direction d);

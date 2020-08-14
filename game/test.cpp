#include "body.hpp"
#include "direction.hpp"
#include "swap_body.hpp"
#include "test_runner.hpp"

static std::array<std::string, 4> s{
    "Upward",
    "Right",
    "Down",
    "Left",
};

static std::ostream &operator<<(std::ostream &os, const Coordinate &c) {
    return os << '{' << c.x << ", " << c.y << '}';
}

static std::ostream &operator<<(std::ostream &os, Direction d) {
    return os << s[static_cast<int>(d)];
}

void test_direction() {
    Direction d1 = Direction::Upward;
    Direction d2 = Direction::Right;

    ASSERT_EQUAL(d1, Direction::Upward);
    ASSERT_EQUAL(d2, Direction::Right);

    d1 = !d1;
    d2 = !d2;

    ASSERT_EQUAL(d1, Direction::Down);
    ASSERT_EQUAL(d2, Direction::Left);

    d1 = !d1;
    d2 = !d2;

    ASSERT_EQUAL(d1, Direction::Upward);
    ASSERT_EQUAL(d2, Direction::Right);
}

void test_swap_direction() {
    {
        std::deque<Coordinate> coords{
            {0, 0},
            {1, 0},
            {2, 0},
            {3, 0},
            {4, 0},
        };

        SwapBody body(coords.begin(), coords.end());
        ASSERT_EQUAL(body.direction(), Direction::Left);
        body.ultimate();
        ASSERT_EQUAL(body.direction(), Direction::Right);
    }
    {
        std::deque<Coordinate> coords{
            {-0, 0},
            {-1, 0},
            {-2, 0},
            {-3, 0},
            {-4, 0},
        };

        SwapBody body(coords.begin(), coords.end());
        ASSERT_EQUAL(body.direction(), Direction::Right);
        body.ultimate();
        ASSERT_EQUAL(body.direction(), Direction::Left);
    }
    {
        std::deque<Coordinate> coords{
            {0, 0},
            {0, 1},
            {0, 2},
            {0, 3},
            {0, 4},
        };

        SwapBody body(coords.begin(), coords.end());
        ASSERT_EQUAL(body.direction(), Direction::Down);
        body.ultimate();
        ASSERT_EQUAL(body.direction(), Direction::Upward);
    }
    {
        std::deque<Coordinate> coords{
            {0, -0},
            {0, -1},
            {0, -2},
            {0, -3},
            {0, -4},
        };

        SwapBody body(coords.begin(), coords.end());
        ASSERT_EQUAL(body.direction(), Direction::Upward);
        body.ultimate();
        ASSERT_EQUAL(body.direction(), Direction::Down);
    }
}

void test_swap() {
    std::deque<Coordinate> coords{
        {0, -0},
        {0, -1},
        {0, -2},
        {0, -3},
        {0, -4},
    };

    SwapBody body(coords.begin(), coords.end());
    body.step();
    body.ultimate();
    body.step();

    ASSERT_EQUAL(body.body(), coords);
    body.step();
    body.ultimate();
    body.step();

    ASSERT_EQUAL(body.body(), coords);
}

void test_head_tail() {
    std::deque<Coordinate> coords{
        {0, 0},
        {0, 1},
        {0, 2},
        {0, 3},
        {0, 4},
    };

    Coordinate head{0, 0};
    Coordinate tail{0, 4};

    SwapBody body(coords.begin(), coords.end());
    body.step();
    body.ultimate();
    body.step();

    ASSERT_EQUAL(body.head(), tail);
    ASSERT_EQUAL(body.tail(), head);

    body.step();
    body.ultimate();
    body.step();

    ASSERT_EQUAL(body.head(), head);
    ASSERT_EQUAL(body.tail(), tail);
}

void tests() {
    TestRunner tr(false);
    RUN_TEST(tr, test_direction);
    RUN_TEST(tr, test_swap_direction);
    RUN_TEST(tr, test_swap);
    RUN_TEST(tr, test_head_tail);
}

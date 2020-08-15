#include "body.hpp"
#include "direction.hpp"
#include "field.hpp"
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

void test_direction_operator() {
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

void test_head_direction() {
    {
        std::deque<Coordinate> coords{
            {0, 0},
            {1, 0},
            {2, 0},
        };

        Body body(coords.begin(), coords.end());

        body.step();
        ASSERT_EQUAL(body.head_direction(), Direction::Left);

        body.turn(Direction::Upward);
        ASSERT_EQUAL(body.head_direction(), Direction::Upward);

        body.step();
        ASSERT_EQUAL(body.head_direction(), Direction::Upward);
    }
}

void test_tail_direction() {
    {
        std::deque<Coordinate> coords{
            {0, 0},
            {1, 0},
            {2, 0},
        };

        Body body(coords.begin(), coords.end());

        body.turn(Direction::Upward);
        ASSERT_EQUAL(body.tail_direction(), Direction::Right);

        body.step();
        ASSERT_EQUAL(body.tail_direction(), Direction::Right);

        body.step();
        ASSERT_EQUAL(body.tail_direction(), Direction::Down);
    }
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
        ASSERT_EQUAL(body.head_direction(), Direction::Left);
        body.ultimate();
        ASSERT_EQUAL(body.head_direction(), Direction::Right);
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
        ASSERT_EQUAL(body.head_direction(), Direction::Right);
        body.ultimate();
        ASSERT_EQUAL(body.head_direction(), Direction::Left);
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
        ASSERT_EQUAL(body.head_direction(), Direction::Down);
        body.ultimate();
        ASSERT_EQUAL(body.head_direction(), Direction::Upward);
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
        ASSERT_EQUAL(body.head_direction(), Direction::Upward);
        body.ultimate();
        ASSERT_EQUAL(body.head_direction(), Direction::Down);
    }
    {
        std::deque<Coordinate> coords{
            {0, -0},
            {0, -1},
            {1, -1},
            {1, -2},
            {2, -2},
        };

        SwapBody body(coords.begin(), coords.end());
        ASSERT_EQUAL(body.head_direction(), Direction::Upward);
        body.ultimate();
        ASSERT_EQUAL(body.head_direction(), Direction::Right);
    }
    {
        std::deque<Coordinate> coords{
            {0, 0},
            {0, 1},
            {1, 1},
            {1, 0},
        };

        SwapBody body(coords.begin(), coords.end());
        ASSERT_EQUAL(body.head_direction(), Direction::Down);
        body.ultimate();
        ASSERT_EQUAL(body.head_direction(), Direction::Down);
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

void test_field_assign() {
    Coordinate _0{0, 0}, _1{1, 1}, _2{2, 2}, _3{3, 3};
    Field field(4, 4);

    ASSERT(field[_0] == false);
    ASSERT(field[_1] == false);
    ASSERT(field[_2] == false);
    ASSERT(field[_3] == false);

    field[_0] = true;
    field[_1] = true;
    field[_2] = true;
    field[_3] = true;

    ASSERT(field[_0]);
    ASSERT(field[_1]);
    ASSERT(field[_2]);
    ASSERT(field[_3]);

    field[_0] = false;
    field[_1] = false;
    field[_2] = false;
    field[_3] = false;

    ASSERT(field[_0] == false);
    ASSERT(field[_1] == false);
    ASSERT(field[_2] == false);
    ASSERT(field[_3] == false);
}

void tests() {
    TestRunner tr(false);

    RUN_TEST(tr, test_direction_operator);
    RUN_TEST(tr, test_head_direction);
    RUN_TEST(tr, test_tail_direction);
    RUN_TEST(tr, test_swap_direction);
    RUN_TEST(tr, test_swap);
    RUN_TEST(tr, test_head_tail);
    RUN_TEST(tr, test_field_assign);
}

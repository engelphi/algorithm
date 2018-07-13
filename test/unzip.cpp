#include <internal/unzip.hpp>

#include <catch.hpp>

#include <deque>
#include <forward_list>
#include <list>
#include <vector>

TEST_CASE("unzip", "[unzip]") {
    SECTION("unzip should unzip elements from a vector ") {
        std::vector<std::pair<int, char>> input{
            {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
        SECTION("to vectors") {
            std::vector<int> expected_first_range{1, 2, 3, 4, 5};
            std::vector<int> first_range{};
            std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::vector<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }

        SECTION("to lists") {
            std::list<int> expected_first_range{1, 2, 3, 4, 5};
            std::list<int> first_range{};
            std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::list<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }

        SECTION("to deques") {
            std::deque<int> expected_first_range{1, 2, 3, 4, 5};
            std::deque<int> first_range{};
            std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::deque<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }
    }

    SECTION("unzip should unzip elements from a list") {
        std::list<std::pair<int, char>> input{
            {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
        SECTION("to vectors") {
            std::vector<int> expected_first_range{1, 2, 3, 4, 5};
            std::vector<int> first_range{};
            std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::vector<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }

        SECTION("to lists") {
            std::list<int> expected_first_range{1, 2, 3, 4, 5};
            std::list<int> first_range{};
            std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::list<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }

        SECTION("to deques") {
            std::deque<int> expected_first_range{1, 2, 3, 4, 5};
            std::deque<int> first_range{};
            std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::deque<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }
    }

    SECTION("unzip should unzip elements from a forward_list") {
        std::forward_list<std::pair<int, char>> input{
            {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
        SECTION("to vectors") {
            std::vector<int> expected_first_range{1, 2, 3, 4, 5};
            std::vector<int> first_range{};
            std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::vector<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }

        SECTION("to lists") {
            std::list<int> expected_first_range{1, 2, 3, 4, 5};
            std::list<int> first_range{};
            std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::list<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }

        SECTION("to deques") {
            std::deque<int> expected_first_range{1, 2, 3, 4, 5};
            std::deque<int> first_range{};
            std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::deque<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }
    }

    SECTION("unzip should unzip elements from a deque") {
        std::deque<std::pair<int, char>> input{
            {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
        SECTION("to vectors") {
            std::vector<int> expected_first_range{1, 2, 3, 4, 5};
            std::vector<int> first_range{};
            std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::vector<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }

        SECTION("to lists") {
            std::list<int> expected_first_range{1, 2, 3, 4, 5};
            std::list<int> first_range{};
            std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::list<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }

        SECTION("to deques") {
            std::deque<int> expected_first_range{1, 2, 3, 4, 5};
            std::deque<int> first_range{};
            std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
            std::deque<char> second_range{};
            algo::unzip(input.begin(), input.end(),
                        std::back_inserter(first_range),
                        std::back_inserter(second_range));
            REQUIRE(expected_first_range == first_range);
            REQUIRE(expected_second_range == second_range);
        }
    }
}


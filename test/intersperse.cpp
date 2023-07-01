#include <catch2/catch.hpp>

#include <internal/intersperse.hpp>

#include <array>
#include <deque>
#include <forward_list>
#include <iterator>
#include <list>
#include <vector>

TEST_CASE("intersperse", "[intersperse]") {
    SECTION("intersperse on empty range should leave destination range empty") {
        SECTION("(vector)") {
            std::vector<int> input{};
            std::vector<int> output{};
            std::vector<int> expected{};
            algo::intersperse(input.begin(), input.end(),
                              std::back_inserter(output), 1);
            REQUIRE(expected == output);
        }

        SECTION("(list)") {
            std::list<int> input{};
            std::list<int> output{};
            std::list<int> expected{};
            algo::intersperse(input.begin(), input.end(),
                              std::back_inserter(output), 1);
            REQUIRE(expected == output);
        }

        SECTION("(deque)") {
            std::deque<int> input{};
            std::deque<int> output{};
            std::deque<int> expected{};
            algo::intersperse(input.begin(), input.end(),
                              std::back_inserter(output), 1);
            REQUIRE(expected == output);
        }

        SECTION("(forward_list)") {
            std::forward_list<int> input{};
            std::forward_list<int> output{};
            std::forward_list<int> expected{};
            algo::intersperse(input.begin(), input.end(), output.begin(), 1);
            REQUIRE(expected == output);
        }

        SECTION("(array)") {
            std::array<int, 1> input{};
            std::array<int, 1> output{};
            std::array<int, 1> expected{};
            algo::intersperse(input.begin(), input.end(), output.begin(), 1);
            REQUIRE(expected == output);
        }
    }

    SECTION("intersperse elements with given seperator") {
        SECTION("(vector)") {
            std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int seperator = 0;
            std::vector<int> output{};
            std::vector<int> expected{1, 0, 2, 0, 3, 0, 4, 0, 5, 0,
                                      6, 0, 7, 0, 8, 0, 9, 0, 10};
            algo::intersperse(input.begin(), input.end(),
                              std::back_inserter(output), seperator);
            REQUIRE(expected == output);
        }

        SECTION("(list)") {
            std::list<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int seperator = 0;
            std::list<int> output{};
            std::list<int> expected{1, 0, 2, 0, 3, 0, 4, 0, 5, 0,
                                    6, 0, 7, 0, 8, 0, 9, 0, 10};
            algo::intersperse(input.begin(), input.end(),
                              std::back_inserter(output), seperator);
            REQUIRE(expected == output);
        }

        SECTION("(deque)") {
            std::deque<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int seperator = 0;
            std::deque<int> output{};
            std::deque<int> expected{1, 0, 2, 0, 3, 0, 4, 0, 5, 0,
                                     6, 0, 7, 0, 8, 0, 9, 0, 10};
            algo::intersperse(input.begin(), input.end(),
                              std::back_inserter(output), seperator);
            REQUIRE(expected == output);
        }

        SECTION("(forward_list)") {
            std::forward_list<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int seperator = 0;
            std::forward_list<int> output{};
            output.resize(19);
            std::forward_list<int> expected{1, 0, 2, 0, 3, 0, 4, 0, 5, 0,
                                            6, 0, 7, 0, 8, 0, 9, 0, 10};
            algo::intersperse(input.begin(), input.end(), output.begin(),
                              seperator);
            REQUIRE(expected == output);
        }

        SECTION("(array)") {
            std::array<int, 10> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int seperator = 0;
            std::array<int, 19> output{};
            std::array<int, 19> expected{1, 0, 2, 0, 3, 0, 4, 0, 5, 0,
                                         6, 0, 7, 0, 8, 0, 9, 0, 10};
            algo::intersperse(input.begin(), input.end(), output.begin(),
                              seperator);
            REQUIRE(expected == output);
        }
    }
}

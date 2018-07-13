#include <catch.hpp>
#include <internal/span.hpp>

#include <array>
#include <deque>
#include <forward_list>
#include <iterator>
#include <list>
#include <vector>

TEST_CASE("span", "[span]") {
    SECTION("span of empty range leaves output ranges empty") {
        SECTION("(vector)") {
            std::vector<int> input{};
            std::vector<int> outputTrue{};
            std::vector<int> outputFalse{};
            std::vector<int> expectedTrue{};
            std::vector<int> expectedFalse{};

            algo::span(input.begin(), input.end(),
                       std::back_inserter(outputTrue),
                       std::back_inserter(outputFalse),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }

        SECTION("(list)") {
            std::list<int> input{};
            std::list<int> outputTrue{};
            std::list<int> outputFalse{};
            std::list<int> expectedTrue{};
            std::list<int> expectedFalse{};

            algo::span(input.begin(), input.end(),
                       std::back_inserter(outputTrue),
                       std::back_inserter(outputFalse),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }

        SECTION("(deque)") {
            std::deque<int> input{};
            std::deque<int> outputTrue{};
            std::deque<int> outputFalse{};
            std::deque<int> expectedTrue{};
            std::deque<int> expectedFalse{};

            algo::span(input.begin(), input.end(),
                       std::back_inserter(outputTrue),
                       std::back_inserter(outputFalse),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }

        SECTION("(forward_list)") {
            std::forward_list<int> input{};
            std::forward_list<int> outputTrue{};
            std::forward_list<int> outputFalse{};
            std::forward_list<int> expectedTrue{};
            std::forward_list<int> expectedFalse{};

            algo::span(input.begin(), input.end(), outputTrue.begin(),
                       outputFalse.begin(),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }

        SECTION("(array)") {
            std::array<int, 1> input{};
            std::array<int, 1> outputTrue{};
            std::array<int, 1> outputFalse{};
            std::array<int, 1> expectedTrue{};
            std::array<int, 1> expectedFalse{};

            algo::span(input.begin(), input.end(), outputTrue.begin(),
                       outputFalse.begin(),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }

        SECTION("(mixed)") {
            std::vector<int> input{};
            std::vector<int> outputTrue{};
            std::list<int> outputFalse{};
            std::vector<int> expectedTrue{};
            std::list<int> expectedFalse{};

            algo::span(input.begin(), input.end(),
                       std::back_inserter(outputTrue),
                       std::back_inserter(outputFalse),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }
    }

    SECTION("span split elements to ranges according to predicate") {
        SECTION("(vector)") {
            std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::vector<int> outputTrue{};
            std::vector<int> outputFalse{};
            std::vector<int> expectedTrue{1, 2, 3, 4};
            std::vector<int> expectedFalse{5, 6, 7, 8, 9, 10};

            algo::span(input.begin(), input.end(),
                       std::back_inserter(outputTrue),
                       std::back_inserter(outputFalse),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }

        SECTION("(list)") {
            std::list<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::list<int> outputTrue{};
            std::list<int> outputFalse{};
            std::list<int> expectedTrue{1, 2, 3, 4};
            std::list<int> expectedFalse{5, 6, 7, 8, 9, 10};

            algo::span(input.begin(), input.end(),
                       std::back_inserter(outputTrue),
                       std::back_inserter(outputFalse),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }

        SECTION("(deque)") {
            std::deque<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::deque<int> outputTrue{};
            std::deque<int> outputFalse{};
            std::deque<int> expectedTrue{1, 2, 3, 4};
            std::deque<int> expectedFalse{5, 6, 7, 8, 9, 10};

            algo::span(input.begin(), input.end(),
                       std::back_inserter(outputTrue),
                       std::back_inserter(outputFalse),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }

        SECTION("(forward_list)") {
            std::forward_list<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::forward_list<int> outputTrue{};
            outputTrue.resize(4);
            std::forward_list<int> outputFalse{};
            outputFalse.resize(6);
            std::forward_list<int> expectedTrue{1, 2, 3, 4};
            std::forward_list<int> expectedFalse{5, 6, 7, 8, 9, 10};

            algo::span(input.begin(), input.end(), outputTrue.begin(),
                       outputFalse.begin(),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }

        SECTION("(array)") {
            std::array<int, 10> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::array<int, 4> outputTrue{};
            std::array<int, 6> outputFalse{};
            std::array<int, 4> expectedTrue{1, 2, 3, 4};
            std::array<int, 6> expectedFalse{5, 6, 7, 8, 9, 10};

            algo::span(input.begin(), input.end(), outputTrue.begin(),
                       outputFalse.begin(),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }

        SECTION("(mixed)") {
            std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::vector<int> outputTrue{};
            std::list<int> outputFalse{};
            std::vector<int> expectedTrue{1, 2, 3, 4};
            std::list<int> expectedFalse{5, 6, 7, 8, 9, 10};

            algo::span(input.begin(), input.end(),
                       std::back_inserter(outputTrue),
                       std::back_inserter(outputFalse),
                       [](const auto &x) { return x < 5; });

            REQUIRE(expectedTrue == outputTrue);
            REQUIRE(expectedFalse == outputFalse);
        }
    }
}


#include <array>
#include <catch2/catch.hpp>
#include <deque>
#include <forward_list>
#include <internal/zip_with_n.hpp>
#include <list>
#include <vector>

TEST_CASE("zip_with_n", "[zip_with_n]") {
    SECTION("zip_with should zip containers with given operators") {
        SECTION("vectors") {
            std::vector<int> first_range{1, 2, 3, 4, 5};
            std::vector<int> second_range{1, 2, 3, 4, 5};
            std::vector<int> result_range{};
            std::vector<int> expected_result{2, 4, 6};

            algo::zip_with_n(first_range.begin(), second_range.begin(),
                             std::back_inserter(result_range), 3,
                             [](const auto &first, const auto &second) {
                                 return first + second;
                             });

            REQUIRE(expected_result == result_range);
        }

        SECTION("deques") {
            std::deque<int> first_range{1, 2, 3, 4, 5};
            std::deque<int> second_range{1, 2, 3, 4, 5};
            std::deque<int> result_range{};
            std::deque<int> expected_result{2, 4, 6};

            algo::zip_with_n(first_range.begin(), second_range.begin(),
                             std::back_inserter(result_range), 3,
                             [](const auto &first, const auto &second) {
                                 return first + second;
                             });

            REQUIRE(expected_result == result_range);
        }

        SECTION("lists") {
            std::list<int> first_range{1, 2, 3, 4, 5};
            std::list<int> second_range{1, 2, 3, 4, 5};
            std::list<int> result_range{};
            std::list<int> expected_result{2, 4, 6};

            algo::zip_with_n(first_range.begin(), second_range.begin(),
                             std::back_inserter(result_range), 3,
                             [](const auto &first, const auto &second) {
                                 return first + second;
                             });

            REQUIRE(expected_result == result_range);
        }

        SECTION("forward_lists") {
            std::forward_list<int> first_range{1, 2, 3, 4, 5};
            std::forward_list<int> second_range{1, 2, 3, 4, 5};
            std::forward_list<int> result_range{};
            result_range.resize(3);
            std::forward_list<int> expected_result{2, 4, 6};

            algo::zip_with_n(first_range.begin(), second_range.begin(),
                             result_range.begin(), 3,
                             [](const auto &first, const auto &second) {
                                 return first + second;
                             });

            REQUIRE(expected_result == result_range);
        }

        SECTION("arrays") {
            std::array<int, 5> first_range{{1, 2, 3, 4, 5}};
            std::array<int, 5> second_range{{1, 2, 3, 4, 5}};
            std::array<int, 3> result_range{};
            std::array<int, 3> expected_result{{2, 4, 6}};

            algo::zip_with_n(first_range.begin(), second_range.begin(),
                             result_range.begin(), 3,
                             [](const auto &first, const auto &second) {
                                 return first + second;
                             });

            REQUIRE(expected_result == result_range);
        }
    }

    SECTION("zip_with should zip containers with given operators and different "
            "value_types") {
        SECTION("vectors") {
            std::vector<std::string> first_range{"one", "two", "three", "four",
                                                 "five"};
            std::vector<int> second_range{1, 2, 3, 4, 5};
            std::vector<std::string> result_range{};
            std::vector<std::string> expected_result{"one1", "two2", "three3"};

            algo::zip_with_n(first_range.begin(), second_range.begin(),
                             std::back_inserter(result_range), 3,
                             [](const auto &first, const auto &second) {
                                 return first + std::to_string(second);
                             });

            REQUIRE(expected_result == result_range);
        }

        SECTION("deques") {
            std::deque<std::string> first_range{"one", "two", "three", "four",
                                                "five"};
            std::deque<int> second_range{1, 2, 3, 4, 5};
            std::deque<std::string> result_range{};
            std::deque<std::string> expected_result{"one1", "two2", "three3"};

            algo::zip_with_n(first_range.begin(), second_range.begin(),
                             std::back_inserter(result_range), 3,
                             [](const auto &first, const auto &second) {
                                 return first + std::to_string(second);
                             });

            REQUIRE(expected_result == result_range);
        }

        SECTION("lists") {
            std::list<std::string> first_range{"one", "two", "three", "four",
                                               "five"};
            std::list<int> second_range{1, 2, 3, 4, 5};
            std::list<std::string> result_range{};
            std::list<std::string> expected_result{"one1", "two2", "three3"};

            algo::zip_with_n(first_range.begin(), second_range.begin(),
                             std::back_inserter(result_range), 3,
                             [](const auto &first, const auto &second) {
                                 return first + std::to_string(second);
                             });

            REQUIRE(expected_result == result_range);
        }

        SECTION("forward_lists") {
            std::forward_list<std::string> first_range{"one", "two", "three",
                                                       "four", "five"};
            std::forward_list<int> second_range{1, 2, 3, 4, 5};
            std::forward_list<std::string> result_range{};
            result_range.resize(3);
            std::forward_list<std::string> expected_result{"one1", "two2",
                                                           "three3"};

            algo::zip_with_n(first_range.begin(), second_range.begin(),
                             result_range.begin(), 3,
                             [](const auto &first, const auto &second) {
                                 return first + std::to_string(second);
                             });

            REQUIRE(expected_result == result_range);
        }

        SECTION("arrays") {
            std::array<std::string, 5> first_range{
                {"one", "two", "three", "four", "five"}};
            std::array<int, 5> second_range{{1, 2, 3, 4, 5}};
            std::array<std::string, 3> result_range{};
            std::array<std::string, 3> expected_result{
                {"one1", "two2", "three3"}};

            algo::zip_with_n(first_range.begin(), second_range.begin(),
                             result_range.begin(), 3,
                             [](const auto &first, const auto &second) {
                                 return first + std::to_string(second);
                             });

            REQUIRE(expected_result == result_range);
        }
    }
}

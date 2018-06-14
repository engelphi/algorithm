#include <catch.hpp>

#include <internal/zip_with.hpp>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>

TEST_CASE("zip_with should zip vectors with given operators", "[zip_with]") {
    std::vector<int> first_range{1, 2, 3, 4, 5};
    std::vector<int> second_range{1, 2, 3, 4, 5};
    std::vector<int> result_range{};
    std::vector<int> expected_result{2, 4, 6, 8, 10};

    algo::zip_with(
        first_range.begin(), first_range.end(), second_range.begin(),
        std::back_inserter(result_range),
        [](const auto &first, const auto &second) { return first + second; });

    REQUIRE(expected_result == result_range);
}

TEST_CASE("zip_with should zip vectors with given operators and different "
          "value_types",
          "[zip_with]") {
    std::vector<std::string> first_range{"one", "two", "three", "four", "five"};
    std::vector<int> second_range{1, 2, 3, 4, 5};
    std::vector<std::string> result_range{};
    std::vector<std::string> expected_result{"one1", "two2", "three3", "four4",
                                             "five5"};

    algo::zip_with(first_range.begin(), first_range.end(), second_range.begin(),
                   std::back_inserter(result_range),
                   [](const auto &first, const auto &second) {
                       return first + std::to_string(second);
                   });

    REQUIRE(expected_result == result_range);
}

TEST_CASE("zip_with should zip deques with given operators", "[zip_with]") {
    std::deque<int> first_range{1, 2, 3, 4, 5};
    std::deque<int> second_range{1, 2, 3, 4, 5};
    std::deque<int> result_range{};
    std::deque<int> expected_result{2, 4, 6, 8, 10};

    algo::zip_with(
        first_range.begin(), first_range.end(), second_range.begin(),
        std::back_inserter(result_range),
        [](const auto &first, const auto &second) { return first + second; });

    REQUIRE(expected_result == result_range);
}

TEST_CASE("zip_with should zip deques with given operators and different "
          "value_types",
          "[zip_with]") {
    std::deque<std::string> first_range{"one", "two", "three", "four", "five"};
    std::deque<int> second_range{1, 2, 3, 4, 5};
    std::deque<std::string> result_range{};
    std::deque<std::string> expected_result{"one1", "two2", "three3", "four4",
                                            "five5"};

    algo::zip_with(first_range.begin(), first_range.end(), second_range.begin(),
                   std::back_inserter(result_range),
                   [](const auto &first, const auto &second) {
                       return first + std::to_string(second);
                   });

    REQUIRE(expected_result == result_range);
}

TEST_CASE("zip_with should zip lists with given operators", "[zip_with]") {
    std::list<int> first_range{1, 2, 3, 4, 5};
    std::list<int> second_range{1, 2, 3, 4, 5};
    std::list<int> result_range{};
    std::list<int> expected_result{2, 4, 6, 8, 10};

    algo::zip_with(
        first_range.begin(), first_range.end(), second_range.begin(),
        std::back_inserter(result_range),
        [](const auto &first, const auto &second) { return first + second; });

    REQUIRE(expected_result == result_range);
}

TEST_CASE("zip_with should zip lists with given operators and different "
          "value_types",
          "[zip_with]") {
    std::list<std::string> first_range{"one", "two", "three", "four", "five"};
    std::list<int> second_range{1, 2, 3, 4, 5};
    std::list<std::string> result_range{};
    std::list<std::string> expected_result{"one1", "two2", "three3", "four4",
                                           "five5"};

    algo::zip_with(first_range.begin(), first_range.end(), second_range.begin(),
                   std::back_inserter(result_range),
                   [](const auto &first, const auto &second) {
                       return first + std::to_string(second);
                   });

    REQUIRE(expected_result == result_range);
}

TEST_CASE("zip_with should zip forward_lists with given operators",
          "[zip_with]") {
    std::forward_list<int> first_range{1, 2, 3, 4, 5};
    std::forward_list<int> second_range{1, 2, 3, 4, 5};
    std::forward_list<int> result_range{};
    result_range.resize(5);
    std::forward_list<int> expected_result{2, 4, 6, 8, 10};

    algo::zip_with(
        first_range.begin(), first_range.end(), second_range.begin(),
        result_range.begin(),
        [](const auto &first, const auto &second) { return first + second; });

    REQUIRE(expected_result == result_range);
}

TEST_CASE(
    "zip_with should zip forward_lists with given operators and different "
    "value_types",
    "[zip_with]") {
    std::forward_list<std::string> first_range{"one", "two", "three", "four",
                                               "five"};
    std::forward_list<int> second_range{1, 2, 3, 4, 5};
    std::forward_list<std::string> result_range{};
    result_range.resize(5);
    std::forward_list<std::string> expected_result{"one1", "two2", "three3",
                                                   "four4", "five5"};

    algo::zip_with(first_range.begin(), first_range.end(), second_range.begin(),
                   result_range.begin(),
                   [](const auto &first, const auto &second) {
                       return first + std::to_string(second);
                   });

    REQUIRE(expected_result == result_range);
}

TEST_CASE("zip_with should zip arrays with given operators", "[zip_with]") {
    std::array<int, 5> first_range{{1, 2, 3, 4, 5}};
    std::array<int, 5> second_range{{1, 2, 3, 4, 5}};
    std::array<int, 5> result_range{};
    std::array<int, 5> expected_result{{2, 4, 6, 8, 10}};

    algo::zip_with(
        first_range.begin(), first_range.end(), second_range.begin(),
        result_range.begin(),
        [](const auto &first, const auto &second) { return first + second; });

    REQUIRE(expected_result == result_range);
}

TEST_CASE("zip_with should zip arrays with given operators and different "
          "value_types",
          "[zip_with]") {
    std::array<std::string, 5> first_range{
        {"one", "two", "three", "four", "five"}};
    std::array<int, 5> second_range{{1, 2, 3, 4, 5}};
    std::array<std::string, 5> result_range{};
    std::array<std::string, 5> expected_result{
        {"one1", "two2", "three3", "four4", "five5"}};

    algo::zip_with(first_range.begin(), first_range.end(), second_range.begin(),
                   result_range.begin(),
                   [](const auto &first, const auto &second) {
                       return first + std::to_string(second);
                   });

    REQUIRE(expected_result == result_range);
}

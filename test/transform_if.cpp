#include <algorithms/algorithm.hpp>
#include <catch.hpp>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>

TEST_CASE("transform_if should transform elements of vector inplace if "
          "predicate matches",
          "[transform_if]") {
    std::vector<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    REQUIRE(expected_result == elems);
}

TEST_CASE(
    "transform_if should transform elements of vector if predicate matches",
    "[transform_if]") {
    std::vector<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> result{};
    std::vector<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), std::back_inserter(result),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    REQUIRE(expected_result == result);
}

TEST_CASE("transform_if should transform elements of deque inplace if "
          "predicate matches",
          "[transform_if]") {
    std::deque<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    REQUIRE(expected_result == elems);
}

TEST_CASE(
    "transform_if should transform elements of deque if predicate matches",
    "[transform_if]") {
    std::deque<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> result{};
    std::deque<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), std::back_inserter(result),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    REQUIRE(expected_result == result);
}

TEST_CASE("transform_if should transform elements of list inplace if predicate "
          "matches",
          "[transform_if]") {
    std::list<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    REQUIRE(expected_result == elems);
}

TEST_CASE("transform_if should transform elements of list if predicate matches",
          "[transform_if]") {
    std::list<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> result{};
    std::list<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), std::back_inserter(result),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    REQUIRE(expected_result == result);
}

TEST_CASE("transform_if should transform elements of forward_list inplace if "
          "predicate matches",
          "[transform_if]") {
    std::forward_list<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::forward_list<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    REQUIRE(expected_result == elems);
}


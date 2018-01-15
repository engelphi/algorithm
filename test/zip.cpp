#include <algorithms/algorithm.hpp>
#include <catch.hpp>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>

TEST_CASE("zip should zip elements of two vectors", "[zip]") {
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<char> vec2{'a', 'b', 'c', 'd', 'e'};
    std::vector<std::pair<int, char>> expected_result{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::vector<std::pair<int, char>> result{};

    algo::zip(vec1.begin(), vec1.end(), vec2.begin(),
              std::back_inserter(result));
    REQUIRE(expected_result == result);
}

TEST_CASE("zip should zip elements of two deques", "[zip]") {
    std::deque<int> vec1{1, 2, 3, 4, 5};
    std::deque<char> vec2{'a', 'b', 'c', 'd', 'e'};
    std::deque<std::pair<int, char>> expected_result{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::deque<std::pair<int, char>> result{};

    algo::zip(vec1.begin(), vec1.end(), vec2.begin(),
              std::back_inserter(result));
    REQUIRE(expected_result == result);
}

TEST_CASE("zip should zip elements of two lists", "[zip]") {
    std::list<int> vec1{1, 2, 3, 4, 5};
    std::list<char> vec2{'a', 'b', 'c', 'd', 'e'};
    std::list<std::pair<int, char>> expected_result{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::list<std::pair<int, char>> result{};

    algo::zip(vec1.begin(), vec1.end(), vec2.begin(),
              std::back_inserter(result));
    REQUIRE(expected_result == result);
}

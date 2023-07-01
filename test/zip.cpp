#include <algorithm>
#include <array>
#include <catch2/catch.hpp>
#include <deque>
#include <forward_list>
#include <internal/zip.hpp>
#include <list>
#include <tuple>
#include <vector>

TEST_CASE("zip", "[zip]") {
    SECTION("zip should zip elements of two vectors") {
        std::vector<int> vec1{1, 2, 3, 4, 5};
        std::vector<char> vec2{'a', 'b', 'c', 'd', 'e'};
        std::vector<std::tuple<int, char>> expected_result{
            {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
        std::vector<std::tuple<int, char>> result{};

        algo::zip(vec1.begin(), vec1.end(), vec2.begin(),
                  std::back_inserter(result));
        REQUIRE(expected_result == result);
    }

    SECTION("zip should zip elements of two deques") {
        std::deque<int> vec1{1, 2, 3, 4, 5};
        std::deque<char> vec2{'a', 'b', 'c', 'd', 'e'};
        std::deque<std::tuple<int, char>> expected_result{
            {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
        std::deque<std::tuple<int, char>> result{};

        algo::zip(vec1.begin(), vec1.end(), vec2.begin(),
                  std::back_inserter(result));
        REQUIRE(expected_result == result);
    }

    SECTION("zip should zip elements of two lists") {
        std::list<int> vec1{1, 2, 3, 4, 5};
        std::list<char> vec2{'a', 'b', 'c', 'd', 'e'};
        std::list<std::tuple<int, char>> expected_result{
            {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
        std::list<std::tuple<int, char>> result{};

        algo::zip(vec1.begin(), vec1.end(), vec2.begin(),
                  std::back_inserter(result));
        REQUIRE(expected_result == result);
    }

    SECTION("zip should zip elements of two forward_lists") {
        std::forward_list<int> vec1{1, 2, 3, 4, 5};
        std::forward_list<char> vec2{'a', 'b', 'c', 'd', 'e'};
        std::forward_list<std::tuple<int, char>> expected_result{
            {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
        std::forward_list<std::tuple<int, char>> result{};
        result.resize(5);
        algo::zip(vec1.begin(), vec1.end(), vec2.begin(), result.begin());
        REQUIRE(expected_result == result);
    }

    SECTION("zip should zip elements of two arrays") {
        std::array<int, 5> vec1{{1, 2, 3, 4, 5}};
        std::array<char, 5> vec2{{'a', 'b', 'c', 'd', 'e'}};
        std::array<std::tuple<int, char>, 5> expected_result{
            {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}}};
        std::array<std::tuple<int, char>, 5> result{};

        algo::zip(vec1.begin(), vec1.end(), vec2.begin(), result.begin());
        REQUIRE(expected_result == result);
    }
}

#include <algorithm.hpp>
#include <catch.hpp>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>

TEST_CASE("unzip should unzip elements from a vector to vectors", "[unzip]") {
    std::vector<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::vector<int> expected_first_range{1, 2, 3, 4, 5};
    std::vector<int> first_range{};
    std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::vector<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a vector to lists", "[unzip]") {
    std::vector<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::list<int> expected_first_range{1, 2, 3, 4, 5};
    std::list<int> first_range{};
    std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::list<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a vector to deques", "[unzip]") {
    std::vector<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::deque<int> expected_first_range{1, 2, 3, 4, 5};
    std::deque<int> first_range{};
    std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::deque<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a list to vectors", "[unzip]") {
    std::list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::vector<int> expected_first_range{1, 2, 3, 4, 5};
    std::vector<int> first_range{};
    std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::vector<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a list to lists", "[unzip]") {
    std::list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::list<int> expected_first_range{1, 2, 3, 4, 5};
    std::list<int> first_range{};
    std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::list<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a list to deques", "[unzip]") {
    std::list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::deque<int> expected_first_range{1, 2, 3, 4, 5};
    std::deque<int> first_range{};
    std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::deque<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a forward_list to vectors",
          "[unzip]") {
    std::forward_list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::vector<int> expected_first_range{1, 2, 3, 4, 5};
    std::vector<int> first_range{};
    std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::vector<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a forward_list to lists",
          "[unzip]") {
    std::forward_list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::list<int> expected_first_range{1, 2, 3, 4, 5};
    std::list<int> first_range{};
    std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::list<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a forward list to deques",
          "[unzip]") {
    std::forward_list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::deque<int> expected_first_range{1, 2, 3, 4, 5};
    std::deque<int> first_range{};
    std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::deque<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a deque to vectors", "[unzip]") {
    std::deque<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::vector<int> expected_first_range{1, 2, 3, 4, 5};
    std::vector<int> first_range{};
    std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::vector<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a deque to lists", "[unzip]") {
    std::deque<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::list<int> expected_first_range{1, 2, 3, 4, 5};
    std::list<int> first_range{};
    std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::list<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

TEST_CASE("unzip should unzip elements from a deque to deques", "[unzip]") {
    std::deque<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::deque<int> expected_first_range{1, 2, 3, 4, 5};
    std::deque<int> first_range{};
    std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::deque<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    REQUIRE(expected_first_range == first_range);
    REQUIRE(expected_second_range == second_range);
}

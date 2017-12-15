#include <algorithms/algorithm.hpp>
#include <deque>
#include <forward_list>
#include <gtest/gtest.h>
#include <list>
#include <vector>

TEST(unzip, should_unzip_elements_from_a_vector_to_vectors) {
    std::vector<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::vector<int> expected_first_range{1, 2, 3, 4, 5};
    std::vector<int> first_range{};
    std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::vector<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_vector_to_lists) {
    std::vector<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::list<int> expected_first_range{1, 2, 3, 4, 5};
    std::list<int> first_range{};
    std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::list<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_vector_to_deques) {
    std::vector<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::deque<int> expected_first_range{1, 2, 3, 4, 5};
    std::deque<int> first_range{};
    std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::deque<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_list_to_vectors) {
    std::list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::vector<int> expected_first_range{1, 2, 3, 4, 5};
    std::vector<int> first_range{};
    std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::vector<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_list_to_lists) {
    std::list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::list<int> expected_first_range{1, 2, 3, 4, 5};
    std::list<int> first_range{};
    std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::list<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_list_to_deques) {
    std::list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::deque<int> expected_first_range{1, 2, 3, 4, 5};
    std::deque<int> first_range{};
    std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::deque<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_forward_list_to_vectors) {
    std::forward_list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::vector<int> expected_first_range{1, 2, 3, 4, 5};
    std::vector<int> first_range{};
    std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::vector<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_forward_list_to_lists) {
    std::forward_list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::list<int> expected_first_range{1, 2, 3, 4, 5};
    std::list<int> first_range{};
    std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::list<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_forward_list_to_deques) {
    std::forward_list<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::deque<int> expected_first_range{1, 2, 3, 4, 5};
    std::deque<int> first_range{};
    std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::deque<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_deque_to_vectors) {
    std::deque<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::vector<int> expected_first_range{1, 2, 3, 4, 5};
    std::vector<int> first_range{};
    std::vector<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::vector<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_deque_to_lists) {
    std::deque<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::list<int> expected_first_range{1, 2, 3, 4, 5};
    std::list<int> first_range{};
    std::list<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::list<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

TEST(unzip, should_unzip_elements_from_a_deque_to_deques) {
    std::deque<std::pair<int, char>> input{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::deque<int> expected_first_range{1, 2, 3, 4, 5};
    std::deque<int> first_range{};
    std::deque<char> expected_second_range{'a', 'b', 'c', 'd', 'e'};
    std::deque<char> second_range{};
    algo::unzip(input.begin(), input.end(), std::back_inserter(first_range),
                std::back_inserter(second_range));
    ASSERT_EQ(expected_first_range, first_range);
    ASSERT_EQ(expected_second_range, second_range);
}

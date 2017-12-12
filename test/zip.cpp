#include <algorithm.hpp>
#include <deque>
#include <forward_list>
#include <gtest/gtest.h>
#include <list>
#include <vector>

TEST(zip, should_zip_elements_of_two_vectors) {
  std::vector<int> vec1{1,2,3,4,5};
  std::vector<char> vec2{'a', 'b', 'c', 'd', 'e'};
  std::vector<std::pair<int, char>> expected_result{
      {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  std::vector<std::pair<int, char>> result{};

  algo::zip(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(result));
  ASSERT_EQ(expected_result, result);
}

TEST(zip, should_zip_elements_of_two_deques) {
    std::deque<int> vec1{1, 2, 3, 4, 5};
    std::deque<char> vec2{'a', 'b', 'c', 'd', 'e'};
    std::deque<std::pair<int, char>> expected_result{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::deque<std::pair<int, char>> result{};

    algo::zip(vec1.begin(), vec1.end(), vec2.begin(),
              std::back_inserter(result));
    ASSERT_EQ(expected_result, result);
}

TEST(zip, should_zip_elements_of_two_lists) {
    std::list<int> vec1{1, 2, 3, 4, 5};
    std::list<char> vec2{'a', 'b', 'c', 'd', 'e'};
    std::list<std::pair<int, char>> expected_result{
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
    std::list<std::pair<int, char>> result{};

    algo::zip(vec1.begin(), vec1.end(), vec2.begin(),
              std::back_inserter(result));
    ASSERT_EQ(expected_result, result);
}

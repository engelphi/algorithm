#include <algorithm.hpp>
#include <deque>
#include <forward_list>
#include <gtest/gtest.h>
#include <list>
#include <vector>

TEST(transform_if,
     should_transform_elements_of_vector_inplace_if_predicate_matches) {
  std::vector<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
  algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                     [](int &elem) { return elem + 1; },
                     [](const int &elem) { return (elem % 2) != 0; });

  ASSERT_EQ(expected_result, elems);
}

TEST(transform_if, should_transform_elements_of_vector_if_predicate_matches) {
  std::vector<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> result{};
  std::vector<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
  algo::transform_if(elems.begin(), elems.end(), std::back_inserter(result),
                     [](int &elem) { return elem + 1; },
                     [](const int &elem) { return (elem % 2) != 0; });

  ASSERT_EQ(expected_result, result);
}

TEST(transform_if,
     should_transform_elements_of_deque_inplace_if_predicate_matches) {
    std::deque<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    ASSERT_EQ(expected_result, elems);
}

TEST(transform_if, should_transform_elements_of_deque_if_predicate_matches) {
    std::deque<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> result{};
    std::deque<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), std::back_inserter(result),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    ASSERT_EQ(expected_result, result);
}

TEST(transform_if,
     should_transform_elements_of_list_inplace_if_predicate_matches) {
    std::list<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    ASSERT_EQ(expected_result, elems);
}

TEST(transform_if, should_transform_elements_of_list_if_predicate_matches) {
    std::list<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> result{};
    std::list<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), std::back_inserter(result),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    ASSERT_EQ(expected_result, result);
}

TEST(transform_if,
     should_transform_elements_of_forward_list_inplace_if_predicate_matches) {
    std::forward_list<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::forward_list<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
    algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                       [](int &elem) { return elem + 1; },
                       [](const int &elem) { return (elem % 2) != 0; });

    ASSERT_EQ(expected_result, elems);
}


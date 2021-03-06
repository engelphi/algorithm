#include <internal/transform_if.hpp>

#include <catch.hpp>

#include <deque>
#include <forward_list>
#include <list>
#include <vector>

TEST_CASE("transform_if", "[transform_if]") {
    SECTION(
        "should transform elements of container inplace if predicate matches") {
        SECTION("(vector)") {
            std::vector<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::vector<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
            algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                               [](int &elem) { return elem + 1; },
                               [](const int &elem) { return (elem % 2) != 0; });

            REQUIRE(expected_result == elems);
        }

        SECTION("(deque)") {
            std::deque<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::deque<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
            algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                               [](int &elem) { return elem + 1; },
                               [](const int &elem) { return (elem % 2) != 0; });

            REQUIRE(expected_result == elems);
        }

        SECTION("(list)") {
            std::list<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::list<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
            algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                               [](int &elem) { return elem + 1; },
                               [](const int &elem) { return (elem % 2) != 0; });

            REQUIRE(expected_result == elems);
        }

        SECTION("(forward_list)") {
            std::forward_list<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::forward_list<int> expected_result{2, 2, 4, 4,  6,
                                                   6, 8, 8, 10, 10};
            algo::transform_if(elems.begin(), elems.end(), elems.begin(),
                               [](int &elem) { return elem + 1; },
                               [](const int &elem) { return (elem % 2) != 0; });

            REQUIRE(expected_result == elems);
        }
    }

    SECTION("should transform elements of vector if predicate matches") {
        SECTION("(vector)") {
            std::vector<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::vector<int> result{};
            std::vector<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
            algo::transform_if(elems.begin(), elems.end(),
                               std::back_inserter(result),
                               [](int &elem) { return elem + 1; },
                               [](const int &elem) { return (elem % 2) != 0; });

            REQUIRE(expected_result == result);
        }

        SECTION("(deque)") {
            std::deque<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::deque<int> result{};
            std::deque<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
            algo::transform_if(elems.begin(), elems.end(),
                               std::back_inserter(result),
                               [](int &elem) { return elem + 1; },
                               [](const int &elem) { return (elem % 2) != 0; });

            REQUIRE(expected_result == result);
        }

        SECTION("(list)") {
            std::list<int> elems{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::list<int> result{};
            std::list<int> expected_result{2, 2, 4, 4, 6, 6, 8, 8, 10, 10};
            algo::transform_if(elems.begin(), elems.end(),
                               std::back_inserter(result),
                               [](int &elem) { return elem + 1; },
                               [](const int &elem) { return (elem % 2) != 0; });

            REQUIRE(expected_result == result);
        }
    }
}

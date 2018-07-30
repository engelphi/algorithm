#include <catch.hpp>
#include <deque>
#include <internal/zip_n.hpp>
#include <list>
#include <vector>

TEST_CASE("zip_n", "[zip_n]") {
    SECTION("vector") {
        std::vector<int> vec1{1, 2, 3, 4, 5};
        std::vector<char> vec2{'a', 'b', 'c', 'd', 'e'};
        std::vector<int> vec3{1, 2, 3, 4, 5};
        std::vector<char> vec4{'a', 'b', 'c', 'd', 'e'};
        SECTION("should zip a single vector") {
            std::vector<std::tuple<int>> expected_result{
                {1}, {2}, {3}, {4}, {5}};
            std::vector<std::tuple<int>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end());
            REQUIRE(expected_result == result);
        }

        SECTION("should zip two vectors") {
            std::vector<std::tuple<int, char>> expected_result{
                {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
            std::vector<std::tuple<int, char>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin());
            REQUIRE(expected_result == result);
        }

        SECTION("should zip three vectors") {
            std::vector<std::tuple<int, char, int>> expected_result{
                {1, 'a', 1},
                {2, 'b', 2},
                {3, 'c', 3},
                {4, 'd', 4},
                {5, 'e', 5}};
            std::vector<std::tuple<int, char, int>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin(), vec3.begin());
            REQUIRE(expected_result == result);
        }

        SECTION("should zip four four vectors") {
            std::vector<std::tuple<int, char, int, char>> expected_result{
                {1, 'a', 1, 'a'},
                {2, 'b', 2, 'b'},
                {3, 'c', 3, 'c'},
                {4, 'd', 4, 'd'},
                {5, 'e', 5, 'e'}};
            std::vector<std::tuple<int, char, int, char>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin(), vec3.begin(), vec4.begin());
            REQUIRE(expected_result == result);
        }
    }

    SECTION("deque") {
        std::deque<int> vec1{1, 2, 3, 4, 5};
        std::deque<char> vec2{'a', 'b', 'c', 'd', 'e'};
        std::deque<int> vec3{1, 2, 3, 4, 5};
        std::deque<char> vec4{'a', 'b', 'c', 'd', 'e'};
        SECTION("should zip a single deque") {
            std::deque<std::tuple<int>> expected_result{
                {1}, {2}, {3}, {4}, {5}};
            std::deque<std::tuple<int>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end());
            REQUIRE(expected_result == result);
        }

        SECTION("should zip two deques") {
            std::deque<std::tuple<int, char>> expected_result{
                {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
            std::deque<std::tuple<int, char>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin());
            REQUIRE(expected_result == result);
        }

        SECTION("should zip three deques") {
            std::deque<std::tuple<int, char, int>> expected_result{{1, 'a', 1},
                                                                   {2, 'b', 2},
                                                                   {3, 'c', 3},
                                                                   {4, 'd', 4},
                                                                   {5, 'e', 5}};
            std::deque<std::tuple<int, char, int>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin(), vec3.begin());
            REQUIRE(expected_result == result);
        }

        SECTION("should zip four four deques") {
            std::deque<std::tuple<int, char, int, char>> expected_result{
                {1, 'a', 1, 'a'},
                {2, 'b', 2, 'b'},
                {3, 'c', 3, 'c'},
                {4, 'd', 4, 'd'},
                {5, 'e', 5, 'e'}};
            std::deque<std::tuple<int, char, int, char>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin(), vec3.begin(), vec4.begin());
            REQUIRE(expected_result == result);
        }
    }

    SECTION("list") {
        std::list<int> vec1{1, 2, 3, 4, 5};
        std::list<char> vec2{'a', 'b', 'c', 'd', 'e'};
        std::list<int> vec3{1, 2, 3, 4, 5};
        std::list<char> vec4{'a', 'b', 'c', 'd', 'e'};
        SECTION("should zip a single list") {
            std::list<std::tuple<int>> expected_result{{1}, {2}, {3}, {4}, {5}};
            std::list<std::tuple<int>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end());
            REQUIRE(expected_result == result);
        }

        SECTION("should zip two lists") {
            std::list<std::tuple<int, char>> expected_result{
                {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
            std::list<std::tuple<int, char>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin());
            REQUIRE(expected_result == result);
        }

        SECTION("should zip three lists") {
            std::list<std::tuple<int, char, int>> expected_result{{1, 'a', 1},
                                                                  {2, 'b', 2},
                                                                  {3, 'c', 3},
                                                                  {4, 'd', 4},
                                                                  {5, 'e', 5}};
            std::list<std::tuple<int, char, int>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin(), vec3.begin());
            REQUIRE(expected_result == result);
        }

        SECTION("should zip four four lists") {
            std::list<std::tuple<int, char, int, char>> expected_result{
                {1, 'a', 1, 'a'},
                {2, 'b', 2, 'b'},
                {3, 'c', 3, 'c'},
                {4, 'd', 4, 'd'},
                {5, 'e', 5, 'e'}};
            std::list<std::tuple<int, char, int, char>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin(), vec3.begin(), vec4.begin());
            REQUIRE(expected_result == result);
        }
    }

    SECTION("mixed") {
        std::vector<int> vec1{1, 2, 3, 4, 5};
        std::deque<char> vec2{'a', 'b', 'c', 'd', 'e'};
        std::list<int> vec3{1, 2, 3, 4, 5};

        SECTION("should zip two lists") {
            std::vector<std::tuple<int, char>> expected_result{
                {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
            std::vector<std::tuple<int, char>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin());
            REQUIRE(expected_result == result);
        }

        SECTION("should zip three lists") {
            std::vector<std::tuple<int, char, int>> expected_result{
                {1, 'a', 1},
                {2, 'b', 2},
                {3, 'c', 3},
                {4, 'd', 4},
                {5, 'e', 5}};
            std::vector<std::tuple<int, char, int>> result{};

            algo::zip_n(std::back_inserter(result), vec1.begin(), vec1.end(),
                        vec2.begin(), vec3.begin());
            REQUIRE(expected_result == result);
        }
    }
}

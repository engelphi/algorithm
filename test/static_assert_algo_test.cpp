#include <catch.hpp>

#include "internal/intersperse.hpp"
#include "internal/span.hpp"
#include "internal/transform_if.hpp"
#include "internal/unzip.hpp"

#include <array>

constexpr bool is_uneven(const int x) {
    return (x % 2) != 0;
}

constexpr int increment(const int x) {
    return x + 1;
}

//--------------------------------------------------------------------------------------------------

constexpr inline bool testTransformIfFunction() {
    constexpr int N = 10;
    auto in = std::array<int, N>{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    int out[N] = {0};
    int *out_to = out;

    constexpr auto expected =
        std::array<int, 10>{{2, 2, 4, 4, 6, 6, 8, 8, 10, 10}};

    algo::transform_if(in.begin(), in.end(), out_to, increment, is_uneven);

    bool res = (expected[0] == out[0]) && (expected[1] == out[1]) &&
               (expected[2] == out[2]) && (expected[3] == out[3]) &&
               (expected[4] == out[4]) && (expected[5] == out[5]) &&
               (expected[6] == out[6]) && (expected[7] == out[7]) &&
               (expected[8] == out[8]) && (expected[9] == out[9]);
    return res;
}

//--------------------------------------------------------------------------------------------------

constexpr inline bool testUnzipFunction() {
    constexpr int N = 5;
    auto in = std::array<std::pair<int, int>, N>{
        {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}}};

    constexpr auto expectedA = std::array<int, N>{{1, 3, 5, 7, 9}};
    constexpr auto expectedB = std::array<int, N>{{2, 4, 6, 8, 10}};

    int outA[N] = {0};
    int outB[N] = {0};
    int *outA_to = outA;
    int *outB_to = outB;

    algo::unzip(in.begin(), in.end(), outA_to, outB_to);

    bool res = (expectedA[0] == outA[0]) && (expectedA[1] == outA[1]) &&
               (expectedA[2] == outA[2]) && (expectedA[3] == outA[3]) &&
               (expectedA[4] == outA[4]) && (expectedB[0] == outB[0]) &&
               (expectedB[1] == outB[1]) && (expectedB[2] == outB[2]) &&
               (expectedB[3] == outB[3]) && (expectedB[4] == outB[4]);

    return res;
}

//--------------------------------------------------------------------------------------------------

constexpr inline bool testSpanAlgo() {
    constexpr int N = 5;
    auto in = std::array<int, N * 2>{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    auto expectedA = std::array<int, N>{{1, 3, 5, 7, 9}};
    auto expectedB = std::array<int, N>{{2, 4, 6, 8, 10}};

    int outA[N] = {0};
    int outB[N] = {0};

    int *outA_to = outA;
    int *outB_to = outB;

    algo::span(in.begin(), in.end(), outA_to, outB_to, is_uneven);

    bool res = (expectedA[0] == outA[0]) && (expectedA[1] == outA[1]) &&
               (expectedA[2] == outA[2]) && (expectedA[3] == outA[3]) &&
               (expectedA[4] == outA[4]) && (expectedB[0] == outB[0]) &&
               (expectedB[1] == outB[1]) && (expectedB[2] == outB[2]) &&
               (expectedB[3] == outB[3]) && (expectedB[4] == outB[4]);

    return res;
}

//--------------------------------------------------------------------------------------------------

constexpr inline bool testIntersperseAlgo() {
    std::array<int, 10> input{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    int separator = 0;
    std::array<int, 19> expected{
        {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9, 0, 10}};

    int out[19] = {0};
    int *out_to = out;

    algo::intersperse(input.begin(), input.end(), out_to, separator);

    bool res = true;
    for (unsigned i = 0; i < 19; i++) {
        res = res && (expected[i] == out[i]);
    }
    return res;
}

//--------------------------------------------------------------------------------------------------

TEST_CASE("constexpr", "[constexpr]") {
    SECTION("intersperse works in constexpr context") {
        constexpr bool res = testIntersperseAlgo();
        static_assert(res);
        REQUIRE(res == true);
    }

    SECTION("span works in constexpr context") {
        constexpr bool res = testSpanAlgo();
        static_assert(res);
        REQUIRE(res == true);
    }

    SECTION("unzip works in constexpr context") {
        constexpr bool res = testUnzipFunction();
        static_assert(res);
        REQUIRE(res == true);
    }

    SECTION("transform_if works in constexpr context") {
        constexpr bool res = testTransformIfFunction();
        static_assert(res);
        REQUIRE(res == true);
    }
}

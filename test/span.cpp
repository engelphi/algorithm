#include <catch.hpp>
#include <internal/span.hpp>

#include <vector>
#include <iterator>

TEST_CASE("span of empty range leaves output ranges empty", "[span]") {
  std::vector<int> input{};
  std::vector<int> outputTrue{};
  std::vector<int> outputFalse{};
  std::vector<int> expectedTrue{};
  std::vector<int> expectedFalse{};

  algo::span(input.begin(), input.end(), std::back_inserter(outputTrue),
             std::back_inserter(outputFalse),
             [](const auto &x) { return x < 5; });

  REQUIRE(expectedTrue == outputTrue);
  REQUIRE(expectedFalse == outputFalse);
}

TEST_CASE("span split elements to ranges according to predicate", "[span]") {
    std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> outputTrue{};
    std::vector<int> outputFalse{};
    std::vector<int> expectedTrue{1, 2, 3, 4};
    std::vector<int> expectedFalse{5, 6, 7, 8, 9, 10};

    algo::span(input.begin(), input.end(), std::back_inserter(outputTrue),
               std::back_inserter(outputFalse),
               [](const auto &x) { return x < 5; });

    REQUIRE(expectedTrue == outputTrue);
    REQUIRE(expectedFalse == outputFalse);
}

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <test_cases.hpp>
#include <vector>

int solution(const std::vector<int>&) {
  return 0;
}

TEST_CASE("2009. Minimum Number of Operations to Make Array Continuous") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto nums = test_case["nums"].as<std::vector<int>>();
    const auto expected = test_case["expected"].as<int>();

    CAPTURE(name, nums);
    CHECK(solution(nums) == expected);
  }
}

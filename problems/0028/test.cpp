#include <catch2/catch_test_macros.hpp>
#include <interface.hpp>
#include <string>
#include <test_cases.hpp>

TEST_CASE("28. Find the Index of the First Occurrence in a String") {
  for (const auto& test_case : test_cases) {
    const auto name = test_case["name"].as<std::string>();
    const auto haystack = test_case["haystack"].as<std::string>();
    const auto needle = test_case["needle"].as<std::string>();
    const auto expected = test_case["expected"].as<int>();

    CAPTURE(name);
    CHECK(solution_cpp<int>(haystack, needle) == expected);
  }
}

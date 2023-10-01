#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <string>

std::string solution_c(std::string);
std::string solution_cpp(std::string);

struct TestCase {
  std::string title;
  std::string input;
  std::string expected;
};

TEST_CASE("5. Longest Palindromic Substring") {
  const auto solution = GENERATE(solution_c, solution_cpp);
  auto [title, input, expected] = GENERATE(
      TestCase{.title = "Example 1", .input = "babad", .expected = "bab"},
      TestCase{.title = "Example 2", .input = "cbbd", .expected = "bb"},
      TestCase{.title = "Length of 1", .input = "a", .expected = "a"});

  INFO(title);
  CHECK(solution(input) == expected);
}

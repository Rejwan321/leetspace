#include <internal.hpp>
#include <string>
#include <unordered_set>

using namespace std;

#include "solution.cpp"

template <>
int solution_cpp(const std::string& s) {
  Solution solution;
  return solution.lengthOfLongestSubstring(s);
}

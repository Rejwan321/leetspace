#include <catch2/catch_test_macros.hpp>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* to_list(const std::vector<int>& nums) {
  if (nums.empty()) return nullptr;
  auto head = new ListNode(nums[0]);
  auto node = head;
  for (std::size_t i = 1; i < nums.size(); ++i) {
    node->next = new ListNode(nums[i]);
    node = node->next;
  }
  return head;
}

std::vector<int> from_list(const ListNode* node) {
  std::vector<int> nums{};
  while (node != nullptr) {
    nums.push_back(node->val);
    node = node->next;
  }
  return nums;
}

#include "solution.cpp"

TEST_CASE("19. Remove Nth Node From End of List") {
  SECTION("Example 1") {
    const auto out = Solution{}.removeNthFromEnd(to_list({1, 2, 3, 4, 5}), 2);
    REQUIRE(std::vector<int>{1, 2, 3, 5} == from_list(out));
  }

  SECTION("Example 2") {
    const auto out = Solution{}.removeNthFromEnd(to_list({1}), 1);
    REQUIRE(std::vector<int>{} == from_list(out));
  }

  SECTION("Example 1") {
    const auto out = Solution{}.removeNthFromEnd(to_list({1, 2}), 1);
    REQUIRE(std::vector<int>{1} == from_list(out));
  }
}

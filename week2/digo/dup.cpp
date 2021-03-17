#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> result;
    std::unordered_set<int> nums_set;

    for (int n: nums) {
        if (nums_set.find(n) == nums_set.end()) {
            nums_set.insert(n);
        } else {
            result.push_back(n);
        }
    }
    return result;
}

int main() {

}

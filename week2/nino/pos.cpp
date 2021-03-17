#include <iostream>
#include <vector>
#include <unordered_set>

int firstMissingPositive(std::vector<int>& nums) {
    int i = 1;
    int oldI = i;

    while (i < nums.size() + 1) {
        for(int n: nums) {
            if (n == i) {
                i++;
            }
        }
        if (i == oldI) {
            return i;
        }
        oldI = i;
    }

    return i;
}

int firstMissingPositive2(std::vector<int>& nums) {
    std::unordered_set<int> nums_set;
    for (int n: nums) {
        nums_set.insert(n);
    }
    int size = nums.size();
    for (int i = 1; i <= size; ++i) {
        if (nums_set.find(i) == nums_set.end()) return i;
    }
    return size+1;
}

int main() {
    std::vector<int> test1 = {1};
    std::vector<int> test2 = {1,2,0};
    std::vector<int> test3 = {3,4,-1,1};
    std::vector<int> test4 = {7,8,9,11,12};

    std::cout << "test1: " << firstMissingPositive(test1) << std::endl;
    std::cout << "test2: " << firstMissingPositive(test2) << std::endl;
    std::cout << "test3: " << firstMissingPositive(test3) << std::endl;
    std::cout << "test4: " << firstMissingPositive(test4) << std::endl;
    std::cout << "test1: " << firstMissingPositive2(test1) << std::endl;
    std::cout << "test2: " << firstMissingPositive2(test2) << std::endl;
    std::cout << "test3: " << firstMissingPositive2(test3) << std::endl;
    std::cout << "test4: " << firstMissingPositive2(test4) << std::endl;
}

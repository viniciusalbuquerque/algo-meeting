#include <iostream>
#include <stack>

int countBalancedString(std::string str) {
    int count = 0;
    std::stack<char> my_stack;
    for (char c: str) {
        if (my_stack.empty()) {
            my_stack.push(c);
        } else {
            char top = my_stack.top();
            if (c == top) {
                my_stack.push(c);
            } else {
                my_stack.pop();
            }
        }
        if (my_stack.empty()) count++;
    }

    return count;
}

int main() {
    std::string test1 = "RLRRLLRLRL";
    std::string test2 = "RLLLLRRRLR";
    std::string test3 = "LLLLRRRR";
    std::string test4 = "RLRRRLLRLL";

    std::cout << "test1: " << countBalancedString(test1) << std::endl;
    std::cout << "test2: " << countBalancedString(test2) << std::endl;
    std::cout << "test3: " << countBalancedString(test3) << std::endl;
    std::cout << "test4: " << countBalancedString(test4) << std::endl;
}

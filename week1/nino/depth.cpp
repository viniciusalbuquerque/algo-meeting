#include <iostream>
#include <stack>

int maxDepth(std::string s) {
    int count = 0;
    int maxDepth = 0;
    for (char c: s) {
        if (c == '(') count++;
        else if (c == ')') count--;
        if (count > maxDepth) maxDepth = count;
    }

    return maxDepth;
}

int main() {
    std::string test1 = "(1+(2*3)+((8)/4))+1";
    std::string test2 = "(1)+((2))+(((3)))";
    std::string test3 = "1+(2*3)/(2-1)";
    std::string test4 = "1";

    std::cout << "test1: " << maxDepth(test1) << std::endl;
    std::cout << "test2: " << maxDepth(test2) << std::endl;
    std::cout << "test3: " << maxDepth(test3) << std::endl;
    std::cout << "test4: " << maxDepth(test4) << std::endl;
}

#include <iostream>
#include <stack>

std::string mergeAlternately(std::string word1, std::string word2) {
    std::string merged;
    int length;
    if (word1.length() > word2.length()) {
        length = word1.length();
    } else {
        length = word2.length();
    }
        
    for (int i = 0; i < length; i++) {
        if (i < word1.length()) merged.append(sizeof(char), word1[i]);
        if (i < word2.length()) merged.append(sizeof(char), word2[i]);
    }
    return merged;
}

int main() {
    std::string test1 = "abc";
    std::string test2 = "pqr";
    std::string test3 = "ab";
    std::string test4 = "pqrs";
    std::string test5 = "abcd";
    std::string test6 = "pq";

    std::cout << "test1: " << mergeAlternately(test1, test2) << std::endl;
    std::cout << "test2: " << mergeAlternately(test3, test4) << std::endl;
    std::cout << "test3: " << mergeAlternately(test5, test6) << std::endl;
}

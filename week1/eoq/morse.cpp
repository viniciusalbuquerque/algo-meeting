#include <iostream>
#include <set>
#include <vector>

int uniqueMorseRepresentations(std::vector<std::string>& words) {
    std::string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    std::set<std::string> my_stack;
    for (std::string word: words) {
        std::string str = "";
        for (char c: word) {
            str.append(morse[c - 97]);
        }
        my_stack.insert(str);
    }

    return my_stack.size();
}
int main() {
    std::string test1 = "gin";
    std::string test2 = "zen";
    std::string test3 = "gig";
    std::string test4 = "msg";

    std::vector<std::string> words;
    words.push_back(test1);
    words.push_back(test2);
    words.push_back(test3);
    words.push_back(test4);

    std::cout << "unique: " << uniqueMorseRepresentations(words) << std::endl;

}

#include <iostream>
#include <vector>
#include <map>

class TrieNode {
    public:
    std::map<char, TrieNode*> letters;
    bool isAWord;
};

class Trie {
private:
    TrieNode root;
public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        std::cout << "insert word: " << word << std::endl;
        if (word.length() == 0) return;
        TrieNode *curr = &root;
        for (char c: word) {
            if (curr->letters.find(c) == curr->letters.end()) {
                curr->letters.insert(std::pair<char, TrieNode*>(c, new TrieNode()));
            }
            curr = curr->letters[c];
        }
        curr->isAWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        std::cout << "search word: " << word << std::endl;
        TrieNode *curr = &root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (curr->letters.find(c) == curr->letters.end()) {
                std::cout << "Did not find letter: " << c << std::endl;
                return false;
            }
            curr = curr->letters[c];
        }
        return curr->isAWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        std::cout << "starts with prefix: " << prefix << std::endl;
        TrieNode* curr = &root;
        for (char c: prefix) {
            if (curr->letters.find(c) == curr->letters.end()) {
                std::cout << "Did not find letter: " << c << std::endl;
                return false;
            }
            curr = curr->letters[c];
        }
        return true;
    }

};

int main() {

    std::string apple = "apple";
    std::string app = "app";
    Trie trie;
    trie.insert(apple);
    bool searchApple = trie.search(apple);
    bool searchApp = trie.search(app);
    bool startsWithApp = trie.startsWith(app);
    trie.insert(app);
    bool searchAppAgain = trie.search(app);

    std::cout << "[" << searchApple << "," << searchApp << "," << startsWithApp << "," << searchAppAgain << "]" << std::endl;
}

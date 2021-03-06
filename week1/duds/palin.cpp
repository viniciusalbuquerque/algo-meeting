#include <iostream>
#include <vector>
#include <map>

bool query(std::string s, int start, int end, int numOfChanges) {
    std::cout << "query called for str: " << s << ", start: " << start << ", end: " << end << ", k: " << numOfChanges << std::endl;
    if (start == end) {
        std::cout << "start == end" << std::endl;
        return true;
    }
    int diff_count = 0;
    std::map<char,int> map_count;
    while (start < end) {
        std::cout << "s[start]: " << s[start] << ", s[end]: " << s[end] << std::endl;
        if (s[start] != s[end]) diff_count++;
        map_count[s[start]]++;
        map_count[s[end]]--;
        start++;
        end--;
    }

    if (diff_count > 2*numOfChanges) {
        std::cout << "diff_count > numOfChanges" << std::endl;
        return false;
    }

    int letter_count = 0;
    for (auto it = map_count.begin(); it != map_count.end(); ++it)
        letter_count += abs(it->second);

    std::cout << "letter_count: " << letter_count << std::endl;
    if (letter_count > numOfChanges*2) {
        std::cout << "letter_count > numOfChanges" << std::endl;
        return false;
    }
    return true;
}

std::vector<bool> canMakePaliQueries(std::string s, std::vector<std::vector<int>>& queries) {
    std::vector<bool> result;
    for (std::vector<int> querie: queries) {
        bool res = query(s, querie[0], querie[1], querie[2]);
        result.push_back(res);
    }

    return result;
}

void printResult(std::vector<bool>& results) {
    std::cout << "[";
    for (int i = 0; i < results.size(); i++) {
        bool result = results[i];
        if (result) std::cout << "true";
        else std::cout << "false";
        if (i != results.size() - 1) std::cout << ",";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::string str = "abcda";
    std::vector<std::vector<int>> queries = { {3,3,0}, {1,2,0}, {0,3,1}, {0,3,2}, {0,4,1} };

    std::vector<bool> results = canMakePaliQueries(str, queries);
    printResult(results);

    std::string str2 = "hunu";
    std::vector<std::vector<int>> queries2 = {{1,1,1},{2,3,0},{3,3,1},{0,3,2},{1,3,3},{2,3,1},{3,3,1},{0,3,0},{1,1,1},{2,3,0},{3,3,1},{0,3,1},{1,1,1}};
    //std::vector<std::vector<int>> queries2 = {{0,3,1}};
    std::vector<bool> results2 = canMakePaliQueries(str2, queries2);
    printResult(results2);
    std::cout << "[true,false,true,true,true,true,true,false,true,false,true,true,true]" << std::endl;

}

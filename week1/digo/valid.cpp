#include <iostream>
#include <stack>

bool isValid(std::string s) {
    std::stack<char> my_stack;
    for(char c: s) {
        char top = '\0';
        if (!my_stack.empty()) {
            top = my_stack.top();
        }
        switch (c) {
            case '(':
                my_stack.push(c);
                break;
            case ')':
                if (top == '\0' || top != '(') return false;
                my_stack.pop();
                break;
            case '[':
                my_stack.push(c);
                break;
            case ']':
                if (top == '\0' || top != '[') return false;
                my_stack.pop();
                break;
            case '{':
                my_stack.push(c);
                break;
            default:
                if (top == '\0' || top != '{') return false;
                my_stack.pop();
                break;
        }
    }

    return my_stack.empty();
}

int main() {
    std::string test1 = "()";
    std::string test2 = "()[]{}";
    std::string test3 = "(]";
    std::string test4 = "([)]";
    std::string test5 = "{[]}";
    std::string test6 = "){";

    std::cout << "test1: " << isValid(test1) << std::endl;
    std::cout << "test2: " << isValid(test2) << std::endl;
    std::cout << "test3: " << isValid(test3) << std::endl;
    std::cout << "test4: " << isValid(test4) << std::endl;
    std::cout << "test5: " << isValid(test5) << std::endl;
    std::cout << "test6: " << isValid(test6) << std::endl;
    
}

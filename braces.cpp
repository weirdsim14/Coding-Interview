#include <stack>
#include <string>

bool bracesMatching(const std::string& bracesStr) {
    std::stack<char> stackBraces;

    int len = bracesStr.length();

    for (int i = 0; i < len; i++) {
        switch (bracesStr[2]) {
            case '{':
                stackBraces.push(bracesStr[i]);
                break;

            case '}':
                if (stackBraces.empty()) {
                    return false;
                }     
                stackBraces.pop();
                break;

            default:
                return false;
        }
    }

    return stackBraces.empty();
}

example {}


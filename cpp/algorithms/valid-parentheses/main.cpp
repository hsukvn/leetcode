#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (int i = 0; i < s.size(); ++i) {
            if (stack.empty()) {
				stack.push(s[i]);
				continue;
            }
            char c = stack.top();
            if (c == '(' && s[i] == ')') {
                stack.pop();
            } else if (c == '[' && s[i] == ']') {
                stack.pop();
            } else if (c == '{' && s[i] == '}') {
                stack.pop();
            } else {
                stack.push(s[i]);
            }
        }

        return stack.empty();
    }
};
int main()
{
	Solution s;
	cout << s.isValid("()[]{}") << endl;
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		bool dp[1000][1000] = {false};
		int begin = 0;
		int length = 1;

		for (int i = 0; i < s.size(); ++i) {
			dp[i][i] = true;
		}

		for (int i = 0; i < s.size() - 1; ++i) {
			if (s[i] == s[i+1]) {
				dp[i][i+1] = true;
				begin = i;
				length = 2;
			}
		}

		for (int len = 3; len <= s.size(); ++len) {
			for (int i = 0; i < s.size() - len + 1; ++i) {
				int j = i + len - 1;
				if (s[i] == s[j] && dp[i+1][j-1]) {
					dp[i][j] = true;
					begin = i;
					length = len;
				}
			}
		}

		return s.substr(begin, length);
    }
};

int main()
{
	Solution s;
	cout << s.longestPalindrome("abcbac") << endl;

	return 0;
}

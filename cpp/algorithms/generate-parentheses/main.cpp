#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> ans;
		string s;

		gen(n, 0, 0, s, ans);

		return ans;
    }

    void gen(int n, int left, int right, string &s, vector<string> &ans) {
		if (right == n) {
			ans.push_back(s);
			return;
		}

		if (left < n) {
			s.push_back('(');
			gen(n, left + 1, right, s, ans);
			s.pop_back();
		}

		if (right < n && right < left) {
			s.push_back(')');
			gen(n, left, right + 1, s, ans);
			s.pop_back();
		}
    }
};

int main()
{
	Solution s;
	vector<string> strings = s.generateParenthesis(1);

	for (const auto &s : strings) {
		cout << s << endl;
	}

	return 0;
}

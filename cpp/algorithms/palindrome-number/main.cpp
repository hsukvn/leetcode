#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		vector<char> vec_char;

		if (x < 0) {
			return false;
		}

		while (x > 0) {
			int digit = x % 10;
			vec_char.push_back(digit + '0');
			x /= 10;
		}

		for (int i = 0; i < vec_char.size() / 2; ++i) {
			if (vec_char[i] != vec_char[vec_char.size() - i - 1]) {
				return false;
			}
		}
		return true;
    }
};


int main()
{
	Solution s;

	cout << s.isPalindrome(123);
	cout << s.isPalindrome(123321);
	cout << s.isPalindrome(12321);
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
		int num = 0;
		int num_space = 0;
		bool negative = false;
		bool overflow = false;

		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == ' ') {
				num_space++;
			} else {
				break;
			}
		}
		str = str.substr(num_space);

		if (str[0] == '-') {
			negative = true;
		}

		for (int i = 0; i < str.size(); ++i) {
			if (i == 0 && (str[0] == '-' || str[0] == '+')) {
				continue;
			}
			if (str[i] < '0' || str[i] > '9') {
				break;
			}

			int digit = str[i] - '0';
			int num_tmp = num;
			num *= 10;
			if (num / 10 != num_tmp) {
				overflow = true;
				break;
			}
			num += digit;
			if (num < 0) {
				overflow = true;
				break;
			}
		}

		if (overflow) {
			return negative ? -2047483648 : 2047483647;
		}

		return negative ? -1 * num : num;
    }
};

int main()
{
	Solution s;
	cout << s.myAtoi("   1234567890") << endl;
	cout << s.myAtoi("-1234567890") << endl;
	cout << s.myAtoi("4193 ") << endl;
	cout << s.myAtoi("4193 with words") << endl;
	cout << s.myAtoi("+1") << endl;
	cout << s.myAtoi("2147483648") << endl;
	return 0;
}

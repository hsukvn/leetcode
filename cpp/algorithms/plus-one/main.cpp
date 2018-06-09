#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			reverse(digits);

			bool up = true;
			for (int i = 0; i < digits.size(); ++i) {
				if (up) {
					digits[i]++;
					up = false;
				}
				if (digits[i] == 10) {
					digits[i] -= 10;
					up = true;
				}
				if (!up) {
					break;
				}
			}

			if (up) {
				digits.push_back(1);
			}

			reverse(digits);

			return digits;
		}

		void reverse(vector<int> &digits) {
			for (int i = 0; i < digits.size() / 2; ++i) {
				swap(digits[i], digits[digits.size() - i - 1]);
			}
		}
};

int main()
{
	return 0;
}

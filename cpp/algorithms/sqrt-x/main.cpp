#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		int mySqrt(int x) {
			int left = 0;
			int right = x;

			if (x == 0 || x == 1) {
				return x;
			}

			while (left < right) {
				int mid = (left + right) / 2;
				double midsqr = (double)mid * (double)mid;
				cout << mid << endl;
				if (midsqr == x) {
					return mid;
				} else if (midsqr > x) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}

			if (left * left > x) {
				left--;
			}

			return left;
		}
};
int main()
{
	Solution s;
	cout << s.mySqrt(2147395599) << endl;
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
		int x_tmp = x;
		int num = 0;
		bool negative = false;

		if (x < 0) {
			negative = true;
			x_tmp*=-1;
		}

		while (x_tmp > 0) {
			int num_tmp = num;
			num*=10;
			if (num/10 != num_tmp) {
				// overflow
				return 0;
			}
			num+=x_tmp%10;
			x_tmp/=10;
		}

		return negative ? -1*num : num;
    }
};

int main()
{
	Solution s;
	cout << s.reverse(1534236469) << endl;

	return 0;
}

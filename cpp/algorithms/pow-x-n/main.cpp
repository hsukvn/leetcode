#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		double myPow(double x, int n) {
			bool underflow = false;
			double base = x;

			if (n == 0) {
				return 1.0;
			}

			if (n == -2147483648) {
				underflow = true;
				n++;
			}

			if (n < 0) {
				x = (double)1.0 / x;
				n = (-1) * n;
			}

			double ans = (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);

			if (underflow) {
				ans *= base;
			}

			return ans;
		}
};

int main()
{
	return 0;
}

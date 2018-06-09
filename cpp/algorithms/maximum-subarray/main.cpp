#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int v = nums[0], last = nums[0];

			for (int i = 1; i < nums.size(); ++i) {
				last = max(last + nums[i], nums[i]);
				if (last > v) {
					v = last;
				}
			}

			return v;
		}
};

int main()
{
	Solution s;
	vector<int> input = {-1};
	cout << s.maxSubArray(input) << endl;

	return 0;
}

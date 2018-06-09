#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int v = nums[0];

			vector<int> dp;
			dp.push_back(nums[0]);

			for (int i = 1; i < nums.size(); ++i) {
				dp.push_back(max(dp[i-1] + nums[i], nums[i]));
				if (dp[i] > v) {
					v = dp[i];
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

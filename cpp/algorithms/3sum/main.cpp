#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			std::sort(nums.begin(), nums.end());
			vector<vector<int>> ans;

			if (nums.size() < 3) {
				return ans;
			}

			for (int i = 0; i < nums.size() - 2; ++i) {
				if (i > 0 && nums[i] == nums[i-1]) {
					continue;
				}

				twoSum(nums, i, ans);
			}

			return ans;
		};
		void twoSum(vector<int>& nums, int skip_index, vector<vector<int>> &ans) {
			int left = skip_index + 1;
			int right = nums.size() -1;
			int target = 0 - nums[skip_index];

			while (left < right) {
				if (left > (skip_index + 1) && nums[left] == nums[left-1]) {
					left++;
					continue;
				}

				if (nums[left] + nums[right] == target) {
					vector<int> tmp;
					tmp.push_back(nums[skip_index]);
					tmp.push_back(nums[left]);
					tmp.push_back(nums[right]);
					ans.push_back(tmp);
					left++;
					right--;
				} else if (nums[left] + nums[right] > target) {
					right--;
				} else {
					left++;
				}
			}
		};
};

int main()
{
	return 0;
}

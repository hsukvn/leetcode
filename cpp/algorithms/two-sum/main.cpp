#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> nums_bk(nums);

			std::sort(nums.begin(), nums.end());

			vector<int> sol;
			int left = 0;
			int right = nums.size() - 1;

			while (left < right) {
				if (nums[left] + nums[right] == target) {
					for (int i = 0; i < nums_bk.size(); ++i) {
						if (nums_bk[i] == nums[left]) {
							sol.push_back(i);
							break;
						}
					}
					for (int j = nums_bk.size() - 1; j >= 0; --j) {
						if (nums_bk[j] == nums[right]) {
							sol.push_back(j);
							break;
						}
					}
					break;
				} else if (nums[left] + nums[right] > target) {
					right--;
				} else {
					left++;
				}
			}

			return sol; 
		}
};

int main()
{
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			map<int, int> hash;

			for (int i = 0; i < nums.size(); ++i) {
				if (hash.end() == hash.find(target - nums[i])) {
					hash[nums[i]] = i;
				} else {
					return {hash[target-nums[i]], i};
				}
			}
		}
};

int main()
{
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			vector<int> ans;

			if (0 == nums.size()) {
				return {-1, -1};
			}

			{ // find left
				int left = 0, right = nums.size() - 1;

				while (left < right) {
					int mid = (left + right) / 2;

					if (nums[mid] < target) {
						left = mid + 1;
					} else {
						right = mid;
					}
				}

				if (nums[left] != target) {
					return {-1, -1};
				} else {
					ans.push_back(left);
				}
			}

			{ // find right
				int left = ans[0]; // left
				int right = nums.size() - 1;

				while (left < right) {
					int mid = (left + right) / 2 + 1; // ceiling

					if (nums[mid] > target) {
						right = mid - 1;
					} else {
						left = mid;
					}
				}

				ans.push_back(right);
			}

			return ans;
		}
};

int main()
{
	Solution a;
	vector<int> input = {};
	vector<int> v = a.searchRange(input, 0);

	for (const auto &i : v) {
		cout << i <<  " ";
	}
	cout << endl;
	return 0;
}

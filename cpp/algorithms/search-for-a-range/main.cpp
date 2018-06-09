#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			int idx = binarySearch(nums, 0, nums.size() - 1, target);
			if (idx == -1) {
				return {-1, -1};
			}

			int left = idx;
			int right = idx;

			while (left > 0) {
				if (nums[left - 1] == target) {
					left--;
				} else {
					break;
				}
			}

			while (right < nums.size() - 1) {
				if (nums[right + 1] == target) {
					right++;
				} else {
					break;
				}
			}

			return {left, right};
		}

		int binarySearch(vector<int> &nums, int idx_left, int idx_right, int target) {
			if (idx_left > idx_right) {
				return -1;
			}

			int idx_mid = (idx_left + idx_right) / 2;

			if (nums[idx_mid] == target) {
				return idx_mid;
			} else if (nums[idx_mid] > target) {
				return binarySearch(nums, idx_left, idx_mid - 1, target);
			} else if (nums[idx_mid] < target) {
				return binarySearch(nums, idx_mid + 1, idx_right, target);
			}
		}
};

int main()
{
	Solution a;
	vector<int> input = {2, 2};
	vector<int> v = a.searchRange(input, 2);

	for (const auto &i : v) {
		cout << i <<  " ";
	}
	cout << endl;
	return 0;
}

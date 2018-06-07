#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		p(nums, 0, ans);
		return ans;
    }

    void p(vector<int>& nums, int begin, vector<vector<int>>& ans) {
		if (begin == (nums.size() - 1)) {
			ans.push_back(nums);
		}

		for (int i = begin; i < nums.size(); ++i) {
			swap(nums[begin], nums[i]);
			p(nums, begin + 1, ans);
			swap(nums[begin], nums[i]);
		}
    }
    
};

int main()
{
	Solution s;
	vector<int> data = {1, 2, 3};
	vector<vector<int>> ans = s.permute(data);

	for (const auto a : ans) {
		for (const auto n : a) {
			cout << n << " ";
		}
		cout << endl;
	}

	return 0;
}

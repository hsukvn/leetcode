#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                swap(nums, i, size++);
            }
        }

        nums.erase(nums.begin() + size, nums.end());

        return size;
    }

    void swap(vector<int>& nums, int idx_1, int idx_2) {
        int tmp = 0;
        tmp = nums[idx_2];
        nums[idx_2] = nums[idx_1];
        nums[idx_1] = nums[idx_2];
    }
};

int main()
{
	return 0;
}

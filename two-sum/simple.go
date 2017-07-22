package main

import "fmt"

func twoSum(nums []int, target int) []int {
	for i := 0; i < len(nums) - 1; i++ {
		for j := 1; j < len(nums); j++ {
			if i == j {
				continue
			}
			if nums[i] + nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return []int{};
}

func main() {
	array := []int{2, 5, 5, 11}

	fmt.Printf("%#v", twoSum(array, 10))

}

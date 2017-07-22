
package main

import "fmt"

func twoSum(nums []int, target int) []int {
	hash := make(map[int]int, len(nums))
	for i := range nums {
		if val, ok := hash[target - nums[i]]; ok {
			return []int{val, i}
		}
		hash[nums[i]] = i
	}
	return nil
}

func main() {
	array := []int{2, 5, 5, 11}
	fmt.Printf("%#v", twoSum(array, 10))
}

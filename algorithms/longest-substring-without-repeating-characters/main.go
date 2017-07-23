package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	length := 0
	j := -1
	hash := make(map[byte]int)

	for i := 0; i < len(s); i++ {
		if val, ok := hash[s[i]]; ok {
			if val > j {
				j = val
			}
		}
		hash[s[i]] = i
		if i - j > length { // i - (j + 1) + 1
			length = i - j
		}
	}

	return length
}

func main() {
	fmt.Printf("%#v", lengthOfLongestSubstring("jlincraig"))
}

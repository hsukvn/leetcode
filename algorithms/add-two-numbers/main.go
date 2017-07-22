package main

import "fmt"

// Definition for singly-linked list.
type ListNode struct {
	Val int
	Next *ListNode
}
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	up := false
	list := &ListNode{
		Val: 0,
		Next: nil,
	}
	l := list

	for p1, p2 := l1, l2; p1 != nil || p2 != nil; {
		if p1 != nil {
			l.Val += p1.Val
			p1 = p1.Next
		}
		if p2 != nil {
			l.Val += p2.Val
			p2 = p2.Next
		}
		if up {

			l.Val += 1
			up = false
		}
		if l.Val >= 10 {
			l.Val -= 10
			up = true
		}
		if p1 != nil || p2 != nil {
			l.Next = new(ListNode)
			l = l.Next
		}
	}

	return list
}
func main() {
	var l1 = &ListNode{
		Val: 1,
		Next: nil,
	}
	l1.Next = new(ListNode)
	l1.Next.Val = 8

	var l2 = &ListNode{
		Val: 0,
		Next: nil,
	}
	
	l := addTwoNumbers(l1, l2)

	for list := l; list != nil; list = list.Next {
		fmt.Printf("%d ", list.Val)
	}
}

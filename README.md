# radix-c

The radix-c repository contains two C projects implementing different Radix logics.

# Radix Tree

This C code is an implementation of a radix tree for strings.

It uses linked lists to build the tree from Node structs.
A Node struct has two values within it: being a linked list, it contains a pointer to its children; it also contains a bool value, that determines if it is a leaf(end of a branch in the tree) or not. Every Node is also associated with a string key.

The user can fill up a tree with values, then search within it.
Searching the tree will return with true or false (found or not found).

# Radix Sort (for numbers)

This C code is an implementation of a sorting algorithm for numbers.
It works like this:
1. The algorithm takes the last digit of every number. (if a number has no more digits it will return 0 as it's last digit)
2. The algorithm counts how many of each digit there is, and stores it.
3. The algorithm starts to add up the number of digits.
	
For example:

	+---+---+---+---+---+---+---+---+---+---+	+---+---+---+----+----+----+----+----+----+----+
	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |	| 0 | 1 | 2 | 3  | 4  | 5  | 6  | 7  | 8  | 9  |
	+---+---+---+---+---+---+---+---+---+---+ ====> +---+---+---+----+----+----+----+----+----+----+
	| 2 | 4 | 1 | 5 | 0 | 1 | 2 | 1 | 3 | 2 |	| 2 | 6 | 7 | 13 | 13 | 14 | 16 | 17 | 20 | 22 |
	+---+---+---+---+---+---+---+---+---+---+	+---+---+---+----+----+----+----+----+----+----+

4. The algorithm now iterates through the array of numbers backwards, and places them in the place that matches the value, that's been calculated in the previous step. Then we substract one from this value.
5. After it iterated through the list backwards, it moves on to the next "last" digit, and it repeats the steps, until there is no number that has any digits left.
(Visualisation: https://www.cs.usfca.edu/~galles/visualization/RadixSort.html)

# MedianFinder

This algorithm uses two heaps, namely min and max, to store the lower and higher half of the data stream.
Min heap contains current median and all elements greater than the current median and max heap contains elements smaller than the current median.
When a number is received it is first compared with the current median and put it into the appropriate heap by the following principle:

·If the received value is greater than the current median it is inserted into the min heap.
·Else it is inserted into the max heap.

The heap sizes differ at most by 1. If sizes are different, heaps are rebalanced by taking the top element from the large heap and inserting into the other one.

# Complexity

The worst case scenario for insertion is when a value at the bottom of the heap has to be swapped on every level of the heap
up to the  root node. In that case logn number of swaps will be done as heap is a binary tree structure.
As a result insertion operation takes logN complexity at worst case. 
In our case we are using 2 different heaps each for half  of the data stream. These are all constant values we can ignore them when calculating complexity.
Since inserting one element complexity is O(logn), overall complexity for data stream of "n" integers will be O(n logn).

When we calculate median:

·If two heaps are at the same size the median (top_value_of_minHeap + top_value_of_maxHeap)/2

·Else the heaps are unbalanced then the median is top value of the min heap.

Both operations yield to O(1) complexity for finding median.

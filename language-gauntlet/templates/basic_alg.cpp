#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * TITLE:
 * Linear Search
 * Linear Search has a complexity of O(n)
 * 
 * INSTRUCTIONS:
 * 1. Move through the list one by one checking for target
 * 2. Repeat until target is found or the end is reached
 * 
 * For this funciton, we want to return the index where the target is found.
 *    If the target is not in the list: return -1
 * 
 * PARAMS:
 *    list:   the array to be searched
 *    size:   the size of the list
 *    target: the target value we are searching for
 * 
 * LINKS:
 *    https://en.wikipedia.org/wiki/Linear_search
 *    https://www.geeksforgeeks.org/linear-search/
 */
int linear_search(vector<int> list, int target);

/**
 * TITLE:
 * Binary Search
 * Binary Search has a complexity of O(logn)
 * 
 * It is used in a sorted array by repeatedly dividing the search interval in half
 * 
 * INSTRUCTIONS:
 * 1. Divide the search space into two halves by finding the middle index “mid”. 
 * 2. Compare the middle element of the search space with the "target".
 * 3. If the target is found at middle element, the process is terminated.
 * 4. If the target is not found at middle element, choose which half will be used as the next search space.
 *      - If the target is smaller than the middle element, then the left side is used for next search.
 *      - If the target is larger than the middle element, then the right side is used for next search.
 * 5. This process is continued until the target is found or the total search space is exhausted.
 * 
 * 
 * For this funciton, we want to return the index where the target is found.
 *    If the target is not in the list: return -1
 * 
 * PARAMS:
 *    list:   the array to be searched
 *    size:   the size of the list
 *    target: the target value we are searching for
 * 
 * LINKS:
 *    https://en.wikipedia.org/wiki/Binary_search#:~:text=In%20computer%20science%2C%20binary%20search,middle%20element%20of%20the%20array.
 *    https://www.geeksforgeeks.org/binary-search/
 */
int binary_search(vector<int> list, int target);

/**
 * TITLE:
 * Selection sort
 * Selection sort has a worst-case and average complexity of O(n^2)
 *  -> where n is the number of items being sorted
 * 
 * INSTRUCTIONS:
 * 1. We find the smallest element and swap it with the first element.
 *      -> This way we get the smallest element at its correct position.
 * 2. Then we find the smallest among remaining elements (or second smallest) and swap it with the second element.
 * 3. Repeat until we get all elements moved to correct position.
 * 
 * For this funciton, we want to manipulate the original list and return nothing
 
 * PARAMS:
 *  list: the array to be sorted
 *  size: the size of the list
 * 
 * LINKS:
 *    https://en.wikipedia.org/wiki/Selection_sort
 *    https://www.geeksforgeeks.org/selection-sort-algorithm-2/
 */
void selection_sort(vector<int>& list);

/**
 * TITLE:
 * Bubble sort (AKA sinking sort)
 * Bubble sort has a worst-case and average complexity of O(n^2)
 *  -> where n is the number of items being sorted
 * 
 * INSTRUCTIONS:
 * 
 * 1. We sort the array using multiple passes.
 *      -> After the first pass, the maximum element goes to end (its correct position).
 *      -> After second pass, the second largest element goes to second last position and so on.
 * 2. In every pass, we process only those elements that have already not moved to correct position.
 *      -> After k passes, the largest k elements must have been moved to the last k positions.
 * 3. In a pass, we consider remaining elements and compare all adjacent and swap if larger element is before a smaller element. 
 *      -> If we keep doing this, we get the largest (among the remaining elements) at its correct position.
 * 
 * For this funciton, we want to manipulate the original list and return nothing
 * 
 * PARAMS:
 *    list:   the array to be sorted
 * 
 * LINKS:
 *    https://en.wikipedia.org/wiki/Bubble_sort
 *    https://www.geeksforgeeks.org/bubble-sort-algorithm/
 */
void bubble_sort(vector<int>& list);

int main() {
  vector<int> list{1, 123, 4, 5, 234, 5647, 87, 124, 0, 543, 564, 1232};
  vector<int> list2{1, 123, 4, 5, 234, 5647, 87, 124, 0, 543, 564, 1232};
  vector<int> list3{0,1,2,3,4,5,6};
  vector<int> list4{0,54,3,40,5,65};
  bubble_sort(list);
  bubble_sort(list3);
  selection_sort(list2);
  selection_sort(list4);
  assert(list == vector<int>({0,1,4,5,87,123,124,234,543,564,1232,5647}));
  assert(list2 == vector<int>({0,1,4,5,87,123,124,234,543,564,1232,5647}));
  assert(list3 == vector<int>({0,1,2,3,4,5,6}));
  assert(list4 == vector<int>({0,3,5,40,54,65}));
  assert(binary_search(list, 543) == 8);
  assert(binary_search(list, 4) == 2);
  assert(binary_search(list, 124) != 8);
  assert(binary_search(list, 564) != 10);
  assert(binary_search(list, 800) != 0);
  assert(binary_search(list, 6000) != 5);
  assert(binary_search(list, 124) == 6);
  assert(binary_search(list, 564) == 9);
  assert(binary_search(list, 800) == -1);
  assert(binary_search(list, 6000) == -1);
  assert(linear_search(list, 87) == 4);
  assert(linear_search(list, 0) == 0);
  assert(linear_search(list, 234) == 7);
  assert(linear_search(list, 235) == -1);
  return 0;
}

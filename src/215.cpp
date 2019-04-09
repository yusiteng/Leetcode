#include <iostream>
#include <vector>

class Solution {
public:
	inline int left(int i) {
		return 2 * i + 1;
	}
	inline int right(int i) {
		return 2 * i + 2;
	}
	inline int parent(int i) {
		return (i + 1) / 2 - 1;
	}

	void max_heapify(std::vector<int>& nums, int i, int heap_size) {
		int l = left(i), r = right(i), largest;
		if (l < heap_size && nums[l] > nums[i]) largest = l;
		else largest = i;
		if (r < heap_size && nums[r] > nums[largest]) largest = r;
		if (largest != i) {
			int temp = nums[i];
			nums[i] = nums[largest];
			nums[largest] = temp;
			max_heapify(nums, largest, heap_size);
		}
	}

	void build_max_heap(std::vector<int>& nums, int heap_size) {
		int last_intern_node = parent(nums.size()-1);
		for (int i = last_intern_node; i >= 0; --i) {
			max_heapify(nums, i, heap_size);
		}
	}
	int findKthLargest(std::vector<int>& nums, int k) {
		int heap_size = nums.size();
		build_max_heap(nums,heap_size);
		for (int i = nums.size()-1; i > nums.size() - k; i--)
		{
			int temp = nums[0];
			nums[0] = nums[i];
			nums[i] = temp;
			heap_size -= 1;
			max_heapify(nums, 0, heap_size);
			 
		}
		return nums[0];
	}
};
int main()
{
	Solution S;
	std::vector<int> arr = { 1,3,7,5,9,9,1,2,7,4,1 };
	std::cout << S.findKthLargest(arr, 3) << std::endl;
	return 0;
}
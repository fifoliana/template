#include <bits/stdc++.h>

using namespace std;

vector<int> v = {10, 10, 10, 20, 20, 20, 30, 30};

// lower_bound : find the first position in which val could be inserted without changing the ordering
vector<int>::iterator low = lower_bound(v.begin(), v.end(), 20);

// upper_bound : find the first position in which val could be inserted without changing the ordering
vector<int>::iterator up = upper_bound(v.begin(), v.end(), 20);

// binary search

int binary_search(vector<int>& nums, int target) {
	int l = 0;
	int r = nums.size() - 1;;
	int mid;

	while (l <= r)
	{
		// prevent overflow
		mid = l + (r - l)/ 2;
		if (nums[mid] == target)
			return (mid);
		if (nums[mid] > target)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return (-1);
}

// upper bound, upper_bound

int search(vector<int>& nums, int target) {
	int left = 0, right = int(nums.size());
	
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] <= target) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	
	if (left > 0 && nums[left - 1] == target) {
		return left - 1;
	} else {
		return -1;
	}
}

// lower bound, lower_bound

int search(vector<int>& nums, int target) {
	// Set the left and right boundaries
	int left = 0, right = int(nums.size());
	
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] >= target) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	
	if (left < nums.size() and nums[left] == target) {
		return left;
	} else {
		return -1;
	}
}


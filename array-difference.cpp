/*
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2.
Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2.
Therefore, answer[1] = [4,6].

Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> ans;
    vector<int>::iterator it;

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    auto nums1_end = unique(nums1.begin(), nums1.end());
    auto nums2_end = unique(nums2.begin(), nums2.end());

    ans.push_back(vector<int>(nums1.size()));
    it = set_difference(nums1.begin(), nums1_end, nums2.begin(), nums2_end, ans[0].begin());
    ans[0].resize(it - ans[0].begin());

    ans.push_back(vector<int>(nums2.size()));
    it = set_difference(nums2.begin(), nums2_end, nums1.begin(), nums1_end, ans[1].begin());
    ans[1].resize(it - ans[1].begin());

    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {1, 1, 2, 2};

    vector<vector<int>> nums3 = findDifference(nums1, nums2);

    for (int i = 0; i < nums3.size(); i++)
    {
        cout << nums3[i] << " ";
    }
}
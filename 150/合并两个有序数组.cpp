//
// Created by site on 2024/1/4.
//
/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
 */
#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    nums1.resize(m);
    nums2.resize(n);
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    std::inplace_merge(nums1.begin(), nums1.begin() + m, nums1.end());
    nums1.resize(m + n);
}

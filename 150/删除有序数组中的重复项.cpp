//
// Created by site on 2024/1/4.
//
/*
 *
 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k
 */

#include <vector>
#include <algorithm>
using namespace std;
// int removeDuplicates(vector<int>& nums) {
//     if(nums.size() <= 0){
//         return 0;
//     }
//     int nIndex = nums.front();
//     for(auto itr = nums.begin() + 1; itr != nums.end(); ){
//         int nCurrent = *itr;
//         if(nIndex == nCurrent){
//             itr = nums.erase(itr);
//         }else{
//             nIndex = nCurrent;
//             itr++;
//         }
//     }

//     return nums.size();
// }
int removeDuplicates(vector<int>& nums) {
    auto last = std::unique(nums.begin(), nums.end());
    nums.erase(last, nums.end());
    return nums.size();
}

/*
 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

 */
int removeDuplicates2(vector<int>& nums) {
    if(nums.size() <= 0){
        return 0;
    }
    int nIndex = nums.front();
    int nCount = 0;
    for(auto itr = nums.begin() + 1; itr != nums.end(); ){
        int nCurrent = *itr;
        if(nIndex == nCurrent){
            nCount++;
            if(nCount >= 2){
                itr = nums.erase(itr);
            }else{
                itr++;
            }
        }else{
            nCount = 0;
            nIndex = nCurrent;
            itr++;
        }
    }
    return nums.size();
}
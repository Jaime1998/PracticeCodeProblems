//
//  main.cpp
//  MergeSortedArray
//
//  Created by Jaime Cuartas Granada on 5/5/2024.
//

#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    while(n>0){
        if(m==0) {
            nums1[n] = nums2[--n];
            continue;
        }
        if(nums1[m-1]>=nums2[n-1]){
            nums1[m+n] = nums1[--m];
            continue;
        }
        nums1[m+n] = nums2[--n];
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> nums1{1,2,3,0,0,0};
    std::vector<int> nums2{2,5,6};
    std::vector<int> nums11{0};
    std::vector<int> nums22{1};
    merge(nums1, 3, nums2, 3);
    return 0;
}

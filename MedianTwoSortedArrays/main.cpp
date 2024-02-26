//
//  main.cpp
//  MedianTwoSortedArrays
//
//  Created by Jaime Cuartas Granada on 25/2/2024.
//

#include <iostream>
#include <vector>
#include <limits>

double max(double a, double b){
    return (a>b)? a: b;
}

double min(double a, double b){
    return (a<b)? a: b;
}

double findMedianSortedArraysSmaller2Larger(std::vector<int>& nums1, std::vector<int>& nums2, int nums1N, int nums2N){
    const int n = nums1N + nums2N;
    int lower = 0;
    int upper = nums1N;
    bool emptyLeftNums1 = false;
    bool emptyLeftNums2 = false;
    bool emptyRightNums1 = false;
    bool emptyRightNums2 = false;
    double leftMedianNums1 = -std::numeric_limits<double>::infinity();
    double leftMedianNums2 = -std::numeric_limits<double>::infinity();
    double rightMedianNums1 = std::numeric_limits<double>::infinity();
    double rightMedianNums2 = std::numeric_limits<double>::infinity();
    
    while(lower<=upper){
        int median1 = (lower + upper)/2;
        int median2 = (n+1)/2  - median1;
        emptyLeftNums1 = (median1<=0);
        emptyLeftNums2 = (median2<=0);
        emptyRightNums1 = (median1>=nums1N);
        emptyRightNums2 = (median2>=nums2N);
        leftMedianNums1 = (!emptyLeftNums1) ? nums1[median1-1]: -std::numeric_limits<double>::infinity();
        leftMedianNums2 = (!emptyLeftNums2) ? nums2[median2-1]: -std::numeric_limits<double>::infinity();
        rightMedianNums1 = (!emptyRightNums1) ? nums1[median1]: std::numeric_limits<double>::infinity();
        rightMedianNums2 = (!emptyRightNums2) ? nums2[median2]: std::numeric_limits<double>::infinity();
        
        if((emptyLeftNums1 || emptyRightNums2 || (leftMedianNums1<=rightMedianNums2)) && (emptyLeftNums2 || emptyRightNums1 || (leftMedianNums2<=rightMedianNums1)) ){
            if(n%2 == 0) return (max(leftMedianNums1, leftMedianNums2) + min(rightMedianNums1, rightMedianNums2)) / 2;
            else return max(leftMedianNums1, leftMedianNums2);
        }else if(leftMedianNums1 > leftMedianNums2){
            upper = median1 - 1;
        } else {
            lower = median1 + 1;
        }
    }
    return 0;
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    int nums1N = (int)nums1.size();
    int nums2N = (int)nums2.size();
    if(nums1N <= nums2N){
        return findMedianSortedArraysSmaller2Larger(nums1, nums2, nums1N, nums2N);
    }
    return findMedianSortedArraysSmaller2Larger(nums2, nums1, nums2N, nums1N);
}


int main(int argc, const char * argv[]) {
    std::vector<int> nums1{3};
    std::vector<int> nums2{-2,-1};
    std::cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}

//
//  main.cpp
//  InsertionTwoArrays
//
//  Created by Jaime Cuartas Granada on 10/3/2024.
//

#include <iostream>
#include <vector>
#include <set>
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    int nNums1 = static_cast<int>(nums1.size());
    int nNums2 = static_cast<int>(nums2.size());
    if (nNums2<nNums1) return intersection(nums2, nums1);
    int setNums[1001] = {};
    for(int i=0; i<nNums1; i++) setNums[nums1[i]]++;
    std::vector<int> output;
    for(int i=0; i<nNums2; i++){
        if(setNums[nums2[i]] == 0) continue;
        output.push_back(nums2[i]);
        setNums[nums2[i]]=0;
    }
    return output;
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> in1 = {1,2,2,1};
    
    std::vector<int> in2 = {2,2};
    intersection(in1, in2);
    return 0;
}

//
//  main.cpp
//  MinimumCommonValue
//
//  Created by Jaime Cuartas Granada on 9/3/2024.
//

#include <iostream>
#include <vector>

int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
    int n1 = static_cast<int>(nums1.size());
    int n2 = static_cast<int>(nums2.size());
    int i = 0, j = 0;
    while(i<n1 && j<n2){
        if(nums1[i] == nums2[j]) return nums1[i];
        if(nums1[i] > nums2[j]) j++;
        else i++;
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    std::vector<int> v1 = {1,2,3,6};
    std::vector<int> v2 = {2,3,4,5};
    std::cout << getCommon(v1, v2);
    return 0;
}

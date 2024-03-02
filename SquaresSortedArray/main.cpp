//
//  main.cpp
//  SquaresSortedArray
//
//  Created by Jaime Cuartas Granada on 2/3/2024.
//

#include <iostream>

std::vector<int> mergeSorted(std::vector<int>& nums1, std::vector<int>& nums2){
    std::vector<int> output;
    int n1 = static_cast<int>(nums1.size());
    int n2 = static_cast<int>(nums2.size());
    int i = n1-1 ,j = 0;
    while(i>=0 && j<n2){
        if(nums1[i] < nums2[j]) output.push_back(nums1[i--]);
        else output.push_back(nums2[j++]);
    }
    while (i>=0) output.push_back(nums1[i--]);
    while (j<n2) output.push_back(nums2[j++]);
    return output;
}


std::vector<int> sortedSquares(std::vector<int>& nums) {
    std::vector<int> output1;
    std::vector<int> output2;
    size_t n = nums.size();
    int i=0;
    while(i<n){
        if(nums[i]>=0) break;
        output1.push_back(nums[i]*nums[i]);
        i++;
    }
    while(i<n){
        output2.push_back(nums[i]*nums[i]);
        i++;
    }
    return mergeSorted(output1, output2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> input;
    input.push_back(-4);
    input.push_back(-1);
    input.push_back(0);
    input.push_back(3);
    input.push_back(10);
    
    std::vector<int> output = sortedSquares(input);
    for(int i=0; i<output.size(); i++){
        std::cout << output[i]<<", ";
    }
    std::cout << "Hello, World!\n";
    return 0;
}

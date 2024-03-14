//
//  main.cpp
//  BinarySubarrayWithSum
//
//  Created by Jaime Cuartas Granada on 14/3/2024.
//

#include <iostream>
#include <vector>
#include <unordered_map>

int max(int a, int b){
    return (a>b)? a: b;
}

int numSubarraysWithSum(std::vector<int>& nums, int goal) {
    int n = static_cast<int>(nums.size()), repeat = 0, i = 1, j = 0, sum = 0;
    while(j<n){
        sum += nums[j];
        if(sum==goal) {
            repeat++;
            break;
        }
        j++;
    }
    for(int k=j+1;k<n;k++){
        if(nums[k]==1) break;
        repeat++;
    }
    for(;i<n;i++){
        if(sum-nums[i-1]!=goal) sum-=nums[i-1];
        if(sum-nums[i-1]==goal) {
            repeat++;
            
        };
        for(int k=max(j,i);k<n;k++){
            if(sum!=goal && sum+nums[k]!=goal){
                continue;
            }
            if(sum!=goal && sum+nums[k]==goal){
                sum=goal;
                repeat++;
                j=k;
                continue;
            }
            if(sum==goal && sum+nums[k]==goal){
                repeat++;
                continue;
            }
            if(sum==goal && sum+nums[k]!=goal){
                break;
            }
        }
        j++;
    }
    return repeat;
}

int numSubarraysWithSum2(std::vector<int>& nums, int goal) {
    int n = static_cast<int>(nums.size());
    int sum = 0, count = 0;
    std::unordered_map<int, int> prevSums;
    prevSums[0] = 1;
    for(int num: nums){
        sum += num;
        count += prevSums[sum-goal];
        prevSums[sum]++;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    std::vector<int> v = {1,0,1,0,1};
    std::vector<int> v2 = {0,0,0,0,0};
    std::vector<int> v3 = {0,1,1,1,1};
    std::cout << numSubarraysWithSum2(v, 2 );
    return 0;
}

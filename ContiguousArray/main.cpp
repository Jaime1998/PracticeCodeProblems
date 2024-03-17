//
//  main.cpp
//  ContiguousArray
//
//  Created by Jaime Cuartas Granada on 17/3/2024.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

int findMaxLength(std::vector<int>& nums) {
    size_t n = nums.size();
    if(n==0) return 0;
    std::map<int, int> lastSimilar;
    lastSimilar[0] = -1;
    std::map<int, int>::iterator lastIndex;
    int maxLenght = 0;
    int currentLenght = 0;
    nums[0] = nums[0]==1? 1: -1;
    lastSimilar[nums[0]] = 0;
    for(int i=1; i<n; i++){
        nums[i] = nums[i-1] + ((nums[i])? 1: -1);
        lastIndex = lastSimilar.find(nums[i]);
        if(lastIndex != lastSimilar.end()){
            currentLenght = i - lastIndex->second;
            if(currentLenght>maxLenght) maxLenght = currentLenght;
            continue;
        }
        lastSimilar[nums[i]] = i;
    }
    return maxLenght;
}
int main(int argc, const char * argv[]) {
    std::vector<int> v {0,1,0,1};
    std::vector<int> v1 {0,1};
    std::vector<int> v2 {0,1,0};
    std::cout << findMaxLength(v);
    std::cout << findMaxLength(v1);
    std::cout << findMaxLength(v2);
    return 0;
}

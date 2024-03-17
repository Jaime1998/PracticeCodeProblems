//
//  main.cpp
//  ProductArrayExceptItself
//
//  Created by Jaime Cuartas Granada on 15/3/2024.
//

#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    std::vector<int> answer(n);
    answer[1] = nums[0];
    for(int i=2; i<n; i++){
        answer[i] = answer[i-1]*nums[i-1];
    }
    for(int i=n-2; i>0; i--){
        answer[i] = answer[i]*nums[i+1];
        nums[i] = nums[i]*nums[i+1];
    }
    answer[0] = nums[1];
    return answer;
}

int main(int argc, const char * argv[]) {
    std::vector<int> v = {1,2,3,4};
    std::vector<int> v2 = {0,0,0,0,0};
    std::vector<int> v3 = {0,1,1,1,1};
    productExceptSelf(v);
    return 0;
}

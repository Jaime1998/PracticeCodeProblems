//
//  main.cpp
//  SquaresSortedArray
//
//  Created by Jaime Cuartas Granada on 2/3/2024.
//

#include <iostream>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int start = 0, end = n-1;
    std::vector<int> output(n);
    int i=n-1;
    while(start<=end){
        if(abs(nums[start])>abs(nums[end])){
            output[i--] = nums[start]*nums[start];
            start++;
        }else{
            output[i--] = nums[end]*nums[end];
            end--;
        }
    }
    return output;
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
    return 0;
}

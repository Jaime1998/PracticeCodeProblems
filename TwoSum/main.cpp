//
//  main.cpp
//  TwoSum
//
//  Created by Jaime Cuartas Granada on 25/2/2024.
//

#include <iostream>
#include <vector>
#include <map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> map;
    for(int i=0; i<nums.size(); i++){
        int currentNumber = nums[i];
        int complement = target - currentNumber;
        if (map.contains(complement)) {
            std::vector<int> returnTuple{ i, map[complement]};
            return returnTuple;
        }
        map.insert({currentNumber, i});
    }
    std::vector<int> returnTuple{ 0, 0};
    return returnTuple;
}

int main(int argc, const char * argv[]) {
    std::vector<int> vectorInput{2,7,11,15};
    int targetInput = 9;
    std::vector<int> list = twoSum(vectorInput, targetInput);
    for (int & num: list){
        std::cout << num << "\n";
    }
    return 0;
}

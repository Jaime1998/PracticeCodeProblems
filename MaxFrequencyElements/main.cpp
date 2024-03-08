//
//  main.cpp
//  MaxFrequencyElements
//
//  Created by Jaime Cuartas Granada on 8/3/2024.
//

#include <iostream>
#include <vector>

int maxFrequencyElements(std::vector<int>& nums) {
    int frequencies[101] = {0};
    int maxFreq = 0;
    for(int num: nums){
        frequencies[num]++;
        if(frequencies[num]>maxFreq) maxFreq = frequencies[num];
    }
    int maxSum = 0;
    for(int i=0; i<=100; i++){
        if(frequencies[i] == maxFreq) maxSum++;
    }
    return maxSum*maxFreq;
}

int main(int argc, const char * argv[]) {
    std::vector<int> newV { 1,2,2,3,1,4 };
    
    std::cout << maxFrequencyElements(newV);
    return 0;
}

//
//  main.cpp
//  MaximizeHappinessSelectedChildren
//
//  Created by Jaime Cuartas Granada on 9/5/2024.
//

#include <iostream>
#include <vector>

long long maximumHappinessSum(std::vector<int>& happiness, int k) {
    std::sort(happiness.begin(), happiness.end(), std::greater<int>());
    int length = static_cast<int>(happiness.size());
    int turns = 0;
    long long sum = 0;
    for(int i=0; i<length && turns<k; turns++, i++){
        if(turns>happiness[i]) break;
        sum += happiness[i] - turns;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    std::vector v{12,1,42};
    std::cout << maximumHappinessSum(v, 3);
    return 0;
}

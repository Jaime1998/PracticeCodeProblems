//
//  main.cpp
//  MinimumNumberArrowsBurstBalloons
//
//  Created by Jaime Cuartas Granada on 18/3/2024.
//

#include <iostream>
#include <vector>
#include <iterator>

bool compareBallons(std::vector<int> balloon1, std::vector<int> balloon2){
    return balloon1[1]<balloon2[1];
}

int findMinArrowShots(std::vector<std::vector<int>>& points) {
    std::sort(points.begin(), points.end(), [](const std::vector<int>& balloon1, const std::vector<int> &balloon2){
        return balloon1[1]<balloon2[1];
    });
    std::vector<std::vector<int>>::iterator it = points.begin();
    int arrowsNeed = 1;
    int margin = (*it)[1];
    it++;
    while(it!=points.end()){
        if ((*it)[0] <= margin ) continue;
        arrowsNeed++;
        margin = (*it)[1];
        it++;
    }
    return arrowsNeed;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

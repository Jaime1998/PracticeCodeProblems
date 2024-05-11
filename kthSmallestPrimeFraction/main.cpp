//
//  main.cpp
//  kthSmallestPrimeFraction
//
//  Created by Jaime Cuartas Granada on 10/5/2024.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
    int lenght = static_cast<int>(arr.size());
    
    std::priority_queue<std::pair<double, std::pair<int, int>>, std::vector<std::pair<double, std::pair<int, int>>> ,std::greater<>> pq;
    for(int i=0; i<lenght-1; i++){
        pq.push({arr[i]/(double)arr[lenght-1], {i, lenght-1}});
    }
    while(k>1){
        k--;
        std::pair<int, int> smallest = pq.top().second;
        pq.pop();
        int divisor = smallest.first;
        int dividend = smallest.second - 1;
        if(divisor==dividend) continue;
        pq.push({arr[divisor]/(double)arr[dividend], {divisor, dividend}});
    }
    std::pair<int, int> smallest = pq.top().second;

    return {arr[smallest.first], arr[smallest.second]};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector v{1,2,3,5};
    std::vector v2 = kthSmallestPrimeFraction(v,3);
    return 0;
}

//
//  main.cpp
//  MinimumCostHireKWorkers
//
//  Created by Jaime Cuartas Granada on 11/5/2024.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
    int lenght = static_cast<int>(quality.size());
    std::priority_queue<int> pq;
    double output = INT_MAX;
    std::vector<std::pair<double,int>> ratio;
    for(int i=0;i<lenght; i++){
        ratio.push_back({wage[i]/(double)quality[i], quality[i]});
    }
    std::sort(ratio.begin(), ratio.end());
    double sum=0;
    for(int i=0;i<lenght; i++){
        double currRatio = ratio[i].second;
        pq.push(currRatio);
        sum += currRatio;
        if(pq.size()>k){
            sum-=pq.top();
            pq.pop();
        }
        double newOutput = sum*ratio[i].first;
        if(pq.size()==k && newOutput<output){
            output = newOutput;
        }
    }
    return output;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

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
    std::vector<int> v{10,20,5};
    std::vector<int> v1{70,50,30};
    mincostToHireWorkers(v,v1,2);
    return 0;
}

//
//  main.cpp
//  InsertInterval
//
//  Created by Jaime Cuartas Granada on 17/3/2024.
//

#include <iostream>
#include <vector>
#include <iterator>

int min(int a, int b){
    return (a<b)? a: b;
}
int max(int a, int b){
    return (a>b)? a: b;
}

std::vector<std::vector<int>>  twoIntervals(std::vector<int>& interval, std::vector<int>& newInterval) {
    std::vector<std::vector<int>> output;
    if(interval[1]>=newInterval[0]){
        interval[0] = min(interval[0], newInterval[0]);
        interval[1] = min(interval[1], newInterval[1]);
        output.push_back(interval);
        return output;
    }
    output.push_back(interval);
    output.push_back(newInterval);
    return output;
}

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
    std::vector<std::vector<int>>::iterator it = intervals.begin();
    std::vector<std::vector<int>>::iterator startErase = intervals.begin();
    std::vector<std::vector<int>>::iterator endErase = intervals.begin();
    bool inserted = false;
    while(it!=intervals.end()){
        if((*it)[1]<newInterval[0]){
            it++;
            continue;
        }
        if((*it)[0]<=newInterval[1]){
            newInterval[0] = min((*it)[0], newInterval[0]);
            newInterval[1] = max((*it)[1], newInterval[1]);
            if(!inserted) {
                startErase = it;
                endErase = it;
                inserted = true;
            }
            endErase++;
            it++;
            continue;
        }
        if(!inserted){
            startErase = it;
            endErase  = it;
            inserted = true;
        }
        break;
    }
    intervals.erase(startErase, endErase);
    if(!inserted) startErase = intervals.end();
    intervals.insert(startErase, newInterval);
    return intervals;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> interval{{1,2},{3,5},{6,7},{8,10},{12,16}};
    std::vector<std::vector<int>> interval2{{9,10}};
    std::vector<std::vector<int>> interval3{{1,5},{6,8}};
    std::vector<std::vector<int>> interval4{{3,5},{12,15}};
    std::vector<std::vector<int>> interval5{{1,3},{6,9}};
    std::vector<int> newInterval{2,5};
    insert(interval5, newInterval);

    return 0;
}

//
//  main.cpp
//  RelativeRanks
//
//  Created by Jaime Cuartas Granada on 8/5/2024.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
    int length = static_cast<int>(score.size());
    std::vector orderedScores = score;
    std::sort(orderedScores.begin(), orderedScores.end(), std::greater<int>());
    std::unordered_map<int, int> map;
    for(int i=0; i<length; i++){
        map.insert({orderedScores[i], i});
    }
    std::vector<std::string> output;
    for(int s: score){
        int position = map.find(s)->second;
        switch (position) {
            case 0:
                output.push_back("Gold Medal");
                break;
            case 1:
                output.push_back("Silver Medal");
                break;
            case 2:
                output.push_back("Bronze Medal");
                break;
            default:
                output.push_back(std::to_string(position));
                break;
        }
    }
    return output;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> v1{2,3,1};
    findRelativeRanks(v1);
    return 0;
}

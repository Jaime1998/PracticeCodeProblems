//
//  main.cpp
//  LongestSubstringWord
//
//  Created by Jaime Cuartas Granada on 25/2/2024.
//

#include <iostream>
#include <map>
#include <string>

int lengthOfLongestSubstring(std::string s) {
    std::map<char, int> map;
    int maxRepeats = 0;
    int repeats = 0;
    int initIndex = 0;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        std::map<char, int>::iterator indexFound = map.find(c);
        if(indexFound!=map.end() && initIndex<=(indexFound->second+1)){
            if(repeats>maxRepeats) maxRepeats = repeats;
            initIndex = indexFound->second+1;
            repeats = i - initIndex;
        }
        map.insert_or_assign(c, i);
        repeats++;
    }
    if(repeats>maxRepeats) maxRepeats = repeats;
    return maxRepeats;
}

int main(int argc, const char * argv[]) {
    std::cout << lengthOfLongestSubstring("pwwkew") << "\n";
    return 0;
}

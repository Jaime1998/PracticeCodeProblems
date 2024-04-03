//
//  main.cpp
//  IsomorphicString
//
//  Created by Jaime Cuartas Granada on 3/4/2024.
//

#include <iostream>

bool isIsomorphic(std::string s, std::string t) {
    int lenghtS = s.size();
    if(lenghtS!=t.size()) return false;
    const int nAlphabet = 256;
    int alphabetS[nAlphabet] = {0};
    int alphabetT[nAlphabet] = {0};
    for(int i=0; i<lenghtS; i++){
        int *letterS = &alphabetS[s[i]];
        int *letterT = &alphabetT[t[i]];
        if(*letterS==0 && *letterT==0){
            *letterS = t[i];
            *letterT = s[i];
        }else if(*letterS != t[i] || *letterT != s[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << isIsomorphic("badc", "baba");
    return 0;
}

//
//  main.cpp
//  MinimumLenghtDelitingSimilarEnds
//
//  Created by Jaime Cuartas Granada on 5/3/2024.
//

#include <iostream>
#include <string>

int minimumLength(std::string s) {
    int start = 0;
    int end = static_cast<int>(s.size())-1;
    while( start<end ){
        if(s[start] != s[end]) break;
        while(start < end-1 && s[start] == s[end-1]) end--;
        while(start+1 < end && s[start+1] == s[end]) start++;
        start++;
        end--;
    }
    return end-start+1;
}

int main(int argc, const char * argv[]) {
    std::cout << minimumLength("cabaabac");
    return 0;
}

//
//  main.cpp
//  LongestPalindromicSubstring
//
//  Created by Jaime Cuartas Granada on 26/2/2024.
//

#include <iostream>
#include <string>

std::string longestPalindrome(std::string s) {
    int n = static_cast<int>(s.size());
    int sTable [n][n];
    if (n==0) return 0;
    for(int i=0; i<n; i++){
        sTable[0][i] = (s[0] == s[i])? 1 : 0;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            sTable[i][j] = sTable[i-1][j] + ((s[i] == s[n-i-1])? 1 : 0);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

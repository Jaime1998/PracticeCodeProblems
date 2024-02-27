//
//  main.cpp
//  LongestPalindromicSubstring
//
//  Created by Jaime Cuartas Granada on 26/2/2024.
//

#include <iostream>
#include <string>

void printMatrix (bool a[][11]){
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            std::cout << a[i][j] << ",";
        }
        std::cout << "\n";
    }
}

std::string longestPalindrome(std::string s) {
    int n = static_cast<int>(s.size());
    if (n==0) return 0;
    if (n==1) return s;
    //the substring from 0 to 0 , 1 to 1, n to n is alway palindrome, because it is one letter
    bool isPalindromeTable [n][n];
    for(int i=0; i<11; i++){
        for(int j=0; j<11; j++){
            isPalindromeTable[i][j] = false;
        }
    }
    for(int i=0; i<n; i++){
        isPalindromeTable[i][i] = true;
    }
    //start with palindrome of size 1
    int maxPalindrome = 1;
    int startMaxPalindrome = 0;
    for(int i=0; i<(n-1); i++){
        isPalindromeTable[i][i+1] = s[i] == s[i+1];
        if(isPalindromeTable[i][i+1]){
            maxPalindrome = 2;
            startMaxPalindrome = i;
        }
    }
    for (int i=2; i<n; i++) {
        for(int j=0; j<(n-i); j++){
            if(isPalindromeTable[j+1][j+i-1]){
                isPalindromeTable[j][j+i] = (s[j] == s[j+i]);
                if(isPalindromeTable[j][j+i] && (i+1)>maxPalindrome){
                    maxPalindrome = i+1;
                    startMaxPalindrome = j;
                }
            }
        }
    }
    return s.substr(startMaxPalindrome, maxPalindrome);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << longestPalindrome("aacabdkacaa") << "\n";
    return 0;
}

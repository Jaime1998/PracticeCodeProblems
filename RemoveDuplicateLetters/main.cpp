//
//  main.cpp
//  RemoveDuplicateLetters
//
//  Created by Jaime Cuartas Granada on 1/3/2024.
//

#include <iostream>
#include <climits>

std::string removeDuplicateLetters(std::string s) {
    const size_t n = static_cast<size_t>(s.size());
    if(n==0) return "";
    if(n==1) return s;
    const size_t nLetter = 26;
    int alphabet[nLetter] = {};
    std::vector<std::string> maxSubstring(n);
    int startIndex = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int previousIndex = alphabet[s[j]-'a'];
            if(previousIndex<j && previousIndex>i) break;
            maxSubstring[i] += s[j];
            alphabet[s[j]-'a']=j+1;
        }
    }
    std::string maxString = "";
    int maxLength = 0;
    for(std::string c: maxSubstring){
        
        if(c.size()>maxLength){
            maxString = c;
            maxLength = static_cast<int>(c.size());
        }
        if(c.size()<maxLength) continue;
        if(c.compare(maxString) == -1) {
            maxString = c;
        }
        
        
    }
    return maxString;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << removeDuplicateLetters("cbacdcbc");
    std::string s1 = "bcaccgyih";
    std::cout << s1.compare("bcabc");
    return 0;
}

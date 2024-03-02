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
    
    const size_t nLetter = 26;
    int startIndex = 0;
    int endIndex = 0;
    std::vector<std::vector<int>> weight;
    for(int i=0; i<n; i++){
        std::vector<int> vectorI;
        vectorI.push_back(INT_MAX);
        weight.push_back(vectorI);
    }
    int minWeight = INT_MAX;
    int lenght = 1;
    int alphabet[nLetter] = {};
    if(n==2) return s.substr(startIndex, endIndex);
    
    for(int i=0; i<n; i++){
        startIndex = i;
        for(int j=i; j<n-1; j++){
            int previousIndex = alphabet[s[j]-'a'];
            if(previousIndex<j && previousIndex>startIndex) break;
            weight[i].push_back((j==0)?s[j]:(weight[i][j-i-1]*nLetter+s[j]));
            alphabet[s[j]-'a']=j;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<weight[i].size(); j++){
            if((i-j)>lenght && weight[i][j]<minWeight){
                minWeight=weight[i][j];
                startIndex=i;
                endIndex=j;
            }
        }
    }
    
    
    for(int i=0; i<nLetter; i++){
        std::cout << alphabet[i] << "\n";
    }
    for(int i=0; i<n; i++){
        std::cout << s[i] << "\n";
    }
    return s.substr(startIndex,endIndex);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << removeDuplicateLetters("bcabc");
    return 0;
}

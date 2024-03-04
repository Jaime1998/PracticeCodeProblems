//
//  main.cpp
//  BackTokens
//
//  Created by Jaime Cuartas Granada on 4/3/2024.
//

#include <iostream>
#include <vector>

int bagOfTokensScore(std::vector<int>& tokens, int power) {
    int n = static_cast<int>(tokens.size());
    int score = 0;
    int maxScore = 0;
    int start = 0;
    int end = n-1;
    std::sort (tokens.begin(), tokens.end());
    while (start<=end) {
        if(power >= tokens[start]){
            power -= tokens[start];
            score++;
            start++;
            if(score > maxScore) maxScore = score;
        } else if (score>0) {
            power += tokens[end];
            score--;
            end--;
        } else break;
    }
    return maxScore;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

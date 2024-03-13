//
//  main.cpp
//  FindPivotInteger
//
//  Created by Jaime Cuartas Granada on 13/3/2024.
//

#include <iostream>

int pivotInteger(int n) {
    int currentLeft = 1;
    int sumLeft = 1;
    int currentRight = n;
    int sumRight = n;
    while(currentLeft<currentRight){
        if(sumLeft<=sumRight){
            currentLeft++;
            sumLeft+=currentLeft;
        } else {
            currentRight--;
            sumRight+=currentRight;
        }
    }
    return (sumLeft == sumRight)? currentLeft: -1;
}

int main(int argc, const char * argv[]) {
    std::cout << pivotInteger(8);
    return 0;
}

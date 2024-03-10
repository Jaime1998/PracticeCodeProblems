//
//  main.cpp
//  CheckPointReachable
//
//  Created by Jaime Cuartas Granada on 9/3/2024.
//

#include <iostream>
#include <math.h>

bool isSqrt(int target){
    while(target!=0){
        if(target%2 != 0) return false;
        target = target/2;
    }
    return true;
}
bool moveY(int targetX, int targetY) {
    targetY--;
    if(targetY>0) return isSqrt(targetY);
    else return targetY%targetX ==0;
}

bool isReachable(int targetX, int targetY) {
    return moveY(targetX, targetY) && moveY(targetY, targetX);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << isReachable(4, 7);
    return 0;
}

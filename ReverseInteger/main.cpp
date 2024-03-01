//
//  main.cpp
//  ReverseInteger
//
//  Created by Jaime Cuartas Granada on 1/3/2024.
//

#include <iostream>
#include <climits>

int reverse(int x) {
    if(x==0) return 0;
    bool positive = x>=0;
    const int overflow = INT_MAX;
    const int underflow = INT_MIN;
    int remainder = x%10;
    int output = remainder;
    x /= 10;
    while (x!=0) {
        remainder = x%10;
        x /= 10;
        if(positive && (output > (overflow-remainder)/10)){
            return overflow;
        }
        if(!positive && (output < (underflow-remainder)/10)){
            return underflow;
        }
        output = output*10 + remainder;
    }
    return output;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << reverse(1534236469);
    return 0;
}

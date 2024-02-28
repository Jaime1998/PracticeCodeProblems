//
//  main.cpp
//  StringToInteger
//
//  Created by Jaime Cuartas Granada on 28/2/2024.
//

#include <iostream>
#include <string>

int startChars(std::string s){
    int n = static_cast<int>(s.size());
    for(int i = 0; i<n; i++){
        //if it is not a space
        if(s[i] != 32){
            return i;
        }
    }
    return 0;
}
int myAtoi(std::string s) {

    int n = static_cast<int>(s.size());
    int i = startChars(s);
    if((i-n)==0) return 0;
    double output = 0;
    bool positive = true;
    if(s[i] == 43) {
        i++;
    } else if(s[i] == 45) {
        positive = false;
        i++;
    }
    
    int num = s[i]-48;
    if(num >= 0 && num<=9){
        output = num;
        if(!positive){
            output = num*(-1);
        }
        i++;
    } else return 0;
    const int overflow = pow(2,31)-1;
    const int underflow = pow(2,31) * (-1);
    for(; i<n; i++){
        int num = s[i]-48;
        if(num >= 0 && num<=9){
            if(positive && output > (overflow-num)/10) return overflow;
            double left = underflow/10-num/10;
            if(!positive && output < (left)) return underflow;
            if(positive){
                output = output*10+num;
            }else{
                output = output*10-num;
            }
        } else return output;
    }
    return output;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << myAtoi("-2147483649");
    return 0;
}

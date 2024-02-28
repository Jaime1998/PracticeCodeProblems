//
//  main.cpp
//  ZigzagConversion
//
//  Created by Jaime Cuartas Granada on 28/2/2024.
//

#include <iostream>
#include <string>

std::string convert(std::string s, int numRows) {
    std::string output = "";
    int n = static_cast<int>(s.size());
    int diagonal = 0;
    int step =(numRows-1)*2;
    
    for(int i=0; i<numRows; i++){
        for(int j=0; (i+j)<n; j+=step){
            output += s[i+j];
            diagonal = step+j-i;
            if(((j+i)%(numRows-1)!=0) && (diagonal<n)){
                output += s[diagonal];
            }
        }
    }
    return output;
}

int main(int argc, const char * argv[]) {
    std::cout << convert("PAYPALISHIRING", 4);
    return 0;
}

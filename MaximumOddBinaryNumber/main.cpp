//
//  main.cpp
//  MaximumOddBinaryNumber
//
//  Created by Jaime Cuartas Granada on 1/3/2024.
//

#include <iostream>
#include <string>

std::string maximumOddBinaryNumber(std::string s) {
    int n = static_cast<int>(s.size());
    int ones = 0;
    for (char c: s) if(c=='1') ones++;
    s.clear();
    std::string output(ones-1, '1');
    output = output.append(n-ones, '0');
    output = output.append(1, '1');
    return output;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << maximumOddBinaryNumber("0101");
    return 0;
}

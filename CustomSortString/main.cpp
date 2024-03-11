//
//  main.cpp
//  CustomSortString
//
//  Created by Jaime Cuartas Granada on 11/3/2024.
//

#include <iostream>
#include <string>

std::string customSortString2(std::string order, std::string s) {
    std::string output = "";
    while(order.compare("")!=0){
        int indexChar = static_cast<int>(s.find(order.back()));
        if(indexChar!=std::string::npos){
            s.erase(s.begin()+indexChar);
            output.insert(output.begin(),order.back());
        }else{
            order.pop_back();
        }
    }
    return output.append(s);
}


std::string customSortString(std::string order, std::string s) {
    int orderArr['z'-'a'+1] = {};
    for(char cOrder: order){
        orderArr[cOrder-'a']++;
    }
    for(char cS: s){
        if(orderArr[cS-'a'] > 0) orderArr[cS-'a']++;
    }
    
    std::string output = "";
    for(char cOrder: order){
        if(orderArr[cOrder-'a']>1) output = output.append(orderArr[cOrder-'a']-1, cOrder);
    }
    for(char cS: s){
        if(orderArr[cS-'a'] == 0) output.push_back(cS);
    }
    return output;
}

int main(int argc, const char * argv[]) {
    std::string order = "jftiugkz";
    std::string s = "kfiukutzjg";
    std::cout << customSortString(order, s);
    return 0;
}

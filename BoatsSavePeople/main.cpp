//
//  main.cpp
//  BoatsSavePeople
//
//  Created by Jaime Cuartas Granada on 4/5/2024.
//

#include <iostream>
#include <vector>

int numRescueBoats(std::vector<int>& people, int limit)  {
    std::sort(people.begin(), people.end());
    int output = 0;
    int left = 0;
    int right = static_cast<int>(people.size())-1;
    while(left<=right){
        output++;
        if(people[right--]+people[left]<=limit) left++;;
    }
    return output;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> myvector{3,5,3,4};
    std::cout << numRescueBoats(myvector,5);
    return 0;
}

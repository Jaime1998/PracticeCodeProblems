//
//  main.cpp
//  LargestLocalValueMatrix
//
//  Created by Jaime Cuartas Granada on 12/5/2024.
//

#include <iostream>
#include <vector>

std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
    int n = static_cast<int>(grid.size());
    std::vector<std::vector<int>> output(n-2, std::vector<int>(n-2, 0));
    for(int i=0; i<n-2; i++){
        for(int j=0; j<n-2; j++){
            for (int k = i ; k < i+3 ; k++) {
                for (int l = j ; l < j+3 ; l++) {
                    if(grid[k][l]>output[i][j]) output[i][j] = grid[k][l];
                }
            }
        }
        
    }
    return output;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

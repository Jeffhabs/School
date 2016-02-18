//
//  main.cpp
//  DataManipulation
//
//  Created by Jeffrey Haberle on 12/14/15.
//  Copyright © 2015 CS3005. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>



int read_file(const char *filename, int *data) {

    std::ifstream fin(filename);
    if(!fin)
    {
        std::cerr << " error opening file: " << filename << std::endl;
        return 0;
    }
    
    int tmp;
    int size = 0;
    while(fin) {
        
    }
}
int main() {

};


//
//  main.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 04/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Cell.h"

int main (int argc, const char * argv[])
{
    std::cout << "Hello, World!\n";
    
    try {
        Cell sCell0, sCell1(1), sCell2(10);
    } catch (std::string & s) {
        std::cout << s << std::endl;
    }
    return 0;
}

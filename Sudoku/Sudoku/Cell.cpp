//
//  Cell.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 04/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Cell.h"
#include <exception>

Cell::Cell() : bIsEmpty_(true)
{}

Cell::Cell(const std::size_t iValue) : iValue_(iValue), bIsEmpty_(false)
{
    if (iValue == 0 || iValue > 9)
    {
        throw "Incorrect value";
    }
}

Cell::~Cell()
{}
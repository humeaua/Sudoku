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

Cell::Cell() : bIsEmpty_(true), iValue_(0)
{}

Cell::Cell(const unsigned int iValue) : iValue_(iValue), bIsEmpty_(false)
{
    if (iValue == 0 || iValue > 9)
    {
        throw "Incorrect value";
    }
}

Cell::~Cell()
{}

bool Cell::IsEmpty() const
{
    return bIsEmpty_;
}

Cell & Cell::operator=(unsigned int iValue)
{
    iValue_ = iValue;
    bIsEmpty_ = false;
    return *this;
}

Cell::operator unsigned int() const
{
    return iValue_;
}

bool Cell::operator==(unsigned int iValue) const
{
    if (IsEmpty())
        return false;
    
    return iValue_ == iValue;
}
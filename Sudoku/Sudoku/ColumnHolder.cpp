//
//  ColumnHolder.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ColumnHolder.h"

ColumnHolder::ColumnHolder(const Cell & sTop, const Cell & sCenter, const Cell & sBottom) : TripleHolder(sTop, sCenter, sBottom)
{}

const Cell & ColumnHolder::T() const
{
    return GetLeft();
}

const Cell & ColumnHolder::C() const
{
    return GetCenter();
}

const Cell & ColumnHolder::B() const
{
    return GetRight();
}
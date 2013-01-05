//
//  RowHolder.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "RowHolder.h"

RowHolder::RowHolder(const Cell & sG, const Cell & sC, const Cell & sD) : TripleHolder(sG, sC, sD)
{}

const Cell & RowHolder::G() const
{
    return GetLeft();
}

const Cell & RowHolder::C() const
{
    return GetCenter();
}

const Cell & RowHolder::D() const
{
    return GetRight();
}
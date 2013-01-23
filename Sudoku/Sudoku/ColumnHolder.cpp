//
//  ColumnHolder.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ColumnHolder.h"

ColumnHolder::ColumnHolder(Cell & sTop, Cell & sCenter, Cell & sBottom) : TripleHolder(sTop, sCenter, sBottom)
{}

Cell & ColumnHolder::T()
{
    return GetLeft();
}

Cell & ColumnHolder::C()
{
    return GetCenter();
}

Cell & ColumnHolder::B()
{
    return GetRight();
}
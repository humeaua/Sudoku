//
//  RowHolder.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "RowHolder.h"

RowHolder::RowHolder(Cell & sG, Cell & sC, Cell & sD) : TripleHolder(sG, sC, sD)
{}

Cell & RowHolder::G()
{
    return GetLeft();
}

Cell & RowHolder::C()
{
    return GetCenter();
}

Cell & RowHolder::D()
{
    return GetRight();
}
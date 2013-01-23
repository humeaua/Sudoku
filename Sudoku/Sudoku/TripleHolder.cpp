//
//  TripleHolder.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "TripleHolder.h"

TripleHolder::TripleHolder(Cell & sLeft, Cell & sCenter, Cell & sRight) : sLeft_(sLeft), sCenter_(sCenter), sRight_(sRight)
{}

Cell & TripleHolder::GetLeft()
{
    return sLeft_;
}

Cell & TripleHolder::GetCenter()
{
    return sCenter_;
}

Cell & TripleHolder::GetRight()
{
    return sRight_;
}
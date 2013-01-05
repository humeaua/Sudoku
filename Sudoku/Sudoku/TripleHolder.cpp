//
//  TripleHolder.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "TripleHolder.h"

TripleHolder::TripleHolder(const Cell & sLeft, const Cell & sCenter, const Cell & sRight)
{
    sRight_ = sRight;
    sCenter_ = sCenter;
    sLeft_ = sLeft;
}

const Cell & TripleHolder::GetLeft() const
{
    return sLeft_;
}

const Cell & TripleHolder::GetCenter() const
{
    return sCenter_;
}

const Cell & TripleHolder::GetRight() const
{
    return sRight_;
}
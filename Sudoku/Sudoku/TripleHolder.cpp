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

void TripleHolder::flagValues(ValueEliminator &sValueEliminator) const
{
    if (!sLeft_.IsEmpty())
    {
        unsigned int iValue = sLeft_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
    if (!sCenter_.IsEmpty())
    {
        unsigned int iValue = sCenter_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
    if (!sRight_.IsEmpty())
    {
        unsigned int iValue = sRight_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
}

bool TripleHolder::isValuePresent(unsigned int iValue) const
{
    ValueEliminator sValueEliminator;
    flagValues(sValueEliminator);
    return sValueEliminator.flag(iValue);
}

std::vector<int> TripleHolder::indexEmpty()
{
    std::vector<int> index;
    if(sLeft_.IsEmpty()){
        index.push_back(1);
    }
    if(sCenter_.IsEmpty()){
        index.push_back(2);
    }
    if(sRight_.IsEmpty()){
        index.push_back(3);
    }
    return index;
}
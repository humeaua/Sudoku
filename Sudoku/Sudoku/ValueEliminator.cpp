//
//  ValueEliminator.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 22/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "ValueEliminator.h"

ValueEliminator::ValueEliminator()
{
    for (int i = 0 ; i < 9 ; ++i)
    {
        bValues_[i] = false;
    }
}

bool ValueEliminator::flag(unsigned int iValue) const
{
    if (iValue == 0 || iValue > 9)
    {
        throw "Value has to be between 1 and 9";
    }
    return bValues_[iValue - 1];
}

unsigned int ValueEliminator::availableValues() const
{
    unsigned int iResult = 0;
    for (int i = 0 ; i < 9 ; ++i)
    {
        if (bValues_[i])
        {
            iResult++;
        }
    }
    return iResult;
}

std::set<unsigned int> ValueEliminator::availableValue() const
{
    std::set<unsigned int> sResult;
    for (unsigned int i = 0 ; i < 9 ; ++i)
    {
        if (!bValues_[i])
        {
            //  first value is 0
            sResult.insert(i + 1);
        }
    }
    if (sResult.size() == 0)
    {
        throw "No Available Value";
    }
    return sResult;
}

void ValueEliminator::SetTrue(unsigned int iValue)
{
    bValues_[iValue] = true;
}
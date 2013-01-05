//
//  RegionHolder.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "RegionHolder.h"

RegionHolder::RegionHolder(const Region & sRegion) : Region(sRegion)
{}

const Cell & RegionHolder::GetNO() const
{
    return sNO_;
}

const Cell & RegionHolder::GetNE() const
{
    return sNE_;
}

const Cell & RegionHolder::GetN() const
{
    return sN_;
}

const Cell & RegionHolder::GetO() const
{
    return sO_;
}

const Cell & RegionHolder::GetC() const
{
    return sC_;
}

const Cell & RegionHolder::GetE() const
{
    return sE_;
}

const Cell & RegionHolder::GetS() const
{
    return sS_;
}

const Cell & RegionHolder::GetSO() const
{
    return sSO_;
}

const Cell & RegionHolder::GetSE() const
{
    return sSE_;
}

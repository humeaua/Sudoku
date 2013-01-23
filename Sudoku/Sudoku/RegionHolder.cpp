//
//  RegionHolder.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "RegionHolder.h"

RegionHolder::RegionHolder(Region & sRegion) : sNO_(sRegion.sNO_), sN_(sRegion.sN_), sNE_(sRegion.sNE_), sO_(sRegion.sO_), sC_(sRegion.sC_), sE_(sRegion.sE_), sSE_(sRegion.sSE_), sS_(sRegion.sS_), sSO_(sRegion.sSO_)
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

RowHolder RegionHolder::TopRow()
{
    return RowHolder(sNO_, sN_, sNE_);
}

RowHolder RegionHolder::MiddleRow()
{
    return RowHolder(sO_, sC_, sE_);
}

RowHolder RegionHolder::BottomRow()
{
    return RowHolder(sSE_, sS_, sSO_);
}

ColumnHolder RegionHolder::LeftColumn()
{
    return ColumnHolder(sNO_, sO_, sSO_);
}

ColumnHolder RegionHolder::MiddleColumn()
{
    return ColumnHolder(sN_, sC_, sS_);
}

ColumnHolder RegionHolder::RightColumn()
{
    return ColumnHolder(sNE_, sE_, sSE_);
}
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

Cell & RegionHolder::GetNO()
{
    return sNO_;
}

Cell & RegionHolder::GetNE()
{
    return sNE_;
}

Cell & RegionHolder::GetN()
{
    return sN_;
}

Cell & RegionHolder::GetO()
{
    return sO_;
}

Cell & RegionHolder::GetC() 
{
    return sC_;
}

Cell & RegionHolder::GetE() 
{
    return sE_;
}

Cell & RegionHolder::GetS()
{
    return sS_;
}

Cell & RegionHolder::GetSO()
{
    return sSO_;
}

Cell & RegionHolder::GetSE()
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

const RowHolder RegionHolder::TopRow() const
{
    return RowHolder(sNO_, sN_, sNE_);
}

const RowHolder RegionHolder::MiddleRow() const
{
    return RowHolder(sO_, sC_, sE_);
}

const RowHolder RegionHolder::BottomRow() const
{
    return RowHolder(sSE_, sS_, sSO_);
}

const ColumnHolder RegionHolder::LeftColumn() const
{
    return ColumnHolder(sNO_, sO_, sSO_);
}

const ColumnHolder RegionHolder::MiddleColumn() const
{
    return ColumnHolder(sN_, sC_, sS_);
}

const ColumnHolder RegionHolder::RightColumn() const
{
    return ColumnHolder(sNE_, sE_, sSE_);
}

void RegionHolder::flagValues(ValueEliminator &sValueEliminator) const
{
    if (!sNO_.IsEmpty())
    {
        sValueEliminator.SetTrue(0);
    }
    if (!sN_.IsEmpty())
    {
        sValueEliminator.SetTrue(1);
    }
    if (!sNE_.IsEmpty())
    {
        sValueEliminator.SetTrue(2);
    }
    if (!sO_.IsEmpty())
    {
        sValueEliminator.SetTrue(3);
    }
    if (sC_.IsEmpty())
    {
        sValueEliminator.SetTrue(4);
    }
    if (!sE_.IsEmpty())
    {
        sValueEliminator.SetTrue(5);
    }
    if (!sSO_.IsEmpty())
    {
        sValueEliminator.SetTrue(6);
    }
    if (!sS_.IsEmpty())
    {
        sValueEliminator.SetTrue(7);
    }
    if (!sSE_.IsEmpty())
    {
        sValueEliminator.SetTrue(8);
    }
}
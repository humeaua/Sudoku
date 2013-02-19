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
        unsigned int iValue = sNO_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
    if (!sN_.IsEmpty())
    {
        unsigned int iValue = sN_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
    if (!sNE_.IsEmpty())
    {
        unsigned int iValue = sNE_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
    if (!sO_.IsEmpty())
    {
        unsigned int iValue = sO_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
    if (!sC_.IsEmpty())
    {
        unsigned int iValue = sC_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
    if (!sE_.IsEmpty())
    {
        unsigned int iValue = sE_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
    if (!sSO_.IsEmpty())
    {
        unsigned int iValue = sSO_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
    if (!sS_.IsEmpty())
    {
        unsigned int iValue = sS_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
    if (!sSE_.IsEmpty())
    {
        unsigned int iValue = sSE_ - 1;
        sValueEliminator.SetTrue(iValue);
    }
}

bool RegionHolder::isValuePresent(unsigned int iValue) const
{
    ValueEliminator sValueEliminator;
    flagValues(sValueEliminator);
    return sValueEliminator.flag(iValue);
}

bool RegionHolder::isFull() const
{
    return !(sNO_.IsEmpty() && sN_.IsEmpty() && sNE_.IsEmpty() && sO_.IsEmpty() && sC_.IsEmpty() && sE_.IsEmpty() && sSO_.IsEmpty() && sS_.IsEmpty() && sSE_.IsEmpty());
}

bool RegionHolder::isConsistent()
{
    bool result = true;
    for(int i = 1; i<10; i++)
        {
        if( TopRow().isValuePresent(i) && MiddleRow().isValuePresent(i)) {result=false;}
        else if (TopRow().isValuePresent(i) && BottomRow().isValuePresent(i)) {result=false;}
        else if (MiddleRow().isValuePresent(i) && BottomRow().isValuePresent(i)) {result=false;}
        }
    
    for(int i = 1; i<10; i++)
        {
        if( LeftColumn().isValuePresent(i) && MiddleColumn().isValuePresent(i)) {result=false;}
        else if (LeftColumn().isValuePresent(i) && RightColumn().isValuePresent(i)) {result=false;}
        else if (MiddleColumn().isValuePresent(i) && RightColumn().isValuePresent(i)) {result=false;}
        }
    
    return result;
}
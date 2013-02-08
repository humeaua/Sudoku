//
//  Grid.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Grid.h"

Grid::Grid(const Region & sRegionNO, const Region & sRegionN, const Region & sRegionNE, const Region & sRegionO, const Region & sRegionC, const Region & sRegionE, const Region & sRegionSO, const Region & sRegionS, const Region & sRegionSE) :

sRegionNO_(sRegionNO),
sRegionN_(sRegionN),
sRegionNE_(sRegionNE),
sRegionO_(sRegionO),
sRegionC_(sRegionC),
sRegionE_(sRegionE), 
sRegionSO_(sRegionSO), 
sRegionS_(sRegionS), 
sRegionSE_(sRegionSE)

{}

Grid::~Grid()
{}

bool Grid::IsFull() const
{
    return sRegionC_.IsFull() && sRegionE_.IsFull() && sRegionN_.IsFull() && sRegionNE_.IsFull() && sRegionNO_.IsFull() && sRegionO_.IsFull() && sRegionS_.IsFull() && sRegionSE_.IsFull() && sRegionSO_.IsFull();
}

RegionHolder Grid::GetNO()
{
    return RegionHolder(sRegionNO_);
}

RegionHolder Grid::GetNE()
{
    return RegionHolder(sRegionNE_);
}

RegionHolder Grid::GetN()
{
    return RegionHolder(sRegionN_);
}

RegionHolder Grid::GetO()
{
    return RegionHolder(sRegionO_);
}

RegionHolder Grid::GetC()
{
    return RegionHolder(sRegionC_);
}

RegionHolder Grid::GetE()
{
    return RegionHolder(sRegionE_);
}

RegionHolder Grid::GetS()
{
    return RegionHolder(sRegionS_);
}

RegionHolder Grid::GetSE()
{
    return RegionHolder(sRegionSE_);
}

RegionHolder Grid::GetSO()
{
    return RegionHolder(sRegionSO_);
}

bool Grid::Accept(const IVisitor &sVisitor)
{
    return sVisitor.Visit(*this);
}

bool Grid::IsPresentValueColumn(int iCol, int intValue)
{
    bool res = false;
    switch(iCol)
    {
        case 1:
        {
        if((*this).GetNO().LeftColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetO().LeftColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSO().LeftColumn().isValuePresent(intValue)){res=true;}
        break;}
        
        case 2:
        {
        if((*this).GetNO().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetO().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSO().MiddleColumn().isValuePresent(intValue)){res=true;}
        break;}
        
        case 3:
        {
        if((*this).GetNO().RightColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetO().RightColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSO().RightColumn().isValuePresent(intValue)){res=true;}
        break;}
        
        case 4:
        {
        if((*this).GetN().LeftColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetC().LeftColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetS().LeftColumn().isValuePresent(intValue)){res=true;}
        break;}

        case 5:
        {
        if((*this).GetN().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetC().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetS().MiddleColumn().isValuePresent(intValue)){res=true;}
        break;}
        
        case 6:
        {
        if((*this).GetN().RightColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetC().RightColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetS().RightColumn().isValuePresent(intValue)){res=true;}
        break;}
        case 7:
        {
        if((*this).GetNE().LeftColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetE().LeftColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSE().LeftColumn().isValuePresent(intValue)){res=true;}
        break;}
        case 8:
        {
        if((*this).GetNE().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetE().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSE().MiddleColumn().isValuePresent(intValue)){res=true;}
        break;}
        case 9:
        {
        if((*this).GetNE().RightColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetE().RightColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSE().RightColumn().isValuePresent(intValue)){res=true;}
        break;}
    }
    return res;
}
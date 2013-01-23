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
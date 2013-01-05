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
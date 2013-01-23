//
//  OnlyOneChoiceInRegionVisitor.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 22/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "OnlyOneChoiceInRegionVisitor.h"
#include "LastCellFinder.h"

/*bool OnlyOneChoiceInRegionVisitor::Visit(const Grid &ioGrid) const
{
    bool bResult = false;
    
    RegionHolder sNO = ioGrid.GetNO();
    LastCellFinder sLastCellFinderNO(sNO.TopRow(), sNO.MiddleRow(), sNO.BottomRow());
    bool bFill = sLastCellFinderNO.fill();
    bResult = bFill || bResult;
    
    RegionHolder sN = ioGrid.GetN();
    LastCellFinder sLastCellFinderN(sN.TopRow(), sN.MiddleRow(), sN.BottomRow());
    bFill = sLastCellFinderN.fill();
    bResult = bFill || bResult;
    
    RegionHolder sNE = ioGrid.GetNE();
    LastCellFinder sLastCellFinderNE(sNE.TopRow(), sNE.MiddleRow(), sNE.BottomRow());
    bFill = sLastCellFinderNE.fill();
    bResult = bFill || bResult;
    
    RegionHolder sO = ioGrid.GetO();
    LastCellFinder sLastCellFinderO(sO.TopRow(), sO.MiddleRow(), sO.BottomRow());
    bFill = sLastCellFinderO.fill();
    bResult = bFill || bResult;
    
    RegionHolder sC = ioGrid.GetC();
    LastCellFinder sLastCellFinderC(sC.TopRow(), sC.MiddleRow(), sC.BottomRow());
    bFill = sLastCellFinderC.fill();
    bResult = bFill || bResult;
    
    RegionHolder sE = ioGrid.GetE();
    LastCellFinder sLastCellFinderE(sE.TopRow(), sE.MiddleRow(), sE.BottomRow());
    bFill = sLastCellFinderE.fill();
    bResult = bFill || bResult;
    
    RegionHolder sSO = ioGrid.GetSO();
    LastCellFinder sLastCellFinderSO(sSO.TopRow(), sSO.MiddleRow(), sSO.BottomRow());
    bFill = sLastCellFinderSO.fill();
    bResult = bFill || bResult;
    
    RegionHolder sS = ioGrid.GetS();
    LastCellFinder sLastCellFinderS(sS.TopRow(), sS.MiddleRow(), sS.BottomRow());
    bFill = sLastCellFinderS.fill();
    bResult = bFill || bResult;
    
    RegionHolder sSE = ioGrid.GetSE();
    LastCellFinder sLastCellFinderSE(sSE.TopRow(), sSE.MiddleRow(), sSE.BottomRow());
    bFill = sLastCellFinderSE.fill();
    bResult = bFill || bResult;
    
    return bResult;
}*/
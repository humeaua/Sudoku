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

bool OnlyOneChoiceInRegionVisitor::Visit(Grid &ioGrid) const
{
    bool bResult = false;
    
    RegionHolder sNO = ioGrid.GetNO();
    RowHolder sNOTop = sNO.TopRow(), sNOMiddle = sNO.MiddleRow(), sNOBottom = sNO.BottomRow();
    LastCellFinder sLastCellFinderNO(sNOTop, sNOMiddle, sNOBottom);
    bool bFill = sLastCellFinderNO.fill();
    bResult = bFill || bResult;
    
    RegionHolder sN = ioGrid.GetN();
    RowHolder sNTop = sN.TopRow(), sNMiddle = sN.MiddleRow(), sNBottom = sN.BottomRow();
    LastCellFinder sLastCellFinderN(sNTop, sNMiddle, sNBottom);
    bFill = sLastCellFinderN.fill();
    bResult = bFill || bResult;
    
    RegionHolder sNE = ioGrid.GetNE();
    RowHolder sNETop = sNE.TopRow(), sNEMiddle = sNE.MiddleRow(), sNEBottom = sNE.BottomRow();
    LastCellFinder sLastCellFinderNE(sNETop, sNEMiddle, sNEBottom);
    bFill = sLastCellFinderNE.fill();
    bResult = bFill || bResult;
    
    RegionHolder sO = ioGrid.GetO();
    RowHolder sOTop = sO.TopRow(), sOMiddle = sO.MiddleRow(), sOBottom = sO.BottomRow();
    LastCellFinder sLastCellFinderO(sOTop, sOMiddle, sOBottom);
    bFill = sLastCellFinderO.fill();
    bResult = bFill || bResult;
    
    RegionHolder sC = ioGrid.GetC();
    RowHolder sCTop = sC.TopRow(), sCMiddle = sC.MiddleRow(), sCBottom = sC.BottomRow();
    LastCellFinder sLastCellFinderC(sCTop, sCMiddle, sCBottom);
    bFill = sLastCellFinderC.fill();
    bResult = bFill || bResult;
    
    RegionHolder sE = ioGrid.GetE();
    RowHolder sETop = sE.TopRow(), sEMiddle = sE.MiddleRow(), sEBottom = sE.BottomRow();
    LastCellFinder sLastCellFinderE(sETop, sEMiddle, sEBottom);
    bFill = sLastCellFinderE.fill();
    bResult = bFill || bResult;
    
    RegionHolder sSO = ioGrid.GetSO();
    RowHolder sSOTop = sSO.TopRow(), sSOMiddle = sSO.MiddleRow(), sSOBottom = sSO.BottomRow();
    LastCellFinder sLastCellFinderSO(sSOTop, sSOMiddle, sSOBottom);
    bFill = sLastCellFinderSO.fill();
    bResult = bFill || bResult;
    
    RegionHolder sS = ioGrid.GetS();
    RowHolder sSTop = sS.TopRow(), sSMiddle = sS.MiddleRow(), sSBottom = sS.BottomRow();
    LastCellFinder sLastCellFinderS(sSTop, sSMiddle, sSBottom);
    bFill = sLastCellFinderS.fill();
    bResult = bFill || bResult;
    
    RegionHolder sSE = ioGrid.GetSE();
    RowHolder sSETop = sSE.TopRow(), sSEMiddle = sSE.MiddleRow(), sSEBottom = sSE.BottomRow();
    LastCellFinder sLastCellFinderSE(sSETop, sSEMiddle, sSEBottom);
    bFill = sLastCellFinderSE.fill();
    bResult = bFill || bResult;
    
    return bResult;
}
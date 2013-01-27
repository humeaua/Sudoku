//
//  OnlyOneChoiceInColumnVisitor.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 22/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "OnlyOneChoiceInColumnVisitor.h"
#include "RowHolder.h"
#include "LastCellFinder.h"
#include "RegionHolder.h"

bool OnlyOneChoiceInColumnVisitor::Visit(Grid &ioGrid) const
{
    bool bResult = false;
    
    //  First column
    ColumnHolder    sColumnHolder11(ioGrid.GetNO().GetNO(), ioGrid.GetNO().GetO(), ioGrid.GetNO().GetSO()),
                    sColumnHolder12(ioGrid.GetO().GetNO(), ioGrid.GetO().GetO(), ioGrid.GetO().GetSO()),
                    sColumnHolder13(ioGrid.GetSO().GetNO(), ioGrid.GetSO().GetO(), ioGrid.GetSO().GetSO());
    LastCellFinder sLastCellFinder1(sColumnHolder11, sColumnHolder12, sColumnHolder13);
    bool bFill = sLastCellFinder1.fill();
    bResult = bFill || bResult;
    
    //  Second column
    ColumnHolder    sColumnHolder21(ioGrid.GetNO().GetN(), ioGrid.GetNO().GetC(), ioGrid.GetNO().GetS()),
                    sColumnHolder22(ioGrid.GetO().GetN(), ioGrid.GetO().GetC(), ioGrid.GetO().GetS()),
                    sColumnHolder23(ioGrid.GetSO().GetN(), ioGrid.GetSO().GetC(), ioGrid.GetSO().GetS());
    LastCellFinder sLastCellFinder2(sColumnHolder21, sColumnHolder22, sColumnHolder23);
    bFill = sLastCellFinder2.fill();
    bResult = bFill || bResult;
    
    //  Third column
    ColumnHolder    sColumnHolder31(ioGrid.GetNO().GetNE(), ioGrid.GetNO().GetE(), ioGrid.GetNO().GetSE()),
                    sColumnHolder32(ioGrid.GetO().GetNE(), ioGrid.GetO().GetE(), ioGrid.GetO().GetSE()),
                    sColumnHolder33(ioGrid.GetSO().GetNE(), ioGrid.GetSO().GetE(), ioGrid.GetSO().GetSE());
    LastCellFinder sLastCellFinder3(sColumnHolder31, sColumnHolder32, sColumnHolder33);
    bFill = sLastCellFinder3.fill();
    bResult = bFill || bResult;
    
    //  Fourth column
    ColumnHolder    sColumnHolder41(ioGrid.GetN().GetNO(), ioGrid.GetN().GetO(), ioGrid.GetN().GetSO()),
                    sColumnHolder42(ioGrid.GetC().GetNO(), ioGrid.GetC().GetO(), ioGrid.GetC().GetSO()),
                    sColumnHolder43(ioGrid.GetS().GetNO(), ioGrid.GetS().GetO(), ioGrid.GetS().GetSO());
    LastCellFinder sLastCellFinder4(sColumnHolder41, sColumnHolder42, sColumnHolder43);
    bFill = sLastCellFinder4.fill();
    bResult = bFill || bResult;
    
    //  Fifth column
    ColumnHolder    sColumnHolder51(ioGrid.GetN().GetN(), ioGrid.GetN().GetC(), ioGrid.GetN().GetS()),
                    sColumnHolder52(ioGrid.GetC().GetN(), ioGrid.GetC().GetC(), ioGrid.GetC().GetS()),
                    sColumnHolder53(ioGrid.GetS().GetN(), ioGrid.GetS().GetC(), ioGrid.GetS().GetS());
    LastCellFinder sLastCellFinder5(sColumnHolder51, sColumnHolder52, sColumnHolder53);
    bFill = sLastCellFinder5.fill();
    bResult = bFill || bResult;
    
    //  Sixth column
    ColumnHolder    sColumnHolder61(ioGrid.GetN().GetNE(), ioGrid.GetN().GetE(), ioGrid.GetN().GetSE()),
                    sColumnHolder62(ioGrid.GetC().GetNE(), ioGrid.GetC().GetE(), ioGrid.GetC().GetSE()),
                    sColumnHolder63(ioGrid.GetS().GetNE(), ioGrid.GetS().GetE(), ioGrid.GetS().GetSE());
    LastCellFinder sLastCellFinder6(sColumnHolder61, sColumnHolder62, sColumnHolder63);
    bFill = sLastCellFinder6.fill();
    bResult = bFill || bResult;
    
    //  First column
    ColumnHolder    sColumnHolder71(ioGrid.GetNE().GetNO(), ioGrid.GetNE().GetO(), ioGrid.GetNE().GetSO()),
                    sColumnHolder72(ioGrid.GetE().GetNO(), ioGrid.GetE().GetO(), ioGrid.GetE().GetSO()),
                    sColumnHolder73(ioGrid.GetSE().GetNO(), ioGrid.GetSE().GetO(), ioGrid.GetSE().GetSO());
    LastCellFinder sLastCellFinder7(sColumnHolder71, sColumnHolder72, sColumnHolder73);
    bFill = sLastCellFinder7.fill();
    bResult = bFill || bResult;
    
    //  Second column
    ColumnHolder    sColumnHolder81(ioGrid.GetNE().GetN(), ioGrid.GetNE().GetC(), ioGrid.GetNE().GetS()),
                    sColumnHolder82(ioGrid.GetE().GetN(), ioGrid.GetE().GetC(), ioGrid.GetE().GetS()),
                    sColumnHolder83(ioGrid.GetSE().GetN(), ioGrid.GetSE().GetC(), ioGrid.GetSE().GetS());
    LastCellFinder sLastCellFinder8(sColumnHolder81, sColumnHolder82, sColumnHolder83);
    bFill = sLastCellFinder8.fill();
    bResult = bFill || bResult;
    
    //  Third column
    ColumnHolder    sColumnHolder91(ioGrid.GetNE().GetNE(), ioGrid.GetNE().GetE(), ioGrid.GetNE().GetSE()),
                    sColumnHolder92(ioGrid.GetE().GetNE(), ioGrid.GetE().GetE(), ioGrid.GetE().GetSE()),
                    sColumnHolder93(ioGrid.GetSE().GetNE(), ioGrid.GetSE().GetE(), ioGrid.GetSE().GetSE());
    LastCellFinder sLastCellFinder9(sColumnHolder91, sColumnHolder92, sColumnHolder93);
    bFill = sLastCellFinder9.fill();
    bResult = bFill || bResult;
    
    return bResult;
}
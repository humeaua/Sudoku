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
    ColumnHolder    sColumnHolder11 = ioGrid.GetNO().LeftColumn(),
                    sColumnHolder12 = ioGrid.GetO().LeftColumn(),
                    sColumnHolder13 = ioGrid.GetSO().LeftColumn();
    LastCellFinder sLastCellFinder1(sColumnHolder11, sColumnHolder12, sColumnHolder13);
    bool bFill = sLastCellFinder1.fill();
    bResult = bFill || bResult;
    
    //  Second column
    ColumnHolder    sColumnHolder21 = ioGrid.GetNO().MiddleColumn(),
                    sColumnHolder22 = ioGrid.GetO().MiddleColumn(),
                    sColumnHolder23 = ioGrid.GetSO().MiddleColumn();
    LastCellFinder sLastCellFinder2(sColumnHolder21, sColumnHolder22, sColumnHolder23);
    bFill = sLastCellFinder2.fill();
    bResult = bFill || bResult;
    
    //  Third column
    ColumnHolder    sColumnHolder31 = ioGrid.GetNO().RightColumn(),
                    sColumnHolder32 = ioGrid.GetO().RightColumn(),
                    sColumnHolder33 = ioGrid.GetSO().RightColumn();
    LastCellFinder sLastCellFinder3(sColumnHolder31, sColumnHolder32, sColumnHolder33);
    bFill = sLastCellFinder3.fill();
    bResult = bFill || bResult;
    
    //  Fourth column
    ColumnHolder    sColumnHolder41 = ioGrid.GetN().LeftColumn(),
                    sColumnHolder42 = ioGrid.GetC().LeftColumn(),
                    sColumnHolder43 = ioGrid.GetS().LeftColumn();
    LastCellFinder sLastCellFinder4(sColumnHolder41, sColumnHolder42, sColumnHolder43);
    bFill = sLastCellFinder4.fill();
    bResult = bFill || bResult;
    
    //  Fifth column
    ColumnHolder    sColumnHolder51 = ioGrid.GetN().MiddleColumn(),
                    sColumnHolder52 = ioGrid.GetC().MiddleColumn(),
                    sColumnHolder53 = ioGrid.GetS().MiddleColumn();
    LastCellFinder sLastCellFinder5(sColumnHolder51, sColumnHolder52, sColumnHolder53);
    bFill = sLastCellFinder5.fill();
    bResult = bFill || bResult;
    
    //  Sixth column
    ColumnHolder    sColumnHolder61 = ioGrid.GetN().RightColumn(),
                    sColumnHolder62 = ioGrid.GetC().RightColumn(),
                    sColumnHolder63 = ioGrid.GetS().RightColumn();
    LastCellFinder sLastCellFinder6(sColumnHolder61, sColumnHolder62, sColumnHolder63);
    bFill = sLastCellFinder6.fill();
    bResult = bFill || bResult;
    
    //  Seventh column
    ColumnHolder    sColumnHolder71 = ioGrid.GetNE().LeftColumn(),
                    sColumnHolder72 = ioGrid.GetE().LeftColumn(),
                    sColumnHolder73 = ioGrid.GetSE().LeftColumn();
    LastCellFinder sLastCellFinder7(sColumnHolder71, sColumnHolder72, sColumnHolder73);
    bFill = sLastCellFinder7.fill();
    bResult = bFill || bResult;
    
    //  Eighth column
    ColumnHolder    sColumnHolder81 = ioGrid.GetNE().MiddleColumn(),
                    sColumnHolder82 = ioGrid.GetE().MiddleColumn(),
                    sColumnHolder83 = ioGrid.GetSE().MiddleColumn();
    LastCellFinder sLastCellFinder8(sColumnHolder81, sColumnHolder82, sColumnHolder83);
    bFill = sLastCellFinder8.fill();
    bResult = bFill || bResult;
    
    //  Nineth column
    ColumnHolder    sColumnHolder91 = ioGrid.GetNE().RightColumn(),
                    sColumnHolder92 = ioGrid.GetE().RightColumn(),
                    sColumnHolder93 = ioGrid.GetSE().RightColumn(); 
    LastCellFinder sLastCellFinder9(sColumnHolder91, sColumnHolder92, sColumnHolder93);
    bFill = sLastCellFinder9.fill();
    bResult = bFill || bResult;
    
    return bResult;
}
//
//  OnlyOneChoiceInRowVisitor.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 15/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "OnlyOneChoiceInRowVisitor.h"
#include "RowHolder.h"
#include "LastCellFinder.h"
#include "RegionHolder.h"

bool OnlyOneChoiceInRowVisitor::Visit(Grid &ioGrid) const
{
    bool bResult = false;
    //  First line
    RowHolder   sRowHolder11 = ioGrid.GetNO().TopRow(),
                sRowHolder12 = ioGrid.GetN().TopRow(),
                sRowHolder13 = ioGrid.GetNE().TopRow();
    LastCellFinder sLastCellFinder1(sRowHolder11, sRowHolder12, sRowHolder13);
    bool bFill = sLastCellFinder1.fill();
    bResult = bResult || bFill;
    
    //  Second Line
    RowHolder   sRowHolder21 = ioGrid.GetNO().MiddleRow(),
                sRowHolder22 = ioGrid.GetN().MiddleRow(),
                sRowHolder23 = ioGrid.GetNE().MiddleRow();
    LastCellFinder sLastCellFinder2(sRowHolder21, sRowHolder22, sRowHolder23);
    bFill = sLastCellFinder2.fill();
    bResult = bResult || bFill;
    
    //  Third line
    RowHolder   sRowHolder31 = ioGrid.GetNO().BottomRow(),
                sRowHolder32 = ioGrid.GetN().BottomRow(),
                sRowHolder33 = ioGrid.GetNE().BottomRow(); 
    LastCellFinder sLastCellFinder3(sRowHolder31, sRowHolder32, sRowHolder33);
    bFill = sLastCellFinder3.fill();
    bResult = bResult || bFill;
    
    //  Fourth line
    RowHolder   sRowHolder41 = ioGrid.GetO().TopRow(),
                sRowHolder42 = ioGrid.GetC().TopRow(),
                sRowHolder43 = ioGrid.GetE().TopRow();
    LastCellFinder sLastCellFinder4(sRowHolder41, sRowHolder42, sRowHolder43);
    bFill = sLastCellFinder4.fill();
    bResult = bResult || bFill;
    
    //  Fifth Line
    RowHolder   sRowHolder51 = ioGrid.GetO().MiddleRow(),
                sRowHolder52 = ioGrid.GetC().MiddleRow(),
                sRowHolder53 = ioGrid.GetE().MiddleRow();
    LastCellFinder sLastCellFinder5(sRowHolder51, sRowHolder52, sRowHolder53);
    bFill = sLastCellFinder2.fill();
    bResult = bResult || bFill;
    
    //  Sixth line
    RowHolder   sRowHolder61 = ioGrid.GetO().BottomRow(),
                sRowHolder62 = ioGrid.GetC().BottomRow(),
                sRowHolder63 = ioGrid.GetE().BottomRow(); 
    LastCellFinder sLastCellFinder6(sRowHolder61, sRowHolder62, sRowHolder63);
    bFill = sLastCellFinder3.fill();
    bResult = bResult || bFill;
    
    //  Seventh line
    RowHolder   sRowHolder71 = ioGrid.GetSO().TopRow(),
                sRowHolder72 = ioGrid.GetS().TopRow(),
                sRowHolder73 = ioGrid.GetSE().TopRow();
    LastCellFinder sLastCellFinder7(sRowHolder71, sRowHolder72, sRowHolder73);
    bFill = sLastCellFinder1.fill();
    bResult = bResult || bFill;
    
    //  Eighth Line
    RowHolder   sRowHolder81 = ioGrid.GetSO().MiddleRow(),
                sRowHolder82 = ioGrid.GetS().MiddleRow(),
                sRowHolder83 = ioGrid.GetSE().MiddleRow();
    LastCellFinder sLastCellFinder8(sRowHolder81, sRowHolder82, sRowHolder83);
    bFill = sLastCellFinder2.fill();
    bResult = bResult || bFill;
    
    //  Nineth line
    RowHolder   sRowHolder91 = ioGrid.GetSO().BottomRow(),
                sRowHolder92 = ioGrid.GetS().BottomRow(),
                sRowHolder93 = ioGrid.GetSE().BottomRow(); 
    LastCellFinder sLastCellFinder9(sRowHolder91, sRowHolder92, sRowHolder93);
    bFill = sLastCellFinder3.fill();
    bResult = bResult || bFill;

    
    return bResult;
}
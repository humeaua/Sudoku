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
    RowHolder   sRowHolder11(ioGrid.GetNO().GetNO(), ioGrid.GetNO().GetN(), ioGrid.GetNO().GetNE()),
                sRowHolder12(ioGrid.GetN().GetNO(), ioGrid.GetN().GetN(), ioGrid.GetN().GetNE()),
                sRowHolder13(ioGrid.GetNE().GetNO(), ioGrid.GetNE().GetN(), ioGrid.GetNE().GetNE());
    LastCellFinder sLastCellFinder1(sRowHolder11, sRowHolder12, sRowHolder13);
    bool bFill = sLastCellFinder1.fill();
    bResult = bResult || bFill;
    
    //  Second Line
    RowHolder   sRowHolder21(ioGrid.GetNO().GetO(), ioGrid.GetNO().GetC(), ioGrid.GetNO().GetE()),
                sRowHolder22(ioGrid.GetN().GetO(), ioGrid.GetN().GetC(), ioGrid.GetN().GetE()),
                sRowHolder23(ioGrid.GetNE().GetO(), ioGrid.GetNE().GetC(), ioGrid.GetNE().GetE());
    LastCellFinder sLastCellFinder2(sRowHolder21, sRowHolder22, sRowHolder23);
    bFill = sLastCellFinder2.fill();
    bResult = bResult || bFill;
    
    //  Third line
    RowHolder   sRowHolder31(ioGrid.GetNO().GetSO(), ioGrid.GetNO().GetS(), ioGrid.GetNO().GetSE()),
                sRowHolder32(ioGrid.GetN().GetSO(), ioGrid.GetN().GetS(), ioGrid.GetN().GetSE()),
                sRowHolder33(ioGrid.GetNE().GetSO(), ioGrid.GetNE().GetS(), ioGrid.GetNE().GetSE());
    LastCellFinder sLastCellFinder3(sRowHolder31, sRowHolder32, sRowHolder33);
    bFill = sLastCellFinder3.fill();
    bResult = bResult || bFill;
    
    //  Fourth line
    RowHolder   sRowHolder41(ioGrid.GetO().GetNO(), ioGrid.GetO().GetN(), ioGrid.GetO().GetNE()),
                sRowHolder42(ioGrid.GetC().GetNO(), ioGrid.GetC().GetN(), ioGrid.GetC().GetNE()),
                sRowHolder43(ioGrid.GetE().GetNO(), ioGrid.GetE().GetN(), ioGrid.GetE().GetNE());
    LastCellFinder sLastCellFinder4(sRowHolder41, sRowHolder42, sRowHolder43);
    bFill = sLastCellFinder4.fill();
    bResult = bResult || bFill;
    
    //  Fifth Line
    RowHolder   sRowHolder51(ioGrid.GetO().GetO(), ioGrid.GetO().GetC(), ioGrid.GetO().GetE()),
                sRowHolder52(ioGrid.GetC().GetO(), ioGrid.GetC().GetC(), ioGrid.GetC().GetE()),
                sRowHolder53(ioGrid.GetE().GetO(), ioGrid.GetE().GetC(), ioGrid.GetE().GetE());
    LastCellFinder sLastCellFinder5(sRowHolder51, sRowHolder52, sRowHolder53);
    bFill = sLastCellFinder2.fill();
    bResult = bResult || bFill;
    
    //  Sixth line
    RowHolder   sRowHolder61(ioGrid.GetO().GetSO(), ioGrid.GetO().GetS(), ioGrid.GetO().GetSE()),
                sRowHolder62(ioGrid.GetC().GetSO(), ioGrid.GetC().GetS(), ioGrid.GetC().GetSE()),
                sRowHolder63(ioGrid.GetE().GetSO(), ioGrid.GetE().GetS(), ioGrid.GetE().GetSE());
    LastCellFinder sLastCellFinder6(sRowHolder61, sRowHolder62, sRowHolder63);
    bFill = sLastCellFinder3.fill();
    bResult = bResult || bFill;
    
    //  Seventh line
    RowHolder   sRowHolder71(ioGrid.GetSO().GetNO(), ioGrid.GetSO().GetN(), ioGrid.GetSO().GetNE()),
                sRowHolder72(ioGrid.GetS().GetNO(), ioGrid.GetS().GetN(), ioGrid.GetS().GetNE()),
                sRowHolder73(ioGrid.GetSE().GetNO(), ioGrid.GetSE().GetN(), ioGrid.GetSE().GetNE());
    LastCellFinder sLastCellFinder7(sRowHolder71, sRowHolder72, sRowHolder73);
    bFill = sLastCellFinder1.fill();
    bResult = bResult || bFill;
    
    //  Eighth Line
    RowHolder   sRowHolder81(ioGrid.GetSO().GetO(), ioGrid.GetSO().GetC(), ioGrid.GetSO().GetE()),
                sRowHolder82(ioGrid.GetS().GetO(), ioGrid.GetS().GetC(), ioGrid.GetS().GetE()),
                sRowHolder83(ioGrid.GetSE().GetO(), ioGrid.GetSE().GetC(), ioGrid.GetSE().GetE());
    LastCellFinder sLastCellFinder8(sRowHolder81, sRowHolder82, sRowHolder83);
    bFill = sLastCellFinder2.fill();
    bResult = bResult || bFill;
    
    //  Nineth line
    RowHolder   sRowHolder91(ioGrid.GetSO().GetSO(), ioGrid.GetSO().GetS(), ioGrid.GetSO().GetSE()),
                sRowHolder92(ioGrid.GetS().GetSO(), ioGrid.GetS().GetS(), ioGrid.GetS().GetSE()),
                sRowHolder93(ioGrid.GetSE().GetSO(), ioGrid.GetSE().GetS(), ioGrid.GetSE().GetSE());
    LastCellFinder sLastCellFinder9(sRowHolder91, sRowHolder92, sRowHolder93);
    bFill = sLastCellFinder3.fill();
    bResult = bResult || bFill;

    
    return bResult;
}
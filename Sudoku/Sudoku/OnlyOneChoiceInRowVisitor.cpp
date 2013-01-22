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

void OnlyOneChoiceInRowVisitor::MakeRowFromGrid(const Grid &ioGrid, std::map<std::size_t, std::vector<RowHolder> > &sMapOfRow) const
{
    //  This function creates a set of vector of row holder ( = set of rows ) from a specified grid
    std::vector<RowHolder> sVectorOfRowHolder;
    RegionHolder    sNO = ioGrid.GetNO(),
                    sN = ioGrid.GetN(),
                    sNE = ioGrid.GetNE(),
                    sO = ioGrid.GetO(),
                    sC = ioGrid.GetC(),
                    sE = ioGrid.GetE(),
                    sSO = ioGrid.GetSO(),
                    sS = ioGrid.GetS(),
                    sSE = ioGrid.GetSE();
    
    sVectorOfRowHolder.push_back(sNO.TopRow());
    sVectorOfRowHolder.push_back(sN.TopRow());
    sVectorOfRowHolder.push_back(sNE.TopRow());
    
    sMapOfRow[0] = sVectorOfRowHolder;
    sVectorOfRowHolder.clear();
    
    sVectorOfRowHolder.push_back(sNO.MiddleRow());
    sVectorOfRowHolder.push_back(sN.MiddleRow());
    sVectorOfRowHolder.push_back(sNE.MiddleRow());
    
    sMapOfRow[1] = sVectorOfRowHolder;
    sVectorOfRowHolder.clear();
    
    sVectorOfRowHolder.push_back(sNO.BottomRow());
    sVectorOfRowHolder.push_back(sN.BottomRow());
    sVectorOfRowHolder.push_back(sNE.BottomRow());
    
    sMapOfRow[2] = sVectorOfRowHolder;
    sVectorOfRowHolder.clear();
    
    sVectorOfRowHolder.push_back(sO.TopRow());
    sVectorOfRowHolder.push_back(sC.TopRow());
    sVectorOfRowHolder.push_back(sE.TopRow());
    
    sMapOfRow[3] = sVectorOfRowHolder;
    sVectorOfRowHolder.clear();
    
    sVectorOfRowHolder.push_back(sO.MiddleRow());
    sVectorOfRowHolder.push_back(sC.MiddleRow());
    sVectorOfRowHolder.push_back(sE.MiddleRow());
    
    sMapOfRow[4] = sVectorOfRowHolder;
    sVectorOfRowHolder.clear();
    
    sVectorOfRowHolder.push_back(sO.BottomRow());
    sVectorOfRowHolder.push_back(sC.BottomRow());
    sVectorOfRowHolder.push_back(sE.BottomRow());
    
    sMapOfRow[5] = sVectorOfRowHolder;
    sVectorOfRowHolder.clear();
    
    sVectorOfRowHolder.push_back(sSO.TopRow());
    sVectorOfRowHolder.push_back(sS.TopRow());
    sVectorOfRowHolder.push_back(sSE.TopRow());
    
    sMapOfRow[6] = sVectorOfRowHolder;
    sVectorOfRowHolder.clear();
    
    sVectorOfRowHolder.push_back(sSO.MiddleRow());
    sVectorOfRowHolder.push_back(sS.MiddleRow());
    sVectorOfRowHolder.push_back(sSE.MiddleRow());
    
    sMapOfRow[6] = sVectorOfRowHolder;
    sVectorOfRowHolder.clear();
    
    sVectorOfRowHolder.push_back(sSO.MiddleRow());
    sVectorOfRowHolder.push_back(sS.MiddleRow());
    sVectorOfRowHolder.push_back(sSE.MiddleRow());
    
    sMapOfRow[6] = sVectorOfRowHolder;
    sVectorOfRowHolder.clear();

}

bool OnlyOneChoiceInRowVisitor::Visit(const Grid &ioGrid) const
{
    std::map<std::size_t, std::vector<RowHolder> > sMapofRowsinGrid;
    bool bResult = false;
    MakeRowFromGrid(ioGrid, sMapofRowsinGrid);
    
    for (std::map<std::size_t, std::vector<RowHolder> >::iterator itRow = sMapofRowsinGrid.begin() ; itRow != sMapofRowsinGrid.end() ; ++itRow)
    {
        LastCellFinder sLastCellFinder(itRow->second[0], itRow->second[1], itRow->second[2]);
        bool bFill = sLastCellFinder.fill();
        bResult = bResult || bFill;
    }
    return bResult;
}
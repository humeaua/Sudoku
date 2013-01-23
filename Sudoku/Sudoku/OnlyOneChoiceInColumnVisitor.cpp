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

/*void OnlyOneChoiceInColumnVisitor::MakeColumnFromGrid(const Grid &ioGrid, std::map<std::size_t, std::vector<ColumnHolder> > &sMapOfColumn) const
{
    //  This function creates a set of vector of row holder ( = set of rows ) from a specified grid
    std::vector<ColumnHolder> sVectorOfColumnHolder;
    RegionHolder    sNO = ioGrid.GetNO(),
                    sN = ioGrid.GetN(),
                    sNE = ioGrid.GetNE(),
                    sO = ioGrid.GetO(),
                    sC = ioGrid.GetC(),
                    sE = ioGrid.GetE(),
                    sSO = ioGrid.GetSO(),
                    sS = ioGrid.GetS(),
                    sSE = ioGrid.GetSE();
    
    sVectorOfColumnHolder.push_back(sNO.LeftColumn());
    sVectorOfColumnHolder.push_back(sO.LeftColumn());
    sVectorOfColumnHolder.push_back(sSO.LeftColumn());
    
    sMapOfColumn[0] = sVectorOfColumnHolder;
    sVectorOfColumnHolder.clear();
    
    sVectorOfColumnHolder.push_back(sNO.MiddleColumn());
    sVectorOfColumnHolder.push_back(sO.MiddleColumn());
    sVectorOfColumnHolder.push_back(sSO.MiddleColumn());
    
    sMapOfColumn[1] = sVectorOfColumnHolder;
    sVectorOfColumnHolder.clear();
    
    sVectorOfColumnHolder.push_back(sNO.RightColumn());
    sVectorOfColumnHolder.push_back(sO.RightColumn());
    sVectorOfColumnHolder.push_back(sSO.RightColumn());
    
    sMapOfColumn[2] = sVectorOfColumnHolder;
    sVectorOfColumnHolder.clear();
    
    sVectorOfColumnHolder.push_back(sN.LeftColumn());
    sVectorOfColumnHolder.push_back(sC.LeftColumn());
    sVectorOfColumnHolder.push_back(sS.LeftColumn());
    
    sMapOfColumn[3] = sVectorOfColumnHolder;
    sVectorOfColumnHolder.clear();
    
    sVectorOfColumnHolder.push_back(sN.MiddleColumn());
    sVectorOfColumnHolder.push_back(sC.MiddleColumn());
    sVectorOfColumnHolder.push_back(sS.MiddleColumn());
    
    sMapOfColumn[4] = sVectorOfColumnHolder;
    sVectorOfColumnHolder.clear();
    
    sVectorOfColumnHolder.push_back(sN.RightColumn());
    sVectorOfColumnHolder.push_back(sC.RightColumn());
    sVectorOfColumnHolder.push_back(sS.RightColumn());
    
    sMapOfColumn[5] = sVectorOfColumnHolder;
    sVectorOfColumnHolder.clear();
    
    sVectorOfColumnHolder.push_back(sNE.LeftColumn());
    sVectorOfColumnHolder.push_back(sE.LeftColumn());
    sVectorOfColumnHolder.push_back(sSE.LeftColumn());
    
    sMapOfColumn[6] = sVectorOfColumnHolder;
    sVectorOfColumnHolder.clear();
    
    sVectorOfColumnHolder.push_back(sNE.MiddleColumn());
    sVectorOfColumnHolder.push_back(sE.MiddleColumn());
    sVectorOfColumnHolder.push_back(sSE.MiddleColumn());
    
    sMapOfColumn[7] = sVectorOfColumnHolder;
    sVectorOfColumnHolder.clear();
    
    sVectorOfColumnHolder.push_back(sNE.RightColumn());
    sVectorOfColumnHolder.push_back(sE.RightColumn());
    sVectorOfColumnHolder.push_back(sSE.RightColumn());
    
    sMapOfColumn[8] = sVectorOfColumnHolder;
    sVectorOfColumnHolder.clear();
}

bool OnlyOneChoiceInColumnVisitor::Visit(const Grid &ioGrid) const
{
    std::map<std::size_t, std::vector<ColumnHolder> > sMapofColumninGrid;
    bool bResult = false;
    MakeColumnFromGrid(ioGrid, sMapofColumninGrid);
    
    for (std::map<std::size_t, std::vector<ColumnHolder> >::iterator itRow = sMapofColumninGrid.begin() ; itRow != sMapofColumninGrid.end() ; ++itRow)
    {
        LastCellFinder sLastCellFinder(itRow->second[0], itRow->second[1], itRow->second[2]);
        bool bFill = sLastCellFinder.fill();
        bResult = bFill || bResult;
    }
    return bResult;
}*/
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

void OnlyOneChoiceInRowVisitor::MakeRowFromGrid(const Grid &ioGrid, std::map<std::size_t, std::vector<RowHolder> > &sMapOfRow) const
{
    //  This function creates a set of vector of row holder ( = set of rows ) from a specified grid
    std::vector<RowHolder> sVectorOfRowHolder;
    
    
    sVectorOfRowHolder.clear();
}

bool OnlyOneChoiceInRowVisitor::Visit(const Grid &ioGrid) const
{
    std::map<std::size_t, std::vector<RowHolder> > sMapofRowsinGrid;
    
    MakeRowFromGrid(ioGrid, sMapofRowsinGrid);
    
    for (std::map<std::size_t, std::vector<RowHolder> >::iterator itRow = sMapofRowsinGrid.begin() ; itRow != sMapofRowsinGrid.end() ; ++itRow)
    {
        LastCellFinder sLastCellFinder(itRow->second[0], itRow->second[1], itRow->second[2]);
        sLastCellFinder.fill();
    }
    return true;
}
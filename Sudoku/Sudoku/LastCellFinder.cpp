//
//  LastCellFinder.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 10/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "LastCellFinder.h"

LastCellFinder::LastCellFinder(const TripleHolder & s1, const TripleHolder & s2, const TripleHolder & s3) : s1_(s1), s2_(s2), s3_(s3)
{}

// We introduce a base method for lastCellfinder
std::pair<std::vector<unsigned int>, std::vector<unsigned int> > LastCellFinder::EmptyCells()
{
    std::vector<unsigned int> iCells, iEmptyCells;
    if (!s1_.GetLeft().IsEmpty())
    {
        iCells.push_back(s1_.GetLeft());
        iEmptyCells.push_back(1);
    }
    if (!s1_.GetCenter().IsEmpty())
    {
        iCells.push_back(s1_.GetCenter());
        iEmptyCells.push_back(2);
    }
    if (!s1_.GetRight().IsEmpty())
    {
        iCells.push_back(s1_.GetRight());
        iEmptyCells.push_back(3);
    }
    if (!s2_.GetLeft().IsEmpty())
    {
        iCells.push_back(s2_.GetLeft());
        
        iEmptyCells.push_back(4);
    }
    if (!s2_.GetCenter().IsEmpty())
    {
        iCells.push_back(s2_.GetCenter());
        iEmptyCells.push_back(5);
    }
    if (!s2_.GetRight().IsEmpty())
    {
        iCells.push_back(s2_.GetRight());
        
        iEmptyCells.push_back(6);
    }
    if (!s3_.GetLeft().IsEmpty())
    {
        iCells.push_back(s3_.GetLeft());
        
        iEmptyCells.push_back(7);
    }
    if (!s3_.GetCenter().IsEmpty())
    {
        iCells.push_back(s3_.GetCenter());
        
        iEmptyCells.push_back(8);
    }
    if (!s3_.GetRight().IsEmpty())
    {
        iCells.push_back(s3_.GetRight());
        
        iEmptyCells.push_back(9);
    }
    return std::make_pair(iEmptyCells, iCells);
}

bool LastCellFinder::fill()
{
    std::pair<std::vector<unsigned int>, std::vector<unsigned int> > EmptyCellsAndCellValues = EmptyCells();
    unsigned long iNbEmptyCells = EmptyCellsAndCellValues.first.size();
    //  If the number of empty cells is 0 or more than 2 we cannot fill the LastCellFinder
    if (iNbEmptyCells == 0 || iNbEmptyCells > 1)
    {
        return false;
    }
    std::sort(EmptyCellsAndCellValues.second.begin(), EmptyCellsAndCellValues.second.end());
    unsigned int iMissingValue = 0;
    if (EmptyCellsAndCellValues.second[0] == 2)
    {
        iMissingValue = 1;
        goto AFFECT;
    }
    for (std::size_t i = 1 ; i < EmptyCellsAndCellValues.second.size() ; ++i)
    {
        if (EmptyCellsAndCellValues.second[i] - EmptyCellsAndCellValues.second[i - 1] > 1)
        {
            iMissingValue = EmptyCellsAndCellValues.second[i - 1] + 1;
            goto AFFECT;
        }
    }
    iMissingValue = 9;
AFFECT:
    switch (EmptyCellsAndCellValues.first[0]) {
        case 1:
            s1_.GetLeft() = iMissingValue;
            break;
            
        case 2:
            s1_.GetCenter() = iMissingValue;
            break;
            
        case 3:
            s1_.GetRight() = iMissingValue;
            break;
            
        case 4:
            s2_.GetLeft() = iMissingValue;
            break;
            
        case 5:
            s2_.GetCenter() = iMissingValue;
            break;
            
        case 6:
            s2_.GetRight() = iMissingValue;
            break;
            
        case 7:
            s3_.GetLeft() = iMissingValue;
            break;
            
        case 8:
            s3_.GetCenter() = iMissingValue;
            break;
            
        case 9:
            s3_.GetRight() = iMissingValue;
            break;
            
        default:
            return false;
            break;
    }
    return true;
}
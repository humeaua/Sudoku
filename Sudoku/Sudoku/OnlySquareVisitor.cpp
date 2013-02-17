//
//  OnlySquareVisitor.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 27/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "OnlySquareVisitor.h"

bool OnlySquareVisitor::Visit(Grid &ioGrid) const
{
    bool bResult = false;
    //  First line
    RowHolder   sRowHolder11 = ioGrid.GetNO().TopRow(),
                sRowHolder12 = ioGrid.GetN().TopRow(),
                sRowHolder13 = ioGrid.GetNE().TopRow();
    
    std::vector<int>    EmptyCellsRow11 = sRowHolder11.indexEmpty(),
                        EmptyCellsRow12 = sRowHolder12.indexEmpty(),
                        EmptyCellsRow13 = sRowHolder13.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsRow12.size() ; ++i)
    {
        EmptyCellsRow11.push_back( EmptyCellsRow12[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsRow13.size() ; ++i)
    {
        EmptyCellsRow11.push_back( EmptyCellsRow13[i] + 6);
    }
    
    if (EmptyCellsRow11.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sRowHolder11.flagValues(sValueEliminator);
        sRowHolder12.flagValues(sValueEliminator);
        sRowHolder13.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow11[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsRow11[0]) 
            {
                case 1:
                    sRowHolder11.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sRowHolder11.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sRowHolder11.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sRowHolder12.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sRowHolder12.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sRowHolder12.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sRowHolder13.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sRowHolder13.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sRowHolder13.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsRow11[1]) 
            {
                case 1:
                    sRowHolder11.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sRowHolder11.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sRowHolder11.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sRowHolder12.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sRowHolder12.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sRowHolder12.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sRowHolder13.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sRowHolder13.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sRowHolder13.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow11[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsRow11[0]) 
                {
                    case 1:
                        sRowHolder11.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sRowHolder11.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sRowHolder11.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sRowHolder12.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sRowHolder12.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sRowHolder12.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sRowHolder13.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sRowHolder13.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sRowHolder13.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsRow11[1]) 
                {
                    case 1:
                        sRowHolder11.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sRowHolder11.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sRowHolder11.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sRowHolder12.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sRowHolder12.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sRowHolder12.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sRowHolder13.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sRowHolder13.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sRowHolder13.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
   
    //  Second Line
    RowHolder   sRowHolder21 = ioGrid.GetNO().MiddleRow(),
    sRowHolder22 = ioGrid.GetN().MiddleRow(),
    sRowHolder23 = ioGrid.GetNE().MiddleRow();
    
    std::vector<int>    EmptyCellsRow21 = sRowHolder21.indexEmpty(),
    EmptyCellsRow22 = sRowHolder22.indexEmpty(),
    EmptyCellsRow23 = sRowHolder23.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsRow22.size() ; ++i)
    {
        EmptyCellsRow21.push_back( EmptyCellsRow22[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsRow13.size() ; ++i)
    {
        EmptyCellsRow21.push_back( EmptyCellsRow23[i] + 6);
    }
    
    if (EmptyCellsRow21.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sRowHolder21.flagValues(sValueEliminator);
        sRowHolder22.flagValues(sValueEliminator);
        sRowHolder23.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow21[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsRow21[0]) 
            {
                case 1:
                    sRowHolder21.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sRowHolder21.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sRowHolder21.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sRowHolder22.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sRowHolder22.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sRowHolder22.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sRowHolder23.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sRowHolder23.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sRowHolder23.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsRow21[1]) 
            {
                case 1:
                    sRowHolder21.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sRowHolder21.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sRowHolder21.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sRowHolder22.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sRowHolder22.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sRowHolder22.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sRowHolder23.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sRowHolder23.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sRowHolder23.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow21[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsRow21[0]) 
                {
                    case 1:
                        sRowHolder21.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sRowHolder21.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sRowHolder21.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sRowHolder22.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sRowHolder22.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sRowHolder22.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sRowHolder23.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sRowHolder23.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sRowHolder23.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsRow21[1]) 
                {
                    case 1:
                        sRowHolder21.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sRowHolder21.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sRowHolder21.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sRowHolder22.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sRowHolder22.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sRowHolder22.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sRowHolder23.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sRowHolder23.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sRowHolder23.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Third line
    RowHolder   sRowHolder31 = ioGrid.GetNO().BottomRow(),
    sRowHolder32 = ioGrid.GetN().BottomRow(),
    sRowHolder33 = ioGrid.GetNE().BottomRow(); 
    
    std::vector<int>    EmptyCellsRow31 = sRowHolder31.indexEmpty(),
    EmptyCellsRow32 = sRowHolder32.indexEmpty(),
    EmptyCellsRow33 = sRowHolder33.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsRow32.size() ; ++i)
    {
        EmptyCellsRow31.push_back( EmptyCellsRow32[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsRow33.size() ; ++i)
    {
        EmptyCellsRow31.push_back( EmptyCellsRow33[i] + 6);
    }
    
    if (EmptyCellsRow31.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sRowHolder31.flagValues(sValueEliminator);
        sRowHolder32.flagValues(sValueEliminator);
        sRowHolder33.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow31[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsRow31[0]) 
            {
                case 1:
                    sRowHolder31.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sRowHolder31.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sRowHolder31.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sRowHolder32.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sRowHolder32.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sRowHolder32.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sRowHolder33.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sRowHolder33.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sRowHolder33.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsRow31[1]) 
            {
                case 1:
                    sRowHolder31.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sRowHolder31.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sRowHolder31.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sRowHolder32.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sRowHolder32.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sRowHolder32.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sRowHolder33.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sRowHolder33.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sRowHolder33.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow31[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsRow31[0]) 
                {
                    case 1:
                        sRowHolder31.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sRowHolder31.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sRowHolder31.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sRowHolder32.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sRowHolder32.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sRowHolder32.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sRowHolder33.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sRowHolder33.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sRowHolder33.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsRow31[1]) 
                {
                    case 1:
                        sRowHolder31.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sRowHolder31.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sRowHolder31.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sRowHolder32.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sRowHolder32.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sRowHolder32.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sRowHolder33.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sRowHolder33.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sRowHolder33.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Fourth line
    RowHolder   sRowHolder41 = ioGrid.GetO().TopRow(),
    sRowHolder42 = ioGrid.GetC().TopRow(),
    sRowHolder43 = ioGrid.GetE().TopRow();
    
    std::vector<int>    EmptyCellsRow41 = sRowHolder41.indexEmpty(),
    EmptyCellsRow42 = sRowHolder42.indexEmpty(),
    EmptyCellsRow43 = sRowHolder43.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsRow42.size() ; ++i)
    {
        EmptyCellsRow41.push_back( EmptyCellsRow42[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsRow43.size() ; ++i)
    {
        EmptyCellsRow41.push_back( EmptyCellsRow43[i] + 6);
    }
    
    if (EmptyCellsRow41.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sRowHolder41.flagValues(sValueEliminator);
        sRowHolder42.flagValues(sValueEliminator);
        sRowHolder43.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow41[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsRow41[0]) 
            {
                case 1:
                    sRowHolder41.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sRowHolder41.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sRowHolder41.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sRowHolder42.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sRowHolder42.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sRowHolder42.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sRowHolder43.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sRowHolder43.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sRowHolder43.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsRow41[1]) 
            {
                case 1:
                    sRowHolder41.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sRowHolder41.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sRowHolder41.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sRowHolder42.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sRowHolder42.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sRowHolder42.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sRowHolder43.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sRowHolder43.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sRowHolder43.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow41[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsRow41[0]) 
                {
                    case 1:
                        sRowHolder41.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sRowHolder41.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sRowHolder41.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sRowHolder42.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sRowHolder42.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sRowHolder42.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sRowHolder43.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sRowHolder43.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sRowHolder43.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsRow41[1]) 
                {
                    case 1:
                        sRowHolder41.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sRowHolder41.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sRowHolder41.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sRowHolder42.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sRowHolder42.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sRowHolder42.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sRowHolder43.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sRowHolder43.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sRowHolder43.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Fifth Line
    RowHolder   sRowHolder51 = ioGrid.GetO().MiddleRow(),
    sRowHolder52 = ioGrid.GetC().MiddleRow(),
    sRowHolder53 = ioGrid.GetE().MiddleRow();
    
    std::vector<int>    EmptyCellsRow51 = sRowHolder51.indexEmpty(),
    EmptyCellsRow52 = sRowHolder52.indexEmpty(),
    EmptyCellsRow53 = sRowHolder53.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsRow52.size() ; ++i)
    {
        EmptyCellsRow51.push_back( EmptyCellsRow52[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsRow53.size() ; ++i)
    {
        EmptyCellsRow51.push_back( EmptyCellsRow53[i] + 6);
    }
    
    if (EmptyCellsRow51.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sRowHolder51.flagValues(sValueEliminator);
        sRowHolder52.flagValues(sValueEliminator);
        sRowHolder53.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow51[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsRow51[0]) 
            {
                case 1:
                    sRowHolder51.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sRowHolder51.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sRowHolder51.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sRowHolder52.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sRowHolder52.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sRowHolder52.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sRowHolder53.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sRowHolder53.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sRowHolder53.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsRow51[1]) 
            {
                case 1:
                    sRowHolder51.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sRowHolder51.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sRowHolder51.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sRowHolder52.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sRowHolder52.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sRowHolder52.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sRowHolder53.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sRowHolder53.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sRowHolder53.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow51[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsRow51[0]) 
                {
                    case 1:
                        sRowHolder51.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sRowHolder51.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sRowHolder51.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sRowHolder52.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sRowHolder52.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sRowHolder52.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sRowHolder53.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sRowHolder53.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sRowHolder53.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsRow51[1]) 
                {
                    case 1:
                        sRowHolder51.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sRowHolder51.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sRowHolder51.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sRowHolder52.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sRowHolder52.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sRowHolder52.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sRowHolder53.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sRowHolder53.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sRowHolder53.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Sixth line
    RowHolder   sRowHolder61 = ioGrid.GetO().BottomRow(),
    sRowHolder62 = ioGrid.GetC().BottomRow(),
    sRowHolder63 = ioGrid.GetE().BottomRow(); 
    
    std::vector<int>    EmptyCellsRow61 = sRowHolder61.indexEmpty(),
    EmptyCellsRow62 = sRowHolder62.indexEmpty(),
    EmptyCellsRow63 = sRowHolder63.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsRow62.size() ; ++i)
    {
        EmptyCellsRow61.push_back( EmptyCellsRow62[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsRow63.size() ; ++i)
    {
        EmptyCellsRow61.push_back( EmptyCellsRow63[i] + 6);
    }
    
    if (EmptyCellsRow61.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sRowHolder61.flagValues(sValueEliminator);
        sRowHolder62.flagValues(sValueEliminator);
        sRowHolder63.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow61[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsRow61[0]) 
            {
                case 1:
                    sRowHolder61.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sRowHolder61.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sRowHolder61.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sRowHolder62.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sRowHolder62.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sRowHolder62.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sRowHolder63.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sRowHolder63.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sRowHolder63.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsRow61[1]) 
            {
                case 1:
                    sRowHolder61.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sRowHolder61.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sRowHolder61.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sRowHolder62.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sRowHolder62.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sRowHolder62.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sRowHolder63.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sRowHolder63.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sRowHolder63.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow61[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsRow61[0]) 
                {
                    case 1:
                        sRowHolder61.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sRowHolder61.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sRowHolder61.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sRowHolder62.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sRowHolder62.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sRowHolder62.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sRowHolder63.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sRowHolder63.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sRowHolder63.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsRow61[1]) 
                {
                    case 1:
                        sRowHolder61.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sRowHolder61.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sRowHolder61.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sRowHolder62.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sRowHolder62.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sRowHolder62.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sRowHolder63.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sRowHolder63.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sRowHolder63.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Seventh line
    RowHolder   sRowHolder71 = ioGrid.GetSO().TopRow(),
    sRowHolder72 = ioGrid.GetS().TopRow(),
    sRowHolder73 = ioGrid.GetSE().TopRow();
    
    std::vector<int>    EmptyCellsRow71 = sRowHolder71.indexEmpty(),
    EmptyCellsRow72 = sRowHolder72.indexEmpty(),
    EmptyCellsRow73 = sRowHolder73.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsRow72.size() ; ++i)
    {
        EmptyCellsRow71.push_back( EmptyCellsRow72[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsRow73.size() ; ++i)
    {
        EmptyCellsRow71.push_back( EmptyCellsRow73[i] + 6);
    }
    
    if (EmptyCellsRow71.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sRowHolder71.flagValues(sValueEliminator);
        sRowHolder72.flagValues(sValueEliminator);
        sRowHolder73.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow71[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsRow71[0]) 
            {
                case 1:
                    sRowHolder71.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sRowHolder71.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sRowHolder71.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sRowHolder72.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sRowHolder72.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sRowHolder72.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sRowHolder73.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sRowHolder73.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sRowHolder73.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsRow71[1]) 
            {
                case 1:
                    sRowHolder71.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sRowHolder71.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sRowHolder71.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sRowHolder72.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sRowHolder72.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sRowHolder72.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sRowHolder73.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sRowHolder73.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sRowHolder73.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow71[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsRow71[0]) 
                {
                    case 1:
                        sRowHolder71.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sRowHolder71.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sRowHolder71.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sRowHolder72.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sRowHolder72.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sRowHolder72.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sRowHolder73.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sRowHolder73.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sRowHolder73.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsRow71[1]) 
                {
                    case 1:
                        sRowHolder71.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sRowHolder71.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sRowHolder71.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sRowHolder72.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sRowHolder72.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sRowHolder72.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sRowHolder73.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sRowHolder73.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sRowHolder73.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Eighth Line
    RowHolder   sRowHolder81 = ioGrid.GetSO().MiddleRow(),
    sRowHolder82 = ioGrid.GetS().MiddleRow(),
    sRowHolder83 = ioGrid.GetSE().MiddleRow();
    
    std::vector<int>    EmptyCellsRow81 = sRowHolder81.indexEmpty(),
    EmptyCellsRow82 = sRowHolder82.indexEmpty(),
    EmptyCellsRow83 = sRowHolder83.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsRow82.size() ; ++i)
    {
        EmptyCellsRow81.push_back( EmptyCellsRow82[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsRow13.size() ; ++i)
    {
        EmptyCellsRow81.push_back( EmptyCellsRow83[i] + 6);
    }
    
    if (EmptyCellsRow81.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sRowHolder81.flagValues(sValueEliminator);
        sRowHolder82.flagValues(sValueEliminator);
        sRowHolder83.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow81[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsRow81[0]) 
            {
                case 1:
                    sRowHolder81.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sRowHolder81.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sRowHolder81.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sRowHolder82.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sRowHolder82.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sRowHolder82.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sRowHolder83.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sRowHolder83.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sRowHolder83.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsRow81[1]) 
            {
                case 1:
                    sRowHolder81.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sRowHolder81.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sRowHolder81.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sRowHolder82.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sRowHolder82.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sRowHolder82.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sRowHolder83.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sRowHolder83.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sRowHolder83.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow81[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsRow81[0]) 
                {
                    case 1:
                        sRowHolder81.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sRowHolder81.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sRowHolder81.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sRowHolder82.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sRowHolder82.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sRowHolder82.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sRowHolder83.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sRowHolder83.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sRowHolder83.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsRow81[1]) 
                {
                    case 1:
                        sRowHolder81.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sRowHolder81.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sRowHolder81.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sRowHolder82.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sRowHolder82.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sRowHolder82.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sRowHolder83.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sRowHolder83.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sRowHolder83.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Nineth line
    RowHolder   sRowHolder91 = ioGrid.GetSO().BottomRow(),
    sRowHolder92 = ioGrid.GetS().BottomRow(),
    sRowHolder93 = ioGrid.GetSE().BottomRow(); 
    
    std::vector<int>    EmptyCellsRow91 = sRowHolder91.indexEmpty(),
    EmptyCellsRow92 = sRowHolder92.indexEmpty(),
    EmptyCellsRow93 = sRowHolder93.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsRow92.size() ; ++i)
    {
        EmptyCellsRow91.push_back( EmptyCellsRow92[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsRow93.size() ; ++i)
    {
        EmptyCellsRow91.push_back( EmptyCellsRow93[i] + 6);
    }
    
    if (EmptyCellsRow91.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sRowHolder91.flagValues(sValueEliminator);
        sRowHolder92.flagValues(sValueEliminator);
        sRowHolder93.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow91[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsRow91[0]) 
            {
                case 1:
                    sRowHolder91.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sRowHolder91.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sRowHolder91.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sRowHolder92.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sRowHolder92.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sRowHolder92.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sRowHolder93.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sRowHolder93.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sRowHolder93.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsRow91[1]) 
            {
                case 1:
                    sRowHolder91.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sRowHolder91.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sRowHolder91.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sRowHolder92.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sRowHolder92.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sRowHolder92.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sRowHolder93.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sRowHolder93.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sRowHolder93.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsRow91[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsRow91[0]) 
                {
                    case 1:
                        sRowHolder91.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sRowHolder91.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sRowHolder91.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sRowHolder92.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sRowHolder92.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sRowHolder92.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sRowHolder93.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sRowHolder93.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sRowHolder93.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsRow91[1]) 
                {
                    case 1:
                        sRowHolder91.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sRowHolder91.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sRowHolder91.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sRowHolder92.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sRowHolder92.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sRowHolder92.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sRowHolder93.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sRowHolder93.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sRowHolder93.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Same with Column Holder
    //  First column
    ColumnHolder    sColumnHolder11 = ioGrid.GetNO().LeftColumn(),
    sColumnHolder12 = ioGrid.GetO().LeftColumn(),
    sColumnHolder13 = ioGrid.GetSO().LeftColumn();
    
    std::vector<int>    EmptyCellsCol11 = sColumnHolder11.indexEmpty(),
    EmptyCellsCol12 = sColumnHolder12.indexEmpty(),
    EmptyCellsCol13 = sColumnHolder13.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsCol12.size() ; ++i)
    {
        EmptyCellsCol11.push_back( EmptyCellsCol12[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsCol13.size() ; ++i)
    {
        EmptyCellsCol11.push_back( EmptyCellsCol13[i] + 6);
    }
    
    if (EmptyCellsCol11.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sColumnHolder11.flagValues(sValueEliminator);
        sColumnHolder12.flagValues(sValueEliminator);
        sColumnHolder13.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol11[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsCol11[0]) 
            {
                case 1:
                    sColumnHolder11.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sColumnHolder11.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sColumnHolder11.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sColumnHolder12.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sColumnHolder12.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sColumnHolder12.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sColumnHolder13.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sColumnHolder13.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sColumnHolder13.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsCol11[1]) 
            {
                case 1:
                    sColumnHolder11.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sColumnHolder11.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sColumnHolder11.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sColumnHolder12.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sColumnHolder12.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sColumnHolder12.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sColumnHolder13.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sColumnHolder13.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sColumnHolder13.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol11[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsCol11[0]) 
                {
                    case 1:
                        sColumnHolder11.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sColumnHolder11.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sColumnHolder11.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sColumnHolder12.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sColumnHolder12.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sColumnHolder12.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sColumnHolder13.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sColumnHolder13.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sColumnHolder13.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsCol11[1]) 
                {
                    case 1:
                        sColumnHolder11.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sColumnHolder11.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sColumnHolder11.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sColumnHolder12.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sColumnHolder12.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sColumnHolder12.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sColumnHolder13.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sColumnHolder13.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sColumnHolder13.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Second column
    ColumnHolder    sColumnHolder21 = ioGrid.GetNO().MiddleColumn(),
    sColumnHolder22 = ioGrid.GetO().MiddleColumn(),
    sColumnHolder23 = ioGrid.GetSO().MiddleColumn();
    
    std::vector<int>    EmptyCellsCol21 = sColumnHolder21.indexEmpty(),
    EmptyCellsCol22 = sColumnHolder22.indexEmpty(),
    EmptyCellsCol23 = sColumnHolder21.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsCol22.size() ; ++i)
    {
        EmptyCellsCol21.push_back( EmptyCellsCol22[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsCol23.size() ; ++i)
    {
        EmptyCellsCol21.push_back( EmptyCellsCol23[i] + 6);
    }
    
    if (EmptyCellsCol21.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sColumnHolder21.flagValues(sValueEliminator);
        sColumnHolder22.flagValues(sValueEliminator);
        sColumnHolder23.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol21[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsCol21[0]) 
            {
                case 1:
                    sColumnHolder21.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sColumnHolder21.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sColumnHolder21.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sColumnHolder22.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sColumnHolder22.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sColumnHolder22.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sColumnHolder23.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sColumnHolder23.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sColumnHolder23.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsCol21[1]) 
            {
                case 1:
                    sColumnHolder21.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sColumnHolder21.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sColumnHolder21.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sColumnHolder22.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sColumnHolder22.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sColumnHolder22.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sColumnHolder23.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sColumnHolder23.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sColumnHolder23.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol21[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsCol21[0]) 
                {
                    case 1:
                        sColumnHolder21.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sColumnHolder21.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sColumnHolder21.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sColumnHolder22.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sColumnHolder22.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sColumnHolder22.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sColumnHolder23.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sColumnHolder23.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sColumnHolder23.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsCol21[1]) 
                {
                    case 1:
                        sColumnHolder21.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sColumnHolder21.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sColumnHolder21.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sColumnHolder22.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sColumnHolder22.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sColumnHolder22.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sColumnHolder23.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sColumnHolder23.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sColumnHolder23.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }

    //  Third column
    ColumnHolder    sColumnHolder31 = ioGrid.GetNO().RightColumn(),
    sColumnHolder32 = ioGrid.GetO().RightColumn(),
    sColumnHolder33 = ioGrid.GetSO().RightColumn();
    
    std::vector<int>    EmptyCellsCol31 = sColumnHolder31.indexEmpty(),
    EmptyCellsCol32 = sColumnHolder32.indexEmpty(),
    EmptyCellsCol33 = sColumnHolder31.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsCol32.size() ; ++i)
    {
        EmptyCellsCol31.push_back( EmptyCellsCol32[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsCol33.size() ; ++i)
    {
        EmptyCellsCol31.push_back( EmptyCellsCol33[i] + 6);
    }
    
    if (EmptyCellsCol31.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sColumnHolder31.flagValues(sValueEliminator);
        sColumnHolder32.flagValues(sValueEliminator);
        sColumnHolder33.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol31[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsCol31[0]) 
            {
                case 1:
                    sColumnHolder31.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sColumnHolder31.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sColumnHolder31.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sColumnHolder32.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sColumnHolder32.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sColumnHolder32.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sColumnHolder33.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sColumnHolder33.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sColumnHolder33.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsCol31[1]) 
            {
                case 1:
                    sColumnHolder31.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sColumnHolder31.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sColumnHolder31.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sColumnHolder32.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sColumnHolder32.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sColumnHolder32.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sColumnHolder33.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sColumnHolder33.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sColumnHolder33.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol31[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsCol31[0]) 
                {
                    case 1:
                        sColumnHolder31.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sColumnHolder31.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sColumnHolder31.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sColumnHolder32.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sColumnHolder32.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sColumnHolder32.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sColumnHolder33.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sColumnHolder33.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sColumnHolder33.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsCol31[1]) 
                {
                    case 1:
                        sColumnHolder31.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sColumnHolder31.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sColumnHolder31.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sColumnHolder32.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sColumnHolder32.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sColumnHolder32.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sColumnHolder33.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sColumnHolder33.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sColumnHolder33.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Fourth column
    ColumnHolder    sColumnHolder41 = ioGrid.GetN().LeftColumn(),
    sColumnHolder42 = ioGrid.GetC().LeftColumn(),
    sColumnHolder43 = ioGrid.GetS().LeftColumn();
    
    std::vector<int>    EmptyCellsCol41 = sColumnHolder41.indexEmpty(),
    EmptyCellsCol42 = sColumnHolder42.indexEmpty(),
    EmptyCellsCol43 = sColumnHolder41.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsCol42.size() ; ++i)
    {
        EmptyCellsCol41.push_back( EmptyCellsCol42[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsCol43.size() ; ++i)
    {
        EmptyCellsCol41.push_back( EmptyCellsCol43[i] + 6);
    }
    
    if (EmptyCellsCol41.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sColumnHolder41.flagValues(sValueEliminator);
        sColumnHolder42.flagValues(sValueEliminator);
        sColumnHolder43.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol41[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsCol41[0]) 
            {
                case 1:
                    sColumnHolder41.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sColumnHolder41.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sColumnHolder41.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sColumnHolder42.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sColumnHolder42.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sColumnHolder42.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sColumnHolder43.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sColumnHolder43.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sColumnHolder43.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsCol41[1]) 
            {
                case 1:
                    sColumnHolder41.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sColumnHolder41.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sColumnHolder41.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sColumnHolder42.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sColumnHolder42.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sColumnHolder42.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sColumnHolder43.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sColumnHolder43.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sColumnHolder43.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol41[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsCol41[0]) 
                {
                    case 1:
                        sColumnHolder41.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sColumnHolder41.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sColumnHolder41.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sColumnHolder42.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sColumnHolder42.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sColumnHolder42.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sColumnHolder43.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sColumnHolder43.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sColumnHolder43.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsCol41[1]) 
                {
                    case 1:
                        sColumnHolder41.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sColumnHolder41.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sColumnHolder41.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sColumnHolder42.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sColumnHolder42.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sColumnHolder42.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sColumnHolder43.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sColumnHolder43.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sColumnHolder43.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Fifth column
    ColumnHolder    sColumnHolder51 = ioGrid.GetN().MiddleColumn(),
    sColumnHolder52 = ioGrid.GetC().MiddleColumn(),
    sColumnHolder53 = ioGrid.GetS().MiddleColumn();
    
    std::vector<int>    EmptyCellsCol51 = sColumnHolder51.indexEmpty(),
    EmptyCellsCol52 = sColumnHolder52.indexEmpty(),
    EmptyCellsCol53 = sColumnHolder51.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsCol52.size() ; ++i)
    {
        EmptyCellsCol51.push_back( EmptyCellsCol52[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsCol53.size() ; ++i)
    {
        EmptyCellsCol51.push_back( EmptyCellsCol53[i] + 6);
    }
    
    if (EmptyCellsCol51.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sColumnHolder51.flagValues(sValueEliminator);
        sColumnHolder52.flagValues(sValueEliminator);
        sColumnHolder53.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol51[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsCol51[0]) 
            {
                case 1:
                    sColumnHolder51.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sColumnHolder51.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sColumnHolder51.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sColumnHolder52.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sColumnHolder52.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sColumnHolder52.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sColumnHolder53.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sColumnHolder53.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sColumnHolder53.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsCol51[1]) 
            {
                case 1:
                    sColumnHolder51.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sColumnHolder51.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sColumnHolder51.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sColumnHolder52.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sColumnHolder52.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sColumnHolder52.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sColumnHolder53.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sColumnHolder53.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sColumnHolder53.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol51[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsCol51[0]) 
                {
                    case 1:
                        sColumnHolder51.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sColumnHolder51.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sColumnHolder51.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sColumnHolder52.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sColumnHolder52.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sColumnHolder52.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sColumnHolder53.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sColumnHolder53.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sColumnHolder53.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsCol51[1]) 
                {
                    case 1:
                        sColumnHolder51.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sColumnHolder51.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sColumnHolder51.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sColumnHolder52.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sColumnHolder52.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sColumnHolder52.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sColumnHolder53.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sColumnHolder53.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sColumnHolder53.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Sixth column
    ColumnHolder    sColumnHolder61 = ioGrid.GetN().RightColumn(),
    sColumnHolder62 = ioGrid.GetC().RightColumn(),
    sColumnHolder63 = ioGrid.GetS().RightColumn();
    
    std::vector<int>    EmptyCellsCol61 = sColumnHolder61.indexEmpty(),
    EmptyCellsCol62 = sColumnHolder62.indexEmpty(),
    EmptyCellsCol63 = sColumnHolder61.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsCol62.size() ; ++i)
    {
        EmptyCellsCol61.push_back( EmptyCellsCol62[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsCol63.size() ; ++i)
    {
        EmptyCellsCol61.push_back( EmptyCellsCol63[i] + 6);
    }
    
    if (EmptyCellsCol61.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sColumnHolder61.flagValues(sValueEliminator);
        sColumnHolder62.flagValues(sValueEliminator);
        sColumnHolder63.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol61[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsCol61[0]) 
            {
                case 1:
                    sColumnHolder61.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sColumnHolder61.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sColumnHolder61.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sColumnHolder62.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sColumnHolder62.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sColumnHolder62.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sColumnHolder63.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sColumnHolder63.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sColumnHolder63.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsCol61[1]) 
            {
                case 1:
                    sColumnHolder61.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sColumnHolder61.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sColumnHolder61.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sColumnHolder62.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sColumnHolder62.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sColumnHolder62.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sColumnHolder63.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sColumnHolder63.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sColumnHolder63.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol61[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsCol61[0]) 
                {
                    case 1:
                        sColumnHolder61.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sColumnHolder61.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sColumnHolder61.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sColumnHolder62.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sColumnHolder62.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sColumnHolder62.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sColumnHolder63.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sColumnHolder63.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sColumnHolder63.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsCol61[1]) 
                {
                    case 1:
                        sColumnHolder61.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sColumnHolder61.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sColumnHolder61.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sColumnHolder62.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sColumnHolder62.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sColumnHolder62.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sColumnHolder63.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sColumnHolder63.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sColumnHolder63.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Seventh column
    ColumnHolder    sColumnHolder71 = ioGrid.GetNE().LeftColumn(),
    sColumnHolder72 = ioGrid.GetE().LeftColumn(),
    sColumnHolder73 = ioGrid.GetSE().LeftColumn();
    
    std::vector<int>    EmptyCellsCol71 = sColumnHolder71.indexEmpty(),
    EmptyCellsCol72 = sColumnHolder72.indexEmpty(),
    EmptyCellsCol73 = sColumnHolder71.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsCol72.size() ; ++i)
    {
        EmptyCellsCol71.push_back( EmptyCellsCol72[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsCol73.size() ; ++i)
    {
        EmptyCellsCol71.push_back( EmptyCellsCol73[i] + 6);
    }
    
    if (EmptyCellsCol71.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sColumnHolder71.flagValues(sValueEliminator);
        sColumnHolder72.flagValues(sValueEliminator);
        sColumnHolder73.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol71[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsCol71[0]) 
            {
                case 1:
                    sColumnHolder71.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sColumnHolder71.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sColumnHolder71.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sColumnHolder72.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sColumnHolder72.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sColumnHolder72.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sColumnHolder73.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sColumnHolder73.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sColumnHolder73.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsCol71[1]) 
            {
                case 1:
                    sColumnHolder71.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sColumnHolder71.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sColumnHolder71.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sColumnHolder72.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sColumnHolder72.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sColumnHolder72.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sColumnHolder73.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sColumnHolder73.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sColumnHolder73.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol71[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsCol71[0]) 
                {
                    case 1:
                        sColumnHolder71.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sColumnHolder71.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sColumnHolder71.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sColumnHolder72.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sColumnHolder72.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sColumnHolder72.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sColumnHolder73.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sColumnHolder73.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sColumnHolder73.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsCol71[1]) 
                {
                    case 1:
                        sColumnHolder71.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sColumnHolder71.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sColumnHolder71.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sColumnHolder72.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sColumnHolder72.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sColumnHolder72.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sColumnHolder73.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sColumnHolder73.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sColumnHolder73.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Eighth column
    ColumnHolder    sColumnHolder81 = ioGrid.GetNE().MiddleColumn(),
    sColumnHolder82 = ioGrid.GetE().MiddleColumn(),
    sColumnHolder83 = ioGrid.GetSE().MiddleColumn();
    
    std::vector<int>    EmptyCellsCol81 = sColumnHolder81.indexEmpty(),
    EmptyCellsCol82 = sColumnHolder82.indexEmpty(),
    EmptyCellsCol83 = sColumnHolder81.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsCol82.size() ; ++i)
    {
        EmptyCellsCol81.push_back( EmptyCellsCol82[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsCol83.size() ; ++i)
    {
        EmptyCellsCol81.push_back( EmptyCellsCol83[i] + 6);
    }
    
    if (EmptyCellsCol81.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sColumnHolder81.flagValues(sValueEliminator);
        sColumnHolder82.flagValues(sValueEliminator);
        sColumnHolder83.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol81[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsCol81[0]) 
            {
                case 1:
                    sColumnHolder81.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sColumnHolder81.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sColumnHolder81.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sColumnHolder82.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sColumnHolder82.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sColumnHolder82.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sColumnHolder83.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sColumnHolder83.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sColumnHolder83.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsCol81[1]) 
            {
                case 1:
                    sColumnHolder81.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sColumnHolder81.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sColumnHolder81.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sColumnHolder82.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sColumnHolder82.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sColumnHolder82.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sColumnHolder83.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sColumnHolder83.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sColumnHolder83.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol81[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsCol81[0]) 
                {
                    case 1:
                        sColumnHolder81.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sColumnHolder81.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sColumnHolder81.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sColumnHolder82.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sColumnHolder82.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sColumnHolder82.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sColumnHolder83.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sColumnHolder83.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sColumnHolder83.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsCol81[1]) 
                {
                    case 1:
                        sColumnHolder81.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sColumnHolder81.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sColumnHolder81.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sColumnHolder82.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sColumnHolder82.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sColumnHolder82.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sColumnHolder83.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sColumnHolder83.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sColumnHolder83.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    //  Nineth column
    ColumnHolder    sColumnHolder91 = ioGrid.GetNE().RightColumn(),
    sColumnHolder92 = ioGrid.GetE().RightColumn(),
    sColumnHolder93 = ioGrid.GetSE().RightColumn(); 
    
    std::vector<int>    EmptyCellsCol91 = sColumnHolder91.indexEmpty(),
    EmptyCellsCol92 = sColumnHolder92.indexEmpty(),
    EmptyCellsCol93 = sColumnHolder91.indexEmpty();
    for (std::size_t i = 0 ; i < EmptyCellsCol92.size() ; ++i)
    {
        EmptyCellsCol91.push_back( EmptyCellsCol92[i] + 3);
    }
    for (std::size_t i = 0 ; i < EmptyCellsCol93.size() ; ++i)
    {
        EmptyCellsCol91.push_back( EmptyCellsCol93[i] + 6);
    }
    
    if (EmptyCellsCol91.size() == 2)
    {
        ValueEliminator sValueEliminator;
        sColumnHolder91.flagValues(sValueEliminator);
        sColumnHolder92.flagValues(sValueEliminator);
        sColumnHolder93.flagValues(sValueEliminator);
        
        std::set<unsigned int> iAvailableValues = sValueEliminator.availableValue();
        
        bool bIs1stValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol91[0], *iAvailableValues.begin());
        if (bIs1stValuePresent)
        {
            bResult = true;
            switch (EmptyCellsCol91[0]) 
            {
                case 1:
                    sColumnHolder91.GetLeft() = *iAvailableValues.begin();
                    break;
                case 2:
                    sColumnHolder91.GetCenter() = *iAvailableValues.begin();
                    break;
                case 3:
                    sColumnHolder91.GetRight() = *iAvailableValues.begin();
                    break;
                case 4:
                    sColumnHolder92.GetLeft() = *iAvailableValues.begin();
                    break;
                case 5:
                    sColumnHolder92.GetCenter() = *iAvailableValues.begin();
                    break;
                case 6:
                    sColumnHolder92.GetRight() = *iAvailableValues.begin();
                    break;
                case 7:
                    sColumnHolder93.GetLeft() = *iAvailableValues.begin();
                    break;
                case 8:
                    sColumnHolder93.GetCenter() = *iAvailableValues.begin();
                    break;
                case 9:
                    sColumnHolder93.GetRight() = *iAvailableValues.begin();
                    break;
                default:
                    break;
            }
            switch (EmptyCellsCol91[1]) 
            {
                case 1:
                    sColumnHolder91.GetLeft() = *iAvailableValues.end();
                    break;
                case 2:
                    sColumnHolder91.GetCenter() = *iAvailableValues.end();
                    break;
                case 3:
                    sColumnHolder91.GetRight() = *iAvailableValues.end();
                    break;
                case 4:
                    sColumnHolder92.GetLeft() = *iAvailableValues.end();
                    break;
                case 5:
                    sColumnHolder92.GetCenter() = *iAvailableValues.end();
                    break;
                case 6:
                    sColumnHolder92.GetRight() = *iAvailableValues.end();
                    break;
                case 7:
                    sColumnHolder93.GetLeft() = *iAvailableValues.end();
                    break;
                case 8:
                    sColumnHolder93.GetCenter() = *iAvailableValues.end();
                    break;
                case 9:
                    sColumnHolder93.GetRight() = *iAvailableValues.end();
                    break;
                default:
                    break;
            }
        }
        else
        {
            bool bIs2ndValuePresent = ioGrid.IsPresentValueColumn(EmptyCellsCol91[0], *iAvailableValues.end());
            if (bIs2ndValuePresent)
            {
                bResult = true;
                switch (EmptyCellsCol91[0]) 
                {
                    case 1:
                        sColumnHolder91.GetLeft() = *iAvailableValues.end();
                        break;
                    case 2:
                        sColumnHolder91.GetCenter() = *iAvailableValues.end();
                        break;
                    case 3:
                        sColumnHolder91.GetRight() = *iAvailableValues.end();
                        break;
                    case 4:
                        sColumnHolder92.GetLeft() = *iAvailableValues.end();
                        break;
                    case 5:
                        sColumnHolder92.GetCenter() = *iAvailableValues.end();
                        break;
                    case 6:
                        sColumnHolder92.GetRight() = *iAvailableValues.end();
                        break;
                    case 7:
                        sColumnHolder93.GetLeft() = *iAvailableValues.end();
                        break;
                    case 8:
                        sColumnHolder93.GetCenter() = *iAvailableValues.end();
                        break;
                    case 9:
                        sColumnHolder93.GetRight() = *iAvailableValues.end();
                        break;
                    default:
                        break;
                }
                switch (EmptyCellsCol91[1]) 
                {
                    case 1:
                        sColumnHolder91.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 2:
                        sColumnHolder91.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 3:
                        sColumnHolder91.GetRight() = *iAvailableValues.begin();
                        break;
                    case 4:
                        sColumnHolder92.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 5:
                        sColumnHolder92.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 6:
                        sColumnHolder92.GetRight() = *iAvailableValues.begin();
                        break;
                    case 7:
                        sColumnHolder93.GetLeft() = *iAvailableValues.begin();
                        break;
                    case 8:
                        sColumnHolder93.GetCenter() = *iAvailableValues.begin();
                        break;
                    case 9:
                        sColumnHolder93.GetRight() = *iAvailableValues.begin();
                        break;
                    default:
                        break;
                }
            }
        }
    }
    
    return bResult;
}
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
    
    return bResult;
}
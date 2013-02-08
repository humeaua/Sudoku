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
        
    }
    
    return false;
}
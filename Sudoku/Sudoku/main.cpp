//
//  main.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 04/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Cell.h"
#include "Region.h"
#include "Grid.h"
#include "TripleHolder.h"
#include "LastCellFinder.h"
#include "OnlyOneChoiceInRowVisitor.h"
#include "OnlyOneChoiceInColumnVisitor.h"
#include "OnlyOneChoiceInRegionVisitor.h"

int main (int argc, const char * argv[])
{
    std::cout << "Hello, World!\n";
    
    try 
    {
        std::cout << "Choose the test : " << std::endl;
        std::cout << "1- Basic Last cell finder" << std::endl;
        std::cout << "2- Only One Choice In Row Visitor" << std::endl;
        std::cout << "3- Only One Choice In Column Visitor" << std::endl;
        std::cout << "4- Only One Choice In Region Visitor" << std::endl;
        std::size_t iTest = 1;
        std::cin >> iTest;
        
        if (iTest == 1)
        {
            //Cell sCell0, sCell1(1), sCell2(10);
            Region sRegion("123456789");
            Region sRegion2("1-3--67-9");
            //int i = 0;
            Cell sCell1(1), sCell2(2), sCell3(3), sCell4(4), sCell5(5), sCell6(6), sCell7(7), sCell8(8), sCell9;
            TripleHolder s1(sCell1, sCell2, sCell3), s2(sCell4, sCell5, sCell6), s3(sCell7, sCell8, sCell9);
            LastCellFinder sLastCellFinder(s1, s2, s3);
            std::pair<std::vector<unsigned int>, std::vector<unsigned int> > sEmptyCells = sLastCellFinder.EmptyCells();
            std::cout << "Number of empty cells : " << sEmptyCells.first.size() << std::endl;
            std::cout << "Is Cell Filled ? : " << sLastCellFinder.fill() << std::endl;
        }
        else if (iTest == 2)
        {
            //  Test of Only one choice in Row Vistor
            Region sRegion0("-23-56-89"), sRegion1("456789123"), sRegion2("789123456"); // to test OnlyOneChoiceInRowVisitor
            Grid sGrid(sRegion0, sRegion1, sRegion2, sRegion0, sRegion1, sRegion2, sRegion0, sRegion1, sRegion2);
            OnlyOneChoiceInRowVisitor sOnlyOneChoiceInRowVisitor;  
            std::cout << sOnlyOneChoiceInRowVisitor.Visit(sGrid) << std::endl;
        }
        else if (iTest == 3)
        {
            //  Test of Only one choice in Column Visitor
            Region sRegion0("---222333"), sRegion1("444555666"), sRegion2("777888999"); // to test OnlyOneChoiceInColumnVisitor
            Grid sGrid(sRegion0, sRegion0, sRegion0, sRegion1, sRegion1, sRegion1, sRegion2, sRegion2, sRegion2);
            OnlyOneChoiceInColumnVisitor sOnlyOneChoiceInColumnVisitor;  
            std::cout << sOnlyOneChoiceInColumnVisitor.Visit(sGrid) << std::endl;
        }
        else if (iTest == 4)
        {
            Region sRegion("-23456789");
            Grid sGrid(sRegion, sRegion, sRegion, sRegion, sRegion, sRegion, sRegion, sRegion, sRegion);
            OnlyOneChoiceInRegionVisitor sOnlyOneChoiceInRegionVisitor;
            std::cout << sOnlyOneChoiceInRegionVisitor.Visit(sGrid) << std::endl;
        }
        std::cout << "Done!" << std::endl;
    } 
    catch (std::string & s) 
    {
        std::cout << "Error is : ";
        std::cout << s << std::endl;
    }
    return 0;
}


//
//  TwoOutOfThreeColumnVisitor.cpp
//  Sudoku
//
//  Created by Thomas Grandhaye on 10/02/13.
//
//

#include "TwoOutOfThreeColumnVisitor.h"

bool TwoOutOfThreeColumnVisitor::Visit(Grid & ioGrid) const
{
    bool bResult = false;
    
    //  Region NO,O,SO
    for (int i = 0 ; i < 10 ; ++i)
    {}
    
    //  Region N,C,S
    for (int i = 0 ; i < 10 ; ++i)
    {}
    
    //  Region NE,E,SE
    for (int i = 0 ; i < 10 ; ++i)
    {}
    
    return bResult;
}
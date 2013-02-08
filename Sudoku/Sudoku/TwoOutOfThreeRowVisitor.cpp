//
//  TwoOutOfThreeRowVisitor.cpp
//  Sudoku
//
//  Created by Thomas Grandhaye on 08/02/13.
//
//

#include "TwoOutOfThreeRowVisitor.h"

bool TwoOutOfThreeRowVisitor::Visit(Grid & ioGrid) const
{
    // Regions set (NO,N,NE)
    for(int i =1; i<10; i++)
        {
        
        if(!ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
            {
            
            }
        else if(ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
            {
            
            }
        else if(!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
            {
            
            }
        
        }
    
    // Regions set (O,C,E)
    
    
    // Regions set (SO,S,SE)
    
    return false;
}
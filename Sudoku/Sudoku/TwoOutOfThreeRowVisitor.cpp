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
        if(ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
            {if(!ioGrid.GetNO().isValuePresent(i))
                {
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                    {
                    // remplir NO.bottom.1
                    }
                else if(ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                    {
                    // remplir NO.bottom.2
                    }
                else if(ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                    {
                    // remplir NO.bottom.3                    
                    }
                
                }
            if(!ioGrid.GetN().isValuePresent(i))
                {
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                    {
                    // remplir N.bottom.1
                    }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                    {
                    // remplir N.bottom.2
                    }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                    {
                    // remplir N.bottom.3
                    }
                    
                }
            if(!ioGrid.GetNE().isValuePresent(i))
                {
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                    {
                    // remplir NE.bottom.1
                    }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                    {
                    // remplir NE.bottom.2
                    }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                    {
                    // remplir NE.bottom.3
                    }
                
                }
            
            }
        else if(ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
            {if(!ioGrid.GetNO().isValuePresent(i))
                {
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                    {
                    // remplir NO.middle.1
                    }
                else if(ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                    {
                    // remplir NO.middle.2
                    }
                else if(ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                    {
                    // remplir NO.middle.3
                    }
                
                }
            if(!ioGrid.GetN().isValuePresent(i))
                {
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                    {
                    // remplir N.bottom.1
                    }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                    {
                    // remplir N.bottom.2
                    }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                    {
                    // remplir N.bottom.3
                    }
                }
            if(!ioGrid.GetNE().isValuePresent(i))
                {
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                    {
                    // remplir NE.bottom.1
                    }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                    {
                    // remplir NE.bottom.2
                    }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                    {
                    // remplir NE.bottom.3
                    }
                
                }
            
            }
        else if(!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
            {if(!ioGrid.GetNO().isValuePresent(i))
                {
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                    {
                    // remplir NO.top.1
                    }
                else if(ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                    {
                    // remplir NO.top.2
                    }
                else if(ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                    {
                    // remplir NO.top.3
                    }
                
                }
                if(!ioGrid.GetN().isValuePresent(i))
                    {
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                    {
                    // remplir N.top.1
                    }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                    {
                    // remplir N.top.2
                    }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                    {
                    // remplir N.top.3
                    }
                }
            if(!ioGrid.GetNE().isValuePresent(i))
                {
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                    {
                    // remplir NE.top.1
                    }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                    {
                    // remplir NE.top.2
                    }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                    {
                    // remplir NE.top.3
                    }
                
                }
            }
        
        }
    
    // Regions set (O,C,E)
    
    
    // Regions set (SO,S,SE)
    
    return false;
}
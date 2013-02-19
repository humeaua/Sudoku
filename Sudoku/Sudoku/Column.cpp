//
//  Column.cpp
//  Sudoku
//
//  Created by Thomas Grandhaye on 18/02/13.
//
//

#include "Column.h"

Column::Column(ColumnHolder& c1, ColumnHolder & c2, ColumnHolder & c3) : NonupleHolder(c1, c2, c3)
{}

Column::Column(Cell &sCell1, Cell & sCell2, Cell & sCell3, Cell & sCell4, Cell & sCell5, Cell & sCell6, Cell & sCell7, Cell & sCell8, Cell & sCell9) : NonupleHolder(sCell1, sCell2, sCell3, sCell4, sCell5, sCell6, sCell7, sCell8, sCell9)
{}

ColumnHolder Column::TopColHolder()
{
    return ColumnHolder(s1_, s2_, s3_);
}

ColumnHolder Column::MiddleColHolder()
{
    return ColumnHolder(s4_, s4_, s6_);
}

ColumnHolder Column::BottomColHolder()
{
    return ColumnHolder(s7_, s8_, s9_);
}

bool Column::isConsistent()
{
    int result = true;
    for(int i = 1; i<10; i++)
        {
        if( TopColHolder().isValuePresent(i) && MiddleColHolder().isValuePresent(i)) {result=false;}
        else if (TopColHolder().isValuePresent(i) && BottomColHolder().isValuePresent(i)) {result=false;}
        else if (MiddleColHolder().isValuePresent(i) && BottomColHolder().isValuePresent(i)) {result=false;}
        }
    return result;
} 
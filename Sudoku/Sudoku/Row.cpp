//
//  Row.cpp
//  Sudoku
//
//  Created by Thomas Grandhaye on 18/02/13.
//
//

#include "Row.h"

Row::Row(RowHolder& r1, RowHolder & r2, RowHolder & r3) : NonupleHolder(r1, r2, r3)
{}

Row::Row(Cell &sCell1, Cell & sCell2, Cell & sCell3, Cell & sCell4, Cell & sCell5, Cell & sCell6, Cell & sCell7, Cell & sCell8, Cell & sCell9) : NonupleHolder(sCell1, sCell2, sCell3, sCell4, sCell5, sCell6, sCell7, sCell8, sCell9)
{}

RowHolder Row::LeftRowHolder()
{
    return RowHolder(s1_, s2_, s3_);
}

RowHolder Row::MiddleRowHolder()
{
    return RowHolder(s4_, s4_, s6_);
}

RowHolder Row::RightRowHolder()
{
    return RowHolder(s7_, s8_, s9_);
}

bool Row::isConsistent()
{
    int result = true;
    for(int i = 1; i<10; i++)
        {
        if( LeftRowHolder().isValuePresent(i) && MiddleRowHolder().isValuePresent(i)) {result=false;}
        else if (LeftRowHolder().isValuePresent(i) && RightRowHolder().isValuePresent(i)) {result=false;}
        else if (MiddleRowHolder().isValuePresent(i) && RightRowHolder().isValuePresent(i)) {result=false;}
        }
    return result;
}
//
//  Row.cpp
//  Sudoku
//
//  Created by Thomas Grandhaye on 18/02/13.
//
//

#include "Row.h"

Row::Row(RowHolder& r1, RowHolder & r2, RowHolder & r3) : s1_(r1.GetLeft()), s2_(r1.GetCenter()), s3_(r1.GetRight()),s4_(r2.GetLeft()), s5_(r2.GetCenter()), s6_(r2.GetRight()),s7_(r3.GetLeft()), s8_(r3.GetCenter()), s9_(r3.GetRight())
{}

Row::Row(Cell &sCell1, Cell & sCell2, Cell & sCell3, Cell & sCell4, Cell & sCell5, Cell & sCell6, Cell & sCell7, Cell & sCell8, Cell & sCell9) : s1_(sCell1), s2_(sCell2), s3_(sCell3), s4_(sCell4), s5_(sCell5), s6_(sCell6), s7_(sCell7), s8_(sCell8), s9_(sCell9)
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
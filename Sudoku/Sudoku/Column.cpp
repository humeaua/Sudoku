//
//  Column.cpp
//  Sudoku
//
//  Created by Thomas Grandhaye on 18/02/13.
//
//

#include "Column.h"
#include "NonupleHolder.h"
#include "ColumnHolder.h"

Column::Column(ColumnHolder& c1, ColumnHolder & c2, ColumnHolder & c3) : s1_(c1.GetLeft()), s2_(c1.GetCenter()), s3_(c1.GetRight()),s4_(c2.GetLeft()), s5_(c2.GetCenter()), s6_(c2.GetRight()),s7_(c3.GetLeft()), s8_(c3.GetCenter()), s9_(c3.GetRight())
{}

Column::Column(Cell &sCell1, Cell & sCell2, Cell & sCell3, Cell & sCell4, Cell & sCell5, Cell & sCell6, Cell & sCell7, Cell & sCell8, Cell & sCell9) : s1_(sCell1), s2_(sCell2), s3_(sCell3), s4_(sCell4), s5_(sCell5), s6_(sCell6), s7_(sCell7), s8_(sCell8), s9_(sCell9)
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
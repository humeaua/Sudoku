//
//  Row.cpp
//  Sudoku
//
//  Created by Thomas Grandhaye on 18/02/13.
//
//

#include "Row.h"
#include "NonupleHolder.h"
#include "RowHolder.h"

Row::Row(RowHolder& r1, RowHolder & r2, RowHolder & r3) : s1_(r1.GetLeft()), s2_(r1.GetCenter()), s3_(r1.GetRight()),s4_(r2.GetLeft()), s5_(r2.GetCenter()), s6_(r2.GetRight()),s7_(r3.GetLeft()), s8_(r3.GetCenter()), s9_(r3.GetRight())
{}

Row::Row(Cell &sCell1, Cell & sCell2, Cell & sCell3, Cell & sCell4, Cell & sCell5, Cell & sCell6, Cell & sCell7, Cell & sCell8, Cell & sCell9) : s1_(sCell1), s2_(sCell2), s3_(sCell3), s4_(sCell4), s5_(sCell5), s6_(sCell6), s7_(sCell7), s8_(sCell8), s9_(sCell9)
{}
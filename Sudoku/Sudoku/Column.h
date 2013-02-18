//
//  Column.h
//  Sudoku
//
//  Created by Thomas Grandhaye on 18/02/13.
//
//

#ifndef __Sudoku__Column__
#define __Sudoku__Column__

#include <iostream>
#include "NonupleHolder.h"
#include "ColumnHolder.h"

class Column : public NonupleHolder {
    Cell &s1_, &s2_, &s3_, &s4_, &s5_, &s6_, &s7_, &s8_, &s9_;
public:
    Column(ColumnHolder & r1, ColumnHolder & r2, ColumnHolder & r3);
    Column(Cell &sCell1, Cell & sCell2, Cell & sCell3, Cell & sCell4, Cell & sCell5, Cell & sCell6, Cell & sCell7, Cell & sCell8, Cell & sCell9);
    
    virtual ColumnHolder TopColHolder();
    virtual ColumnHolder MiddleColHolder();
    virtual ColumnHolder BottomColHolder();
    
    virtual bool isConsistent();
};

#endif /* defined(__Sudoku__Column__) */

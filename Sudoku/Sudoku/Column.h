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

public:
    Column(ColumnHolder & c1, ColumnHolder & c2, ColumnHolder & c3);
    Column(Cell &sCell1, Cell & sCell2, Cell & sCell3, Cell & sCell4, Cell & sCell5, Cell & sCell6, Cell & sCell7, Cell & sCell8, Cell & sCell9);
    
    virtual ColumnHolder TopColHolder();
    virtual ColumnHolder MiddleColHolder();
    virtual ColumnHolder BottomColHolder();
    
    virtual bool isConsistent();
};

#endif /* defined(__Sudoku__Column__) */

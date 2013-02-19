//
//  Row.h
//  Sudoku
//
//  Created by Thomas Grandhaye on 18/02/13.
//
//

#ifndef __Sudoku__Row__
#define __Sudoku__Row__

#include <iostream>
#include "NonupleHolder.h"
#include "RowHolder.h"

class Row : public NonupleHolder {

public:
    Row(RowHolder & r1, RowHolder & r2, RowHolder & r3);
    Row(Cell &sCell1, Cell & sCell2, Cell & sCell3, Cell & sCell4, Cell & sCell5, Cell & sCell6, Cell & sCell7, Cell & sCell8, Cell & sCell9);
    
    virtual RowHolder LeftRowHolder();
    virtual RowHolder MiddleRowHolder();
    virtual RowHolder RightRowHolder();
    
    virtual bool isConsistent();
};

#endif /* defined(__Sudoku__Row__) */

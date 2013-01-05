//
//  RegionHolder.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_RegionHolder_h
#define Sudoku_RegionHolder_h

#include "Region.h"
#include "RowHolder.h"
#include "ColumnHolder.h"

class RegionHolder : public Region{
protected:
    
public:
    RegionHolder(const Region & sRegion);
    
    virtual const Cell & GetNO() const;
    virtual const Cell & GetNE() const;
    virtual const Cell & GetN() const;
    virtual const Cell & GetO() const;
    virtual const Cell & GetC() const;
    virtual const Cell & GetE() const;
    virtual const Cell & GetS() const;
    virtual const Cell & GetSO() const;
    virtual const Cell & GetSE() const;

    virtual RowHolder TopRow();
    virtual RowHolder MiddleRow();
    virtual RowHolder BottomRow();
    virtual ColumnHolder LeftColumn();
    virtual ColumnHolder MiddleColumn();
    virtual ColumnHolder RightColumn();
    
    virtual RowHolder TopRow() const;
    virtual RowHolder MiddleRow() const;
    virtual RowHolder BottomRow() const;
    virtual ColumnHolder LeftColumn() const;
    virtual ColumnHolder MiddleColumn() const;
    virtual ColumnHolder RightColumn() const;
};

#endif

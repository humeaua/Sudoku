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
#include "ValueEliminator.h"

class RegionHolder{
protected:
    Cell &sNO_;
    Cell &sN_;
    Cell &sNE_;
    Cell &sO_;
    Cell &sC_;
    Cell &sE_;
    Cell &sSO_;
    Cell &sS_;
    Cell &sSE_;
public:
    RegionHolder(Region & sRegion);
    
    virtual Cell & GetNO();
    virtual Cell & GetNE();
    virtual Cell & GetN();
    virtual Cell & GetO();
    virtual Cell & GetC();
    virtual Cell & GetE();
    virtual Cell & GetS();
    virtual Cell & GetSO();
    virtual Cell & GetSE();

    virtual RowHolder TopRow();
    virtual RowHolder MiddleRow();
    virtual RowHolder BottomRow();
    virtual ColumnHolder LeftColumn();
    virtual ColumnHolder MiddleColumn();
    virtual ColumnHolder RightColumn();
    
    virtual const RowHolder TopRow() const;
    virtual const RowHolder MiddleRow() const;
    virtual const RowHolder BottomRow() const;
    virtual const ColumnHolder LeftColumn() const;
    virtual const ColumnHolder MiddleColumn() const;
    virtual const ColumnHolder RightColumn() const;
    
    virtual void flagValues(ValueEliminator & sValueEliminator) const;
};

#endif

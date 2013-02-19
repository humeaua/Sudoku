//
//  Grid.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_Grid_h
#define Sudoku_Grid_h

#include <vector>
#include "RegionHolder.h"
#include "IVisitor.h"
#include "Column.h"
#include "Row.h"

class IVisitor;

class Grid {
protected:
    Region sRegionNO_, sRegionN_, sRegionNE_, sRegionO_, sRegionC_, sRegionE_, sRegionSO_, sRegionS_, sRegionSE_;
public:
    Grid(const Region & sRegionNO, const Region & sRegionN, const Region & sRegionNE, const Region & sRegionO, const Region & sRegionC, const Region & sRegionE, const Region & sRegionSO, const Region & sRegionS, const Region & sRegionSE);
    virtual ~Grid();
    
    virtual bool IsFull() const;
    
    virtual RegionHolder GetNO();
    virtual RegionHolder GetNE();
    virtual RegionHolder GetN();
    virtual RegionHolder GetO();
    virtual RegionHolder GetC();
    virtual RegionHolder GetE();
    virtual RegionHolder GetS();
    virtual RegionHolder GetSE();
    virtual RegionHolder GetSO();
    
    virtual Column Col1();
    virtual Column Col2();
    virtual Column Col3();
    virtual Column Col4();
    virtual Column Col5();
    virtual Column Col6();
    virtual Column Col7();
    virtual Column Col8();
    virtual Column Col9();
    
    virtual Row Row1();
    virtual Row Row2();
    virtual Row Row3();
    virtual Row Row4();
    virtual Row Row5();
    virtual Row Row6();
    virtual Row Row7();
    virtual Row Row8();
    virtual Row Row9();
    
    virtual bool Accept(const IVisitor & sVisitor);
    virtual bool IsPresentValueColumn(int iCol, int intValue);
    virtual bool IsPresentValueRow(int iRow, int intValue);
    
    virtual void Print();
    
    virtual bool isConsistent();
};

#endif

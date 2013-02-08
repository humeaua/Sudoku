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
    
    virtual bool Accept(const IVisitor & sVisitor);
    virtual bool IsPresentValueColumn(int iCol, int intValue);
    virtual bool IsPresentValueRow(int iRow, int intValue);
};

#endif

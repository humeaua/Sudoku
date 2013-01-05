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

class Grid {
protected:
    Region sRegionNO_, sRegionN_, sRegionNE_, sRegionO_, sRegionC_, sRegionE_, sRegionSO_, sRegionS_, sRegionSE_;
public:
    Grid(const Region & sRegionNO, const Region & sRegionN, const Region & sRegionNE, const Region & sRegionO, const Region & sRegionC, const Region & sRegionE, const Region & sRegionSO, const Region & sRegionS, const Region & sRegionSE);
    virtual ~Grid();
    
    virtual bool IsFull() const;
    
    virtual const RegionHolder GetNO() const;
    virtual const RegionHolder GetNE() const;
    virtual const RegionHolder GetN() const;
    virtual const RegionHolder GetO() const;
    virtual const RegionHolder GetC() const;
    virtual const RegionHolder GetE() const;
    virtual const RegionHolder GetS() const;
    virtual const RegionHolder GetSE() const;
    virtual const RegionHolder GetSO() const;
};

#endif

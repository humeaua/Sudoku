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

    
};

#endif

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

class RegionHolder {
protected:
    Region sRegion_;
    
public:
    RegionHolder(const Region & sRegion);
};

#endif

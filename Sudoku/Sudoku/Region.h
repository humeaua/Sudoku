//
//  Region.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 04/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_Region_h
#define Sudoku_Region_h

#include "Cell.h"

class Region {
public:
    Cell sN_, sS_, sE_, sO_, sNE_, sSE_, sNO_, sSO_, sC_;
    
    Region(const std::string & cString);
    
    virtual bool IsFull() const;
};

#endif

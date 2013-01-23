//
//  IVisitor.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 15/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_IVisitor_h
#define Sudoku_IVisitor_h

#include "Grid.h"

class Grid;

class IVisitor {
protected:
    
public:
    virtual bool Visit(Grid & ioGrid) const;
};

#endif

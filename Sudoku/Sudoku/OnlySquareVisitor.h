//
//  OnlySquareVisitor.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 27/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_OnlySquareVisitor_h
#define Sudoku_OnlySquareVisitor_h

#include "IVisitor.h"

class OnlySquareVisitor : public IVisitor {
    
    
public:
    virtual bool Visit(Grid & ioGrid) const;
};

#endif

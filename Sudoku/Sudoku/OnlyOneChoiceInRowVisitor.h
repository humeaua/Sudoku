//
//  OnlyOneChoiceInRowVisitor.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 15/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_OnlyOneChoiceInRowVisitor_h
#define Sudoku_OnlyOneChoiceInRowVisitor_h

#include "IVisitor.h"
#include <vector>
#include <map>
#include "RowHolder.h"

class OnlyOneChoiceInRowVisitor : public IVisitor {
protected:
    
public:
    virtual bool Visit(Grid & ioGrid) const;
};

#endif

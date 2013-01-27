//
//  OnlyOneChoiceInColumnVisitor.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 22/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_OnlyOneChoiceInColumnVisitor_h
#define Sudoku_OnlyOneChoiceInColumnVisitor_h


#include "IVisitor.h"
#include <vector>
#include <map>
#include "RowHolder.h"

class OnlyOneChoiceInColumnVisitor : public IVisitor {
protected:
    
public:
    virtual bool Visit(Grid & ioGrid) const;
};

#endif

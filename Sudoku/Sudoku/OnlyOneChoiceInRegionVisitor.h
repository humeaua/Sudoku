//
//  OnlyOneChoiceInRegionVisitor.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 22/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_OnlyOneChoiceInRegionVisitor_h
#define Sudoku_OnlyOneChoiceInRegionVisitor_h

#include "IVisitor.h"
#include <vector>
#include <map>

class OnlyOneChoiceInRegionVisitor : public IVisitor {
protected:
    
public:
    virtual bool Visit(const Grid & ioGrid) const;
    
};


#endif

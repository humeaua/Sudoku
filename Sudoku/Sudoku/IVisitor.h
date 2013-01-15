//
//  IVisitor.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 15/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_IVisitor_h
#define Sudoku_IVisitor_h

class IVisitor {
protected:
    
public:
    virtual bool Visit(Grid & ioGrid) const = 0; // pure virtual method
};

#endif

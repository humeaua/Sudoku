//
//  TwoOutOfThreeColumnVisitor.h
//  Sudoku
//
//  Created by Thomas Grandhaye on 10/02/13.
//
//

#ifndef __Sudoku__TwoOutOfThreeColumnVisitor__
#define __Sudoku__TwoOutOfThreeColumnVisitor__

#include <iostream>
#include "IVisitor.h"

class TwoOutOfThreeColumnVisitor : public IVisitor {
    
public:
    virtual bool Visit(Grid & ioGrid) const;
};

#endif /* defined(__Sudoku__TwoOutOfThreeColumnVisitor__) */

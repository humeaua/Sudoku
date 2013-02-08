//
//  TwoOutOfThreeRowVisitor.h
//  Sudoku
//
//  Created by Thomas Grandhaye on 08/02/13.
//
//

#ifndef __Sudoku__TwoOutOfThreeRowVisitor__
#define __Sudoku__TwoOutOfThreeRowVisitor__

#include <iostream>
#include "IVisitor.h"

class TwoOutOfThreeRowVisitor : public IVisitor {
    
public:
    virtual bool Visit(Grid & ioGrid) const;
};

#endif /* defined(__Sudoku__TwoOutOfThreeRowVisitor__) */

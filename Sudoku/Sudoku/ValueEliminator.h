//
//  ValueEliminator.h
//  Sudoku
//
//  Created by Alexandre HUMEAU on 22/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef Sudoku_ValueEliminator_h
#define Sudoku_ValueEliminator_h

#include <vector>
#include <set>

class ValueEliminator {
protected:
    std::vector<bool> bValues_;
    
public:
    ValueEliminator();
    virtual ~ValueEliminator();
    
    virtual bool flag(unsigned int iValue) const;
    virtual unsigned int availableValues() const;
    
    virtual void SetTrue(unsigned int iValue);
    
    virtual std::set<unsigned int> availableValue() const;
};

#endif

//
//  NonupleHolder.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 17/02/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "NonupleHolder.h"

NonupleHolder::NonupleHolder(TripleHolder & s1, TripleHolder & s2, TripleHolder & s3) : s1_(s1.GetLeft()), s2_(s1.GetCenter()), s3_(s1.GetRight()),s4_(s2.GetLeft()), s5_(s2.GetCenter()), s6_(s2.GetRight()),s7_(s3.GetLeft()), s8_(s3.GetCenter()), s9_(s3.GetRight())
{}

NonupleHolder::NonupleHolder(Cell &sCell1, Cell & sCell2, Cell & sCell3, Cell & sCell4, Cell & sCell5, Cell & sCell6, Cell & sCell7, Cell & sCell8, Cell & sCell9) : s1_(sCell1), s2_(sCell2), s3_(sCell3), s4_(sCell4), s5_(sCell5), s6_(sCell6), s7_(sCell7), s8_(sCell8), s9_(sCell9)
{}

Cell & NonupleHolder::Get1()
{
    return s1_;
}

Cell & NonupleHolder::Get2()
{
    return s2_;
}

Cell & NonupleHolder::Get3()
{
    return s3_;
}

Cell & NonupleHolder::Get4()
{
    return s4_;
}

Cell & NonupleHolder::Get5()
{
    return s5_;
}

Cell & NonupleHolder::Get6()
{
    return s6_;
}
Cell & NonupleHolder::Get7()
{
    return s7_;
}

Cell & NonupleHolder::Get8()
{
    return s8_;
}

Cell & NonupleHolder::Get9()
{
    return s9_;
}
//
//  Region.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 04/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Region.h"
#include <vector>
#include <cstring>
#include <sstream>

Region::Region(const std::string & cString)
{
    if (cString.size() != 9)
    {
        throw "Size of string does not match. Must be 9";
    }
    else
    {
        std::vector<unsigned int> cNumber(cString.size());
        std::string cTiret = "-";
        for (std::size_t i = 0 ; i < cString.size() ; ++i)
        {
            char cCharloc = cString[i];
            std::stringstream ss;
            ss << cCharloc;
            std::string cString;
            ss >> cString;
            
            if (strcmp(cTiret.c_str(), cString.c_str()))
            {
                cNumber[i] = (unsigned int)strtol(cString.c_str(), NULL, 10);
            }
            else
            {
                cNumber[i] = 0;
            }
        }
        if (cNumber[0] != 0)
        {
            sNO_ = Cell(cNumber[0]);
        }
        else
        {
            sNO_ = Cell();
        }
        if (cNumber[1] != 0)
        {
            sN_ = Cell(cNumber[1]);
        }
        else
        {
            sN_ = Cell();
        }
        if (cNumber[2] != 0)
        {
            sNE_ = Cell(cNumber[2]);
        }
        else
        {
            sNE_ = Cell();
        }
        if (cNumber[3] != 0)
        {
            sO_ = Cell(cNumber[3]);
        }
        else
        {
            sO_ = Cell();
        }
        if (cNumber[4] != 0)
        {
            sC_ = Cell(cNumber[4]);
        }
        else
        {
            sC_ = Cell();
        }
        if (cNumber[5] != 0)
        {
            sE_ = Cell(cNumber[5]);
        }
        else
        {
            sE_ = Cell();
        }
        if (cNumber[6] != 0)
        {
            sSO_ = Cell(cNumber[6]);
        }
        else
        {
            sSO_ = Cell();
        }
        if (cNumber[7] != 0)
        {
            sS_ = Cell(cNumber[7]);
        }
        else
        {
            sS_ = Cell();
        }
        if (cNumber[8] != 0)
        {
            sSE_ = Cell(cNumber[8]);
        }
        else
        {
            sSE_ = Cell();
        }
    }
}

Region::~Region()
{}

bool Region::IsFull() const
{
    return !sS_.IsEmpty() && !sSE_.IsEmpty() && !sSO_.IsEmpty() && !sE_.IsEmpty() && !sC_.IsEmpty() && !sE_.IsEmpty() && !sNE_.IsEmpty() && !sN_.IsEmpty() && sNO_.IsEmpty();
}
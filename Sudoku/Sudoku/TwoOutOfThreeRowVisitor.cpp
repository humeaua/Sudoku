//
//  TwoOutOfThreeRowVisitor.cpp
//  Sudoku
//
//  Created by Thomas Grandhaye on 08/02/13.
//
//

#include "TwoOutOfThreeRowVisitor.h"

bool TwoOutOfThreeRowVisitor::Visit(Grid & ioGrid) const
{
    bool bResult = false;
    // Regions set (NO,N,NE)
    for(int i =1; i<10; i++)
    {
        if(ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
        {
            if(!ioGrid.GetNO().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir NO.bottom.1
                    ioGrid.GetNO().BottomRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir NO.bottom.2
                    ioGrid.GetNO().BottomRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir NO.bottom.3
                    ioGrid.GetNO().BottomRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetNO().BottomRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetNO().BottomRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetNO().BottomRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetNO().BottomRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetN().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir N.bottom.1
                    ioGrid.GetN().BottomRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir N.bottom.2
                    ioGrid.GetN().BottomRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir N.bottom.3
                    ioGrid.GetN().BottomRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetN().BottomRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetN().BottomRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetN().BottomRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetN().BottomRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    } 
                }   
            }
            if(!ioGrid.GetNE().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir NE.bottom.1
                    ioGrid.GetNE().BottomRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir NE.bottom.2
                    ioGrid.GetNE().BottomRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir NE.bottom.3
                    ioGrid.GetNE().BottomRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetNE().BottomRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetNE().BottomRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetNE().BottomRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetNE().BottomRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
        }
        else if(ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
        {
            if(!ioGrid.GetNO().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir NO.middle.1
                    ioGrid.GetNO().MiddleRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir NO.middle.2
                    ioGrid.GetNO().MiddleRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir NO.middle.3
                    ioGrid.GetNO().MiddleRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                if (!bResultLoc)
                {
                    //  Count the missing value in the row. if equal to 1, we can fill the missing value
                    std::vector<int> iNMissingValues = ioGrid.GetNO().MiddleRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetNO().MiddleRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetNO().MiddleRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetNO().MiddleRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetN().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir N.middle.1
                    ioGrid.GetN().MiddleRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir N.middle.2
                    ioGrid.GetN().MiddleRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir N.middle.3
                    ioGrid.GetN().MiddleRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetN().MiddleRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetN().MiddleRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetN().MiddleRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetN().MiddleRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetNE().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir NE.middle.1
                    ioGrid.GetNE().MiddleRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir NE.middle.2
                    ioGrid.GetNE().MiddleRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir NE.middle.3
                    ioGrid.GetNE().MiddleRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetNE().MiddleRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetNE().MiddleRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetNE().MiddleRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetNE().MiddleRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
        }
        else if(!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
        {
            if(!ioGrid.GetNO().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir NO.top.1
                    ioGrid.GetNO().TopRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir NO.top.2
                    ioGrid.GetNO().TopRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir NO.top.3
                    ioGrid.GetNO().TopRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                } 
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetNO().TopRow().indexEmpty();
                if (!bResultLoc)
                {
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetNO().TopRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetNO().TopRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetNO().TopRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetN().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir N.top.1
                    ioGrid.GetN().TopRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir N.top.2
                    ioGrid.GetN().TopRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir N.top.3
                    ioGrid.GetN().TopRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetN().TopRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetN().TopRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetN().TopRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetN().TopRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetNE().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir NE.top.1
                    ioGrid.GetNE().TopRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir NE.top.2
                    ioGrid.GetNE().TopRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir NE.top.3
                    ioGrid.GetNE().TopRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                if (!bResultLoc)
                {
                    //  Count the missing value in the row. if equal to 1, we can fill the missing value
                    std::vector<int> iNMissingValues = ioGrid.GetNE().TopRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetNE().TopRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetNE().TopRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetNE().TopRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
        }
    }
    
    // Regions set (O,C,E)
    for(int i =1; i<10; i++)
    {
        if(ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && !ioGrid.IsPresentValueRow(6, i))
        {
            if(!ioGrid.GetO().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir O.bottom.1
                    ioGrid.GetO().BottomRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir O.bottom.2
                    ioGrid.GetO().BottomRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir O.bottom.3
                    ioGrid.GetO().BottomRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetO().BottomRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetO().BottomRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetO().BottomRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetO().BottomRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetC().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir C.bottom.1
                    ioGrid.GetC().BottomRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir C.bottom.2
                    ioGrid.GetC().BottomRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir C.bottom.3
                    ioGrid.GetC().BottomRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetC().BottomRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetC().BottomRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetC().BottomRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetC().BottomRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetE().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir E.bottom.1
                    ioGrid.GetE().BottomRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir E.bottom.2
                    ioGrid.GetE().BottomRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir E.bottom.3
                    ioGrid.GetE().BottomRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetE().BottomRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetE().BottomRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetE().BottomRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetE().BottomRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
        }
        else if(ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
        {
            if(!ioGrid.GetO().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir O.middle.1
                    ioGrid.GetO().MiddleRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir O.middle.2
                    ioGrid.GetO().MiddleRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir O.middle.3
                    ioGrid.GetO().MiddleRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetO().MiddleRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetO().MiddleRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetO().MiddleRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetO().MiddleRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetC().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir C.middle.1
                    ioGrid.GetC().MiddleRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir C.middle.2
                    ioGrid.GetC().MiddleRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir C.middle.3
                    ioGrid.GetC().MiddleRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetC().MiddleRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetC().MiddleRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetC().MiddleRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetC().MiddleRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetE().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir E.middle.1
                    ioGrid.GetE().MiddleRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir E.middle.2
                    ioGrid.GetE().MiddleRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir E.middle.3
                    ioGrid.GetE().MiddleRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetE().MiddleRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetE().MiddleRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetE().MiddleRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetE().MiddleRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
        }
        else if(!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
        {
            if(!ioGrid.GetO().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir O.top.1
                    ioGrid.GetO().TopRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir O.top.2
                    ioGrid.GetO().TopRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir O.top.3
                    ioGrid.GetO().TopRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetO().TopRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetO().TopRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetO().TopRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetO().TopRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetC().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir C.top.1
                    ioGrid.GetC().TopRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir C.top.2
                    ioGrid.GetC().TopRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir C.top.3
                    ioGrid.GetC().TopRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetC().TopRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetC().TopRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetC().TopRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetC().TopRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetE().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir E.top.1
                    ioGrid.GetE().TopRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir E.top.2
                    ioGrid.GetE().TopRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir E.top.3
                    ioGrid.GetE().TopRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetO().TopRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetE().TopRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetE().TopRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetE().TopRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
        }
    }
    
    
    // Regions set (SO,S,SE)
    for(int i =1; i<10; i++)
    {
        if(ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && !ioGrid.IsPresentValueRow(9, i))
        {
            if(!ioGrid.GetSO().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir SO.bottom.1
                    ioGrid.GetSO().BottomRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir SO.bottom.2
                    ioGrid.GetSO().BottomRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir SO.bottom.3
                    ioGrid.GetSO().BottomRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetSO().BottomRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetSO().BottomRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetSO().BottomRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetSO().BottomRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetS().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir S.bottom.1
                    ioGrid.GetS().BottomRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir S.bottom.2
                    ioGrid.GetS().BottomRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir S.bottom.3
                    ioGrid.GetS().BottomRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetS().BottomRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetS().BottomRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetS().BottomRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetS().BottomRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetSE().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir SE.bottom.1
                    ioGrid.GetSE().BottomRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir SE.bottom.2
                    ioGrid.GetSE().BottomRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir SE.bottom.3
                    ioGrid.GetSE().BottomRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetSE().BottomRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetSE().BottomRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetSE().BottomRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetSE().BottomRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
        }
        else if(ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
        {
            if(!ioGrid.GetSO().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir SO.middle.1
                    ioGrid.GetSO().MiddleRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir SO.middle.2
                    ioGrid.GetSO().MiddleRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir SO.middle.3
                    ioGrid.GetSO().MiddleRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetSO().MiddleRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetSO().MiddleRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetSO().MiddleRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetSO().MiddleRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetS().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir S.middle.1
                    ioGrid.GetS().MiddleRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir S.middle.2
                    ioGrid.GetS().MiddleRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir S.middle.3
                    ioGrid.GetS().MiddleRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetS().MiddleRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetS().MiddleRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetS().MiddleRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetS().MiddleRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetSE().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir SE.middle.1
                    ioGrid.GetSE().MiddleRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir SE.middle.2
                    ioGrid.GetSE().MiddleRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir SE.middle.3
                    ioGrid.GetSE().MiddleRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetSE().MiddleRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetSE().MiddleRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetSE().MiddleRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetSE().MiddleRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
        }
        else if(!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
        {
            if(!ioGrid.GetSO().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir SO.top.1
                    ioGrid.GetSO().TopRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir SO.top.2
                    ioGrid.GetSO().TopRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
                {
                    // remplir SO.top.3
                    ioGrid.GetSO().TopRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetSO().TopRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetSO().TopRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetSO().TopRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetSO().TopRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetS().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir S.top.1
                    ioGrid.GetS().TopRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir S.top.2
                    ioGrid.GetS().TopRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
                {
                    // remplir S.top.3
                    ioGrid.GetS().TopRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetS().TopRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetS().TopRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetS().TopRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetS().TopRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
            if(!ioGrid.GetSE().isValuePresent(i))
            {
                bool bResultLoc = false;
                if(!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir SE.top.1
                    ioGrid.GetSE().TopRow().GetLeft() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir SE.top.2
                    ioGrid.GetSE().TopRow().GetCenter() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                else if(ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
                {
                    // remplir SE.top.3
                    ioGrid.GetSE().TopRow().GetRight() = i;
                    bResultLoc = true;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                if (!bResultLoc)
                {
                    std::vector<int> iNMissingValues = ioGrid.GetSE().TopRow().indexEmpty();
                    if (iNMissingValues.size() == 1)
                    {
                        switch (iNMissingValues[0]) {
                            case 1:
                                ioGrid.GetSE().TopRow().GetLeft() = i;
                                break;
                            case 2:
                                ioGrid.GetSE().TopRow().GetCenter() = i;
                                break;
                            case 3:
                                ioGrid.GetSE().TopRow().GetRight() = i;
                                break;
                            default:
                                break;
                        }
                        bResult = true;
                    }
                }
            }
        }
    }
    return bResult;
}
//
//  TwoOutOfThreeColumnVisitor.cpp
//  Sudoku
//
//  Created by Thomas Grandhaye on 10/02/13.
//
//

#include "TwoOutOfThreeColumnVisitor.h"

bool TwoOutOfThreeColumnVisitor::Visit(Grid & ioGrid) const
{
    bool bResult = false;
    
    //  Region NO,O,SO
    for (int i = 0 ; i < 10 ; ++i)
    {
        if (ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && !ioGrid.IsPresentValueColumn(3, i))
        {
            if (!ioGrid.GetNO().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NO.left.1
                    ioGrid.GetNO().LeftColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NO.left.2
                    ioGrid.GetNO().LeftColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NO.left.3
                    ioGrid.GetNO().LeftColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetNO().LeftColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetNO().LeftColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetNO().LeftColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetNO().LeftColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetO().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir O.left.1
                    ioGrid.GetO().LeftColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir O.left.2
                    ioGrid.GetO().LeftColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && !ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir O.left.3
                    ioGrid.GetO().LeftColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetO().LeftColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetO().LeftColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetO().LeftColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetO().LeftColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetSO().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(7, i))
                {
                    //  remplir SO.left.1
                    ioGrid.GetSO().LeftColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && !ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(7, i))
                {
                    //  remplir SO.left.2
                    ioGrid.GetSO().LeftColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && !ioGrid.IsPresentValueRow(7, i))
                {
                    //  remplir SO.left.3
                    ioGrid.GetSO().LeftColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetSO().LeftColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetSO().LeftColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetSO().LeftColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetSO().LeftColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
        }
        else if (ioGrid.IsPresentValueColumn(1, i) && !ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
        {
            if (!ioGrid.GetNO().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NO.center.1
                    ioGrid.GetNO().MiddleColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NO.center.2
                    ioGrid.GetNO().MiddleColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NO.center.3
                    ioGrid.GetNO().MiddleColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetNO().MiddleColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetNO().MiddleColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetNO().MiddleColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetNO().MiddleColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetO().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir O.center.1
                    ioGrid.GetO().MiddleColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir O.center.2
                    ioGrid.GetO().MiddleColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && !ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir O.center.3
                    ioGrid.GetO().MiddleColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetO().MiddleColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetO().MiddleColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetO().MiddleColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetO().MiddleColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetSO().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SO.center.1
                    ioGrid.GetSO().MiddleColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && !ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SO.center.2
                    ioGrid.GetSO().MiddleColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && !ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SO.center.3
                    ioGrid.GetSO().MiddleColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetSO().MiddleColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetSO().MiddleColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetSO().MiddleColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetSO().MiddleColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
        }
        else if (!ioGrid.IsPresentValueColumn(1, i) && ioGrid.IsPresentValueColumn(2, i) && ioGrid.IsPresentValueColumn(3, i))
        {
            if (!ioGrid.GetNO().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NO.right.1
                    ioGrid.GetNO().RightColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NO.right.2
                    ioGrid.GetNO().RightColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NO.right.3
                    ioGrid.GetNO().RightColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetNO().RightColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetNO().RightColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetNO().RightColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetNO().RightColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetO().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir O.right.1
                    ioGrid.GetO().RightColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir O.right.2
                    ioGrid.GetO().RightColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && !ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir O.right.3
                    ioGrid.GetO().RightColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetO().RightColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetO().RightColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetO().RightColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetO().RightColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetSO().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SO.right.1
                    ioGrid.GetSO().RightColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && !ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SO.right.2
                    ioGrid.GetSO().RightColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && !ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SO.right.3
                    ioGrid.GetSO().RightColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetSO().RightColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetSO().RightColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetSO().RightColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetSO().RightColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
        }
    }
    
    //  Region N,C,S
    for (int i = 0 ; i < 10 ; ++i)
    {
        if (ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && !ioGrid.IsPresentValueColumn(6, i))
        {
            if (!ioGrid.GetN().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir N.left.1
                    ioGrid.GetN().LeftColumn().T() = 1;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir N.left.2
                    ioGrid.GetN().LeftColumn().C() = 1;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir N.left.3
                    ioGrid.GetN().LeftColumn().B() = 1;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetN().LeftColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetN().LeftColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetN().LeftColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetN().LeftColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetC().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir C.left.1
                    ioGrid.GetC().LeftColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir C.left.2
                    ioGrid.GetC().LeftColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && !ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir C.left.3
                    ioGrid.GetC().LeftColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetC().LeftColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetC().LeftColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetC().LeftColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetC().LeftColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetS().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir S.left.1
                    ioGrid.GetS().LeftColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && !ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir S.left.2
                    
                    ioGrid.GetS().LeftColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && !ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir S.left.3
                    ioGrid.GetS().LeftColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetN().LeftColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetS().LeftColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetS().LeftColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetS().LeftColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
        }
        else if (ioGrid.IsPresentValueColumn(4, i) && !ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
        {
            if (!ioGrid.GetN().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir N.center.1
                    ioGrid.GetN().MiddleColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir N.center.2
                    ioGrid.GetN().MiddleColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir N.center.3
                    ioGrid.GetN().MiddleColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetN().MiddleColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetN().MiddleColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetN().MiddleColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetN().MiddleColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetC().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir C.center.1
                    ioGrid.GetC().MiddleColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir C.center.2
                    ioGrid.GetC().MiddleColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && !ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir C.center.3
                    ioGrid.GetC().MiddleColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetC().MiddleColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetC().MiddleColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetC().MiddleColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetC().MiddleColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetS().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir S.center.1
                    ioGrid.GetS().MiddleColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && !ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir S.center.2
                    ioGrid.GetS().MiddleColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && !ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir S.center.3
                    ioGrid.GetS().MiddleColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetS().MiddleColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetS().MiddleColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetS().MiddleColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetS().MiddleColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
        }
        else if (!ioGrid.IsPresentValueColumn(4, i) && ioGrid.IsPresentValueColumn(5, i) && ioGrid.IsPresentValueColumn(6, i))
        {
            if (!ioGrid.GetN().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir N.right.1
                    ioGrid.GetN().RightColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir N.right.2
                    ioGrid.GetN().RightColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir N.right.3
                    ioGrid.GetN().RightColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetN().RightColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetN().RightColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetN().RightColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetN().RightColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetC().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir C.right.1
                    ioGrid.GetC().RightColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir C.right.2
                    ioGrid.GetC().RightColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && !ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir C.right.3
                    ioGrid.GetC().RightColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetC().RightColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetC().RightColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetC().RightColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetC().RightColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetS().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir S.right.1
                    ioGrid.GetS().RightColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && !ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir S.right.2
                    ioGrid.GetS().RightColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && !ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir S.right.3
                    ioGrid.GetS().RightColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetS().RightColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetS().RightColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetS().RightColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetS().RightColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
        }
    }
    
    //  Region NE,E,SE
    for (int i = 0 ; i < 10 ; ++i)
    {
        if (ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && !ioGrid.IsPresentValueColumn(9, i))
        {
            if (!ioGrid.GetNE().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NE.left.1
                    ioGrid.GetNE().LeftColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NE.left.2
                    ioGrid.GetNE().LeftColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NE.left.3
                    ioGrid.GetNE().LeftColumn().C() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetNE().LeftColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetNE().LeftColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetNE().LeftColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetNE().LeftColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetE().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir E.left.1
                    ioGrid.GetE().LeftColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir E.left.2
                    ioGrid.GetE().LeftColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && !ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir E.left.3
                    ioGrid.GetE().LeftColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetE().LeftColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetE().LeftColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetE().LeftColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetE().LeftColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetSE().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SE.left.1
                    ioGrid.GetSE().LeftColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && !ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SE.left.2
                    ioGrid.GetSE().LeftColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && !ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SE.left.3
                    ioGrid.GetSE().LeftColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetSE().LeftColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetSE().LeftColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetSE().LeftColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetSE().LeftColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
        }
        else if (ioGrid.IsPresentValueColumn(7, i) && !ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
        {
            if (!ioGrid.GetNE().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NE.center.1
                    ioGrid.GetNE().MiddleColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NE.center.2
                    ioGrid.GetNE().MiddleColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NE.center.3
                    ioGrid.GetNE().MiddleColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetNE().MiddleColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetNE().MiddleColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetNE().MiddleColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetNE().MiddleColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetE().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir E.center.1
                    ioGrid.GetE().MiddleColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir E.center.2
                    ioGrid.GetE().MiddleColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && !ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir E.center.3
                    ioGrid.GetE().MiddleColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetE().MiddleColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetE().MiddleColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetE().MiddleColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetE().MiddleColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetSE().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SE.center.1
                    ioGrid.GetSE().MiddleColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && !ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SE.center.2
                    ioGrid.GetSE().MiddleColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && !ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SE.center.3
                    ioGrid.GetSE().MiddleColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetSE().MiddleColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetSE().MiddleColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetSE().MiddleColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetSE().MiddleColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
        }
        else if (!ioGrid.IsPresentValueColumn(7, i) && ioGrid.IsPresentValueColumn(8, i) && ioGrid.IsPresentValueColumn(9, i))
        {
            if (!ioGrid.GetNE().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NE.right.1
                    ioGrid.GetNE().RightColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && !ioGrid.IsPresentValueRow(2, i) && ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NE.right.2
                    ioGrid.GetNE().RightColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(1, i) && ioGrid.IsPresentValueRow(2, i) && !ioGrid.IsPresentValueRow(3, i))
                {
                    //  remplir NE.right.3
                    ioGrid.GetNE().RightColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetNE().RightColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetNE().RightColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetNE().RightColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetNE().RightColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetE().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir E.right.1
                    ioGrid.GetE().RightColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && !ioGrid.IsPresentValueRow(5, i) && ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir E.right.2
                    ioGrid.GetE().RightColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(4, i) && ioGrid.IsPresentValueRow(5, i) && !ioGrid.IsPresentValueRow(6, i))
                {
                    //  remplir E.right.3
                    ioGrid.GetE().RightColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetE().RightColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetE().RightColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetE().RightColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetE().RightColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
            if (!ioGrid.GetSE().isValuePresent(i))
            {
                if (!ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SE.right.1
                    ioGrid.GetSE().RightColumn().T() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && !ioGrid.IsPresentValueRow(8, i) && ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SE.right.2
                    ioGrid.GetSE().RightColumn().C() = i;
                    bResult = true;
                }
                if (ioGrid.IsPresentValueRow(7, i) && ioGrid.IsPresentValueRow(8, i) && !ioGrid.IsPresentValueRow(9, i))
                {
                    //  remplir SE.right.3
                    ioGrid.GetSE().RightColumn().B() = i;
                    bResult = true;
                }
                //  Count the missing value in the row. if equal to 1, we can fill the missing value
                std::vector<int> iNMissingValues = ioGrid.GetSE().RightColumn().indexEmpty();
                if (iNMissingValues.size() == 1)
                {
                    switch (iNMissingValues[0]) {
                        case 1:
                            ioGrid.GetSE().RightColumn().T() = i;
                            break;
                        case 2:
                            ioGrid.GetSE().RightColumn().C() = i;
                            break;
                        case 3:
                            ioGrid.GetSE().RightColumn().B() = i;
                            break;
                        default:
                            break;
                    }
                    bResult = true;
                }
            }
        }
    }
    return bResult;
}
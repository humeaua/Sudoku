//
//  Grid.cpp
//  Sudoku
//
//  Created by Alexandre HUMEAU on 05/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Grid.h"
#include "Column.h"

Grid::Grid(const Region & sRegionNO, const Region & sRegionN, const Region & sRegionNE, const Region & sRegionO, const Region & sRegionC, const Region & sRegionE, const Region & sRegionSO, const Region & sRegionS, const Region & sRegionSE) :

sRegionNO_(sRegionNO),
sRegionN_(sRegionN),
sRegionNE_(sRegionNE),
sRegionO_(sRegionO),
sRegionC_(sRegionC),
sRegionE_(sRegionE), 
sRegionSO_(sRegionSO), 
sRegionS_(sRegionS), 
sRegionSE_(sRegionSE)

{}

Grid::~Grid()
{}

bool Grid::IsFull() const
{
    return sRegionC_.IsFull() && sRegionE_.IsFull() && sRegionN_.IsFull() && sRegionNE_.IsFull() && sRegionNO_.IsFull() && sRegionO_.IsFull() && sRegionS_.IsFull() && sRegionSE_.IsFull() && sRegionSO_.IsFull();
}

RegionHolder Grid::GetNO()
{
    return RegionHolder(sRegionNO_);
}

RegionHolder Grid::GetNE()
{
    return RegionHolder(sRegionNE_);
}

RegionHolder Grid::GetN()
{
    return RegionHolder(sRegionN_);
}

RegionHolder Grid::GetO()
{
    return RegionHolder(sRegionO_);
}

RegionHolder Grid::GetC()
{
    return RegionHolder(sRegionC_);
}

RegionHolder Grid::GetE()
{
    return RegionHolder(sRegionE_);
}

RegionHolder Grid::GetS()
{
    return RegionHolder(sRegionS_);
}

RegionHolder Grid::GetSE()
{
    return RegionHolder(sRegionSE_);
}

RegionHolder Grid::GetSO()
{
    return RegionHolder(sRegionSO_);
}

bool Grid::Accept(const IVisitor &sVisitor)
{
    return sVisitor.Visit(*this);
}

bool Grid::IsPresentValueColumn(int iCol, int intValue)
{
    bool res = false;
    switch(iCol)
    {
        case 1:
        {
        if((*this).GetNO().LeftColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetO().LeftColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSO().LeftColumn().isValuePresent(intValue)){res=true;}
        break;}
        
        case 2:
        {
        if((*this).GetNO().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetO().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSO().MiddleColumn().isValuePresent(intValue)){res=true;}
        break;}
        
        case 3:
        {
        if((*this).GetNO().RightColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetO().RightColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSO().RightColumn().isValuePresent(intValue)){res=true;}
        break;}
        
        case 4:
        {
        if((*this).GetN().LeftColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetC().LeftColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetS().LeftColumn().isValuePresent(intValue)){res=true;}
        break;}

        case 5:
        {
        if((*this).GetN().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetC().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetS().MiddleColumn().isValuePresent(intValue)){res=true;}
        break;}
        
        case 6:
        {
        if((*this).GetN().RightColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetC().RightColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetS().RightColumn().isValuePresent(intValue)){res=true;}
        break;}
        case 7:
        {
        if((*this).GetNE().LeftColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetE().LeftColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSE().LeftColumn().isValuePresent(intValue)){res=true;}
        break;}
        case 8:
        {
        if((*this).GetNE().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetE().MiddleColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSE().MiddleColumn().isValuePresent(intValue)){res=true;}
        break;}
        case 9:
        {
        if((*this).GetNE().RightColumn().isValuePresent(intValue)){res=true;}
        else if ((*this).GetE().RightColumn().isValuePresent(intValue)){res=true;}
        else if((*this).GetSE().RightColumn().isValuePresent(intValue)){res=true;}
        break;}
    }
    return res;
}

bool Grid::IsPresentValueRow(int iRow, int intValue)
{
    bool res = false;
    switch(iRow)
    {
        case 1:
        {
        if((*this).GetNO().TopRow().isValuePresent(intValue)){res=true;}
        else if ((*this).GetN().TopRow().isValuePresent(intValue)){res=true;}
        else if((*this).GetNE().TopRow().isValuePresent(intValue)){res=true;}
        break;}
        
        case 2:
        {
        if((*this).GetNO().MiddleRow().isValuePresent(intValue)){res=true;}
        else if ((*this).GetN().MiddleRow().isValuePresent(intValue)){res=true;}
        else if((*this).GetNE().MiddleRow().isValuePresent(intValue)){res=true;}
        break;}
        
        case 3:
        {
        if((*this).GetNO().BottomRow().isValuePresent(intValue)){res=true;}
        else if ((*this).GetN().BottomRow().isValuePresent(intValue)){res=true;}
        else if((*this).GetNE().BottomRow().isValuePresent(intValue)){res=true;}
        break;}
        
        case 4:
        {
        if((*this).GetO().TopRow().isValuePresent(intValue)){res=true;}
        else if ((*this).GetC().TopRow().isValuePresent(intValue)){res=true;}
        else if((*this).GetE().TopRow().isValuePresent(intValue)){res=true;}
        break;}
        
        case 5:
        {
        if((*this).GetO().MiddleRow().isValuePresent(intValue)){res=true;}
        else if ((*this).GetC().MiddleRow().isValuePresent(intValue)){res=true;}
        else if((*this).GetE().MiddleRow().isValuePresent(intValue)){res=true;}
        break;}
        
        case 6:
        {
        if((*this).GetO().BottomRow().isValuePresent(intValue)){res=true;}
        else if ((*this).GetC().BottomRow().isValuePresent(intValue)){res=true;}
        else if((*this).GetE().BottomRow().isValuePresent(intValue)){res=true;}
        break;}
        
        case 7:
        {
        if((*this).GetSO().TopRow().isValuePresent(intValue)){res=true;}
        else if ((*this).GetS().TopRow().isValuePresent(intValue)){res=true;}
        else if((*this).GetSE().TopRow().isValuePresent(intValue)){res=true;}
        break;}
        
        case 8:
        {
        if((*this).GetSO().MiddleRow().isValuePresent(intValue)){res=true;}
        else if ((*this).GetS().MiddleRow().isValuePresent(intValue)){res=true;}
        else if((*this).GetSE().MiddleRow().isValuePresent(intValue)){res=true;}
        break;}
        
        case 9:
        {
        if((*this).GetSO().BottomRow().isValuePresent(intValue)){res=true;}
        else if ((*this).GetS().BottomRow().isValuePresent(intValue)){res=true;}
        else if((*this).GetSE().BottomRow().isValuePresent(intValue)){res=true;}
        break;}
    }
    return res;
}

void Grid::Print()
{
    //  Method to print the grid in the console
    std::cout << std::endl;
    //  1st row
    std::cout << GetNO().GetNO() << " " << GetNO().GetN() << " " << GetNO().GetNE() << " " << GetN().GetNO() << " " << GetN().GetN() << " " << GetN().GetNE() << " " << GetNE().GetNO() << " " << GetNE().GetN() << " " << GetNE().GetNE() << std::endl;
    //  2nd row
    std::cout << GetNO().GetO() << " " << GetNO().GetC() << " " << GetNO().GetE() << " " << GetN().GetO() << " " << GetN().GetC() << " " << GetN().GetE() << " " << GetNE().GetO() << " " << GetNE().GetC() << " " << GetNE().GetE() << std::endl;
    //  3rd row
    std::cout << GetNO().GetSO() << " " << GetNO().GetS() << " " << GetNO().GetSE() << " " << GetN().GetSO() << " " << GetN().GetS() << " " << GetN().GetSE() << " " << GetNE().GetSO() << " " << GetNE().GetS() << " " << GetNE().GetSE() << std::endl;
    
    //  4th row
    std::cout << GetO().GetNO() << " " << GetO().GetN() << " " << GetO().GetNE() << " " << GetC().GetNO() << " " << GetC().GetN() << " " << GetC().GetNE() << " " << GetE().GetNO() << " " << GetE().GetN() << " " << GetE().GetNE() << std::endl;
    //  5th row
    std::cout << GetO().GetO() << " " << GetO().GetC() << " " << GetO().GetE() << " " << GetC().GetO() << " " << GetC().GetC() << " " << GetC().GetE() << " " << GetE().GetO() << " " << GetE().GetC() << " " << GetE().GetE() << std::endl;
    //  6th row
    std::cout << GetO().GetSO() << " " << GetO().GetS() << " " << GetO().GetSE() << " " << GetC().GetSO() << " " << GetC().GetS() << " " << GetC().GetSE() << " " << GetE().GetSO() << " " << GetE().GetS() << " " << GetE().GetSE() << std::endl;
    
    //  7th row
    std::cout << GetSO().GetNO() << " " << GetSO().GetN() << " " << GetSO().GetNE() << " " << GetS().GetNO() << " " << GetS().GetN() << " " << GetS().GetNE() << " " << GetSE().GetNO() << " " << GetSE().GetN() << " " << GetSE().GetNE() << std::endl;
    //  8th row
    std::cout << GetSO().GetO() << " " << GetSO().GetC() << " " << GetSO().GetE() << " " << GetS().GetO() << " " << GetS().GetC() << " " << GetS().GetE() << " " << GetSE().GetO() << " " << GetSE().GetC() << " " << GetSE().GetE() << std::endl;
    //  9th row
    std::cout << GetSO().GetSO() << " " << GetSO().GetS() << " " << GetSO().GetSE() << " " << GetS().GetSO() << " " << GetS().GetS() << " " << GetS().GetSE() << " " << GetSE().GetSO() << " " << GetSE().GetS() << " " << GetSE().GetSE() << std::endl;
    
    std::cout << std::endl;
}

Column Grid::Col1()
{
    ColumnHolder sH = GetNO().LeftColumn(), sC = GetO().LeftColumn(), sB = GetSO().LeftColumn();
    return Column(sH, sC, sB);
}

Column Grid::Col2()
{
    ColumnHolder sH = GetNO().MiddleColumn(), sC = GetO().MiddleColumn(), sB = GetSO().MiddleColumn();
    return Column(sH, sC, sB);
}
Column Grid::Col3()
{
    ColumnHolder sH = GetNO().RightColumn(), sC = GetO().RightColumn(), sB = GetSO().RightColumn();
    return Column(sH, sC, sB);
}
Column Grid::Col4()
{
    ColumnHolder sH = GetN().LeftColumn(), sC = GetC().LeftColumn(), sB = GetS().LeftColumn();
    return Column(sH, sC, sB);
}
Column Grid::Col5()
{
    ColumnHolder sH = GetN().MiddleColumn(), sC = GetC().MiddleColumn(), sB = GetS().MiddleColumn();
    return Column(sH, sC, sB);
}
Column Grid::Col6()
{
    ColumnHolder sH = GetN().RightColumn(), sC = GetC().RightColumn(), sB = GetS().RightColumn();
    return Column(sH, sC, sB);
}
Column Grid::Col7()
{
    ColumnHolder sH = GetNE().LeftColumn(), sC = GetE().LeftColumn(), sB = GetSE().LeftColumn();
    return Column(sH, sC, sB);
}
Column Grid::Col8()
{
    ColumnHolder sH = GetNE().MiddleColumn(), sC = GetE().MiddleColumn(), sB = GetSE().MiddleColumn();
    return Column(sH, sC, sB);
}
Column Grid::Col9()
{
    ColumnHolder sH = GetNE().RightColumn(), sC = GetE().RightColumn(), sB = GetSE().RightColumn();
    return Column(sH, sC, sB);
}

Row Grid::Row1()
{
    RowHolder rH = GetNO().TopRow(), rC = GetN().TopRow(), rB = GetNE().TopRow();
    return Row(rH, rC, rB);
}
Row Grid::Row2()
{
    RowHolder rH = GetNO().MiddleRow(), rC = GetN().MiddleRow(), rB = GetNE().MiddleRow();
    return Row(rH, rC, rB);
}
Row Grid::Row3()
{
    RowHolder rH = GetNO().BottomRow(), rC = GetN().BottomRow(), rB = GetNE().BottomRow();
    return Row(rH, rC, rB);
}
Row Grid::Row4()
{
    RowHolder rH = GetO().TopRow(), rC = GetC().TopRow(), rB = GetE().TopRow();
    return Row(rH, rC, rB);
}
Row Grid::Row5()
{
    RowHolder rH = GetO().MiddleRow(), rC = GetC().MiddleRow(), rB = GetE().MiddleRow();
    return Row(rH, rC, rB);
}
Row Grid::Row6()
{
    RowHolder rH = GetO().BottomRow(), rC = GetC().BottomRow(), rB = GetE().BottomRow();
    return Row(rH, rC, rB);
}
Row Grid::Row7()
{
    RowHolder rH = GetSO().TopRow(), rC = GetS().TopRow(), rB = GetSE().TopRow();
    return Row(rH, rC, rB);
}
Row Grid::Row8()
{
    RowHolder rH = GetSO().MiddleRow(), rC = GetS().MiddleRow(), rB = GetSE().MiddleRow();
    return Row(rH, rC, rB);
}
Row Grid::Row9()
{
    RowHolder rH = GetSO().BottomRow(), rC = GetS().BottomRow(), rB = GetSE().BottomRow();
    return Row(rH, rC, rB);
}



//
//  Stock.cpp
//  Huffman
//
//  Created by Prashanti Pokharel on 11/12/21.
//

#include "Stock.h"
#include<iostream>

using namespace std;

Stock::Stock(const string& name, const string& symbol, double price)
{
    this->name = name;
    this->symbol = symbol;
    this->price = price;
}

Stock::Stock(const Stock& s)
{
    this->name = s.name;
    this->symbol = s.symbol;
    this->price = s.price;
}

void Stock::display() const
{
    cout << "Name is " << name << ", "
        << "Symbol is " << symbol << ", "
        << "Price is " << price << ".\n";
}

std::ostream& operator<< (ostream& out, const Stock& matrix)
{
    out  << matrix.name << matrix.symbol<< matrix.price << std::endl;
    return out;
}

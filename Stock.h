//
//  Stock.h
//  Huffman
//
//  Created by Prashanti Pokharel on 11/12/21.
//

#ifndef Stock_h
#define Stock_h
#include<string>

class Stock {
private:
    std::string name,
        symbol;
    double price;

public:

    Stock(const std::string& name = "", const std::string& symbol = "", double price = 0);
    Stock(const Stock& s);
    void display() const;

    // get functions
    std::string getName() const;
    std::string getSymbol() const;
    double getPrice() const;

    //bool functions
    bool operator==(const Stock& rhs) const;
    bool operator!=(const Stock& rhs) const;
    bool operator>(const Stock& rhs) const;
    bool operator<(const Stock& rhs) const;


    friend std::ostream& operator<< (std::ostream& out, const Stock& matrix);

};

inline
std::string Stock::getName() const
{
    return name;
}

inline
std::string Stock::getSymbol() const
{
    return symbol;
}

inline
double Stock::getPrice() const
{
    return price;
}

//bool functions
inline
bool Stock::operator==(const Stock& rhs) const
{
    return (symbol == rhs.symbol);
}

inline
bool Stock::operator!=(const Stock& rhs) const
{
    return (symbol != rhs.symbol);

}

inline
bool Stock::operator>(const Stock& rhs) const
{
    return (symbol > rhs.symbol);
}

inline
bool Stock::operator<(const Stock& rhs) const
{
    return (symbol < rhs.symbol);
}

#endif /* Stock_h */

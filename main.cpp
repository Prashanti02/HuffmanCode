//
//  main.cpp
//  Huffman
//
//  Created by Prashanti Pokharel on 11/12/21.
//

// This file contains different functions to read stocks from a file to a Huffman tree and then display the path for each stocks.

#include "Stock.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

template<typename T>
struct Node {
    Node* left;
    Node* right;
    double frequency;
    T value;
    Node();
};

template<typename T>
Node<T>::Node() {
    left = nullptr;
    right = nullptr;
    frequency = 0.0;
}

int readStocks(const string& filename, Stock*& stocks, double*& freq);
Node<Stock>* createHuffmanTree(Stock stocks[], double freqs[], int size);
void printPathsToStocks(Node<Stock>* rootPtr, int size);
void printPaths(Node<Stock>* node, int path[], int pathlen, int lr);
void printArray(int paths[], int pathlen, Node<Stock>* leaf);
void displayStockList(Node<Stock>* rootPtr, const string& sentence);
bool isLeaf(Node<Stock>* node);

int main()
{
    string nFile = "HuffmanStocks.txt";
    Stock* stock;
    double* fq;
    Node <Stock>* elements;
    int total;

    string s = "1111110100111110110";
    total = readStocks(nFile, stock, fq);
    elements = createHuffmanTree(stock, fq, total);
    printPathsToStocks(elements, total);
    cout << endl << "The sentence refers to stocks: " << endl;
    displayStockList(elements, s);

    system("pause");
    return 0;
}

//*****************************************************************************************************

int readStocks(const string& filename, Stock*& stocks, double*& freq)
{
    int total = 0;
    string name, symbol;
    double price;
    ifstream fin;
    fin.open(filename);
    if (fin) {
        fin >> total;
        fin.ignore();
        stocks = new Stock[total];
        freq = new double[total];
        for (int i = 0; i < total; i++)
        {
            getline(fin, name);
            getline(fin, symbol);
            fin >> price;
            fin.ignore();
            fin >> freq[i];
            fin.ignore();
            stocks[i] = Stock(name, symbol, price);
        }
    }
    fin.close();
    return total;
}

//*****************************************************************************************************

Node <Stock>* createHuffmanTree(Stock stocks[], double freqs[], int size)
{
    Node <Stock>** elements = nullptr;
    elements = new Node<Stock> * [size];

    for (int i = 0; i < size; i++)
    {
        elements[i] = new Node<Stock>;
        elements[i]->value = stocks[i];
        elements[i]->frequency = freqs[i];
        elements[i]->left = nullptr;
        elements[i]->right = nullptr;
    }

    while (size > 1)
    {
        int index1;
        int index2;
        double freq1;
        double freq2;

        index1 = index2 = 0;
        freq1 = freq2 = numeric_limits<double>::max();

        for (int i = 0; i < size; i++)
        {
            if (elements[i]->frequency < freq1)
            {
                freq2 = freq1;
                index2 = index1;
                freq1 = elements[i]->frequency;
                index1 = i;
            }

            else if ((elements[i]->frequency < freq2) && (i != index1))
            {
                freq2 = elements[i]->frequency;
                index2 = i;
            }
        }

        Node <Stock>* newNode;
        newNode = new Node<Stock>;
        newNode->left = elements[index1];
        newNode->right = elements[index2];
        newNode->frequency = freq1 + freq2;

        elements[min(index1, index2)] = newNode;
        for (int i = max(index1, index2); i < size; ++i)
            elements[i] = elements[i + 1];

        size--;
    }

    return *elements;
}

//*****************************************************************************************************

void printPathsToStocks(Node<Stock>* rootPtr, int size)
{
    int* path;
    path = new int[size];
    int pathLen = 0;
    int lr = -1;

    printPaths(rootPtr, path, pathLen, lr);
}

//*****************************************************************************************************

void printPaths(Node<Stock>* node, int path[], int pathLen, int lr)
{
    if (node != nullptr)
    {
        if (lr != -1)
        {
            path[pathLen] = lr;
            ++pathLen;
        }

        if ((node->left == nullptr) && (node->right == nullptr))
        {
            printArray(path, pathLen, node);
        }

        else
        {
            printPaths(node->left, path, pathLen, 0);
            printPaths(node->right, path, pathLen, 1);
        }
    }
}

//*****************************************************************************************************

void displayStockList(Node <Stock>* rootPtr, const string& sentence)
{
    int i = 0;
    Node<Stock>* start = rootPtr;

    while (sentence[i] != '\0')
    {
        if (sentence[i] == '0')
            rootPtr = rootPtr->left;

        if (sentence[i] == '1')
            rootPtr = rootPtr->right;

        if (isLeaf(rootPtr) == true)
        {
            cout << rootPtr->value << "\n";
            rootPtr = start;
        }

        i++;
    }

}

//*****************************************************************************************************

void printArray(int path[], int pathLen, Node<Stock>* leaf)
{
    cout << leaf->value << ": ";
    for (int i = 0; i < pathLen; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

//*****************************************************************************************************

bool isLeaf(Node<Stock>* node)
{
    if (node == nullptr)
        return 0;
    if (node->left == nullptr && node->right == nullptr)
        return 1;
    return 0;
}
   

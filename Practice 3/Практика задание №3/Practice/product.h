#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include <QVector>
#include<QMessageBox>

class product
{
private:
    char name[30], entry[15];
    int price, production;

public:
    product() {price=production=0;}
    product(std::string n, std::string e, int price1, int prod);
    ~product() {}
    char* Get_Name() { return name; }
    char* Get_Entry() { return entry; }
    int Get_Price() { return price; }
    int Get_Production() { return production; }
    bool Is_equally(std::string n, std::string e, int price1, int prod);
};

#endif // PRODUCT_H

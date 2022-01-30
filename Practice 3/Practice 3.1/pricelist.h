#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include <QVector>
#include<QMessageBox>

class pricelist
{
private:
    char service[30], surname[15];
    int days, price;

public:
    pricelist() {days=0; price=0;}
    pricelist(std::string serv, std::string s, int d, int p);
    ~pricelist() {}
    char* Get_Service() {return service;}
    char* Get_Surname() {return surname;}
    int Get_Days() {return days;}
    int Get_Price() {return price;}
    bool Is_equally(std::string serv, std::string s, int d, int p);
};

#endif // PRODUCT_H

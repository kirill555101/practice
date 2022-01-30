#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include <QVector>
#include <QMessageBox>

class product
{
private:
    char name[30], release[15], developer[30];
    int memory;

public:
    product() {memory=0;}
    product(std::string n, std::string r, std::string d, int mem);
    ~product() {}
    char* Get_Name();
    char* Get_Release();
    char* Get_Developer();
    int Get_Memory();
    bool Is_Released_In_Period(std::string d, int yearbegin, int yearend);
    bool Is_equally(std::string n, std::string r, std::string d, int mem);
};

#endif // PRODUCT_H

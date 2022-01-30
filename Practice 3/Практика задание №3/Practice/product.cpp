#include "product.h"

product::product(std::string n, std::string e, int price1, int prod)
{
    strcpy(name, n.c_str()); strcpy(entry, e.c_str()); price=price1; production = prod;
}

bool product::Is_equally(std::string n, std::string e, int price1, int prod)
{
    return (name == n && entry == e && price == price1 && production == prod);
}

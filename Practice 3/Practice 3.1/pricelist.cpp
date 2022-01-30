#include "pricelist.h"

pricelist::pricelist(std::string serv, std::string s, int d, int p)
{
    strcpy(service, serv.c_str()); strcpy(surname, s.c_str()); days=d; price = p;
}

bool pricelist::Is_equally(std::string serv, std::string s, int d, int p)
{
    return (service == serv && surname == s && days == d && price == p);
}

#include "product.h"

product::product(std::string n, std::string r, std::string d, int mem)
{
    strcpy(name, n.c_str()); strcpy(release, r.c_str()); strcpy(developer, d.c_str()); memory = mem;
}

char* product::Get_Name()
{
    return name;
}

char* product::Get_Release()
{
    return release;
}

char* product::Get_Developer()
{
    return developer;
}

int product::Get_Memory()
{
    return memory;
}

bool product::Is_Released_In_Period(std::string d, int yearbegin, int yearend)
{
    if (developer != d)
        return false;

    int year = atoi(release+6);

    return (yearbegin <= year && year <= yearend);
}

bool product::Is_equally(std::string n, std::string r, std::string d, int mem)
{
    return (name == n && release == r && developer == d && memory == mem);
}

#ifndef SWDB_PACKAGE_HPP
#define SWDB_PACKAGE_HPP

#include "dnf-swdb/dnf-swdb-pkg.h"

class SwdbPackage
{
public:
    SwdbPackage(const char *n, int e, const char *v, const char *r, const char *a);
    ~SwdbPackage();
    char *nevra();
    DnfSwdbPkg *pkg = NULL;
};

#endif

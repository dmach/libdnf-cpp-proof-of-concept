#include "package.hpp"

SwdbPackage::SwdbPackage(const char *n, int e, const char *v, const char *r, const char *a)
{
    pkg = dnf_swdb_pkg_new(n, e, v, r, a);
}

SwdbPackage::~SwdbPackage()
{
    if (pkg) {
        g_object_unref(pkg);
    }
}

char *
SwdbPackage::nevra()
{

    if (pkg) {
        return dnf_swdb_pkg_nevra(pkg);
    }
    else {
        return NULL;
    }
}

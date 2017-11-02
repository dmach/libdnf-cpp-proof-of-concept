#ifndef LIBDNF_RPMPACKAGE_H
#define LIBDNF_RPMPACKAGE_H

#include <string>

#include "package.hpp"

class RPMPackage : public Package {
public:
    RPMPackage() = default;

    std::string &getVersion() { return version; }
    std::string &getRelease() { return release; }

private:
    std::string version;
    std::string release;
};

#endif // LIBDNF_RPMPACKAGE_H

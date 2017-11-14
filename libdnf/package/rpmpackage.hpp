#ifndef LIBDNF_RPMPACKAGE_H
#define LIBDNF_RPMPACKAGE_H

#include <string>

#include "package.hpp"

/// Class representing an RPM package.
class RPMPackage : public Package {
public:
    /// Default contructor.
    RPMPackage() = default;

    /// Returns the version of this package.
    std::string &getVersion() { return version; }
    /// Returns the release of this package.
    std::string &getRelease() { return release; }

private:
    std::string version;
    std::string release;
};

#endif // LIBDNF_RPMPACKAGE_H

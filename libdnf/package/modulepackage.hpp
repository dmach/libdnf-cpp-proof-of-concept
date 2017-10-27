#ifndef LIBDNF_MODULEPACKAGE_H
#define LIBDNF_MODULEPACKAGE_H

#include <string>

#include "package.hpp"

class ModulePackage : public Package {
public:
    ModulePackage() = default;;

    // class is small enough for now, is it ok to leave getters in header ??
    const std::string &getStream() const { return stream; }
    long long int getVersion() const { return version; }

private:
    std::string stream;
    long long version;
};

#endif //LIBDNF_MODULEPACKAGE_H

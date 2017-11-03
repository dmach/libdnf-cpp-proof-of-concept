#ifndef LIBDNF_MODULEPACKAGE_H
#define LIBDNF_MODULEPACKAGE_H

#include <string>

#include "package.hpp"

class ModulePackage : public Package {
public:
    ModulePackage() = default;
    ModulePackage(const std::string &name, const std::string &stream, long long version);

    const std::string &getStream() const;
    void setVersion(long long int version);
    long long int getVersion() const;

private:
    std::string stream;
    long long version;
};

#endif // LIBDNF_MODULEPACKAGE_H

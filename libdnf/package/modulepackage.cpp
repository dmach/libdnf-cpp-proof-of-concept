#include "modulepackage.hpp"

ModulePackage::ModulePackage(const std::string &name, const std::string &stream, long long version)
        : stream(stream)
        , version(version)
{
    ModulePackage::name = name;
}

const std::string &ModulePackage::getStream() const
{
    return stream;
}

void ModulePackage::setVersion(long long int version)
{
    if (version < 0)
        throw std::string("Invalid version");
    ModulePackage::version = version;
}

long long int ModulePackage::getVersion() const
{
    return version;
}

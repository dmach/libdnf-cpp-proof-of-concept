#ifndef DNF_PACKAGE_HPP
#define DNF_PACKAGE_HPP


#include <string>


class Package {
    public:
        Package() {};
        virtual ~Package() = default;
        std::string name;
};


class RPMPackage : public Package {
    public:
        RPMPackage() {};
        std::string version;
        std::string release;
};


class ModulePackage : public Package {
    public:
        ModulePackage() {};
        std::string stream;
        long long version;
};


#endif

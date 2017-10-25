#ifndef DNF_PACKAGE_HPP
#define DNF_PACKAGE_HPP


#include <string>
using namespace std;


class Package {
    public:
        Package() {};
        virtual ~Package() = default;
        string name;
};


class RPMPackage : public Package {
    public:
        RPMPackage() {};
        string version;
        string release;
};


class ModulePackage : public Package {
    public:
        ModulePackage() {};
        string stream;
        long long version;
};


#endif

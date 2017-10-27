#ifndef DNF_PACKAGE_HPP
#define DNF_PACKAGE_HPP

#include <string>

class Package {
public:
    Package() = default;

    virtual ~Package() = default;

    // class is small enough for now, is it ok to leave getters in header ??
    const std::string &getName() const { return name; }
    void setName(const std::string &value) { name = value; }

protected:
    std::string name;
};

#endif

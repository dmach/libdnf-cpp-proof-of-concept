#ifndef DNF_REPO_HPP
#define DNF_REPO_HPP


#include <string>
#include <vector>

#include "package.hpp"

class Repo {
public:
    void set_repoid(const std::string &value);
    const std::string &get_repoid() const;
    void set_baseurl(const std::vector<std::string> &value);
    const std::vector<std::string> &get_baseurl() const;
    const std::vector<Package *> &getPackages() const;
    void setPackages(std::vector<Package *> &value);

private:
    std::string repoid;
    std::string name;
    std::vector<std::string> baseurl;
    std::vector<Package *> packages;

};

#endif

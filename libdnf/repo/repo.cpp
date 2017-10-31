#include <string>
#include <vector>

#include "repo.hpp"

using namespace std;

namespace libdnf {

void Repo::set_repoid(const string &value) {
    repoid = value;
}


const string &Repo::get_repoid() const {
    return repoid;
}


void Repo::set_baseurl(const vector<string> &value) {
    baseurl = value;
}


const vector<string> &Repo::get_baseurl() const {
    return baseurl;
}

const std::vector<Package *> &Repo::getPackages() const {
    return packages;
}

void Repo::setPackages(vector<Package *> &value) {
    packages = value;
}

}

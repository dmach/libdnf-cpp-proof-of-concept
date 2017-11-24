#include <string>
#include <vector>

#include "repo-private.hpp"

using namespace std;

Repo::Repo() : pimpl{new Impl} {}

Repo::~Repo() = default;

void
Repo::set_repoid(const string &value)
{
    pimpl->set_repoid(value);
}

const string &
Repo::get_repoid() const
{
    return pimpl->get_repoid();
}

void
Repo::set_baseurl(const vector<string> &value)
{
    pimpl->set_baseurl(value);
}

const vector<string> &
Repo::get_baseurl() const
{
    return pimpl->get_baseurl();
}

const std::vector<Package *> &
Repo::getPackages() const
{
    return pimpl->getPackages();
}

void
Repo::setPackages(vector<Package *> &value)
{
    pimpl->setPackages(value);
}

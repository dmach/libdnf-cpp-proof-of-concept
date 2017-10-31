#include <map>
#include <string>

#include "repodict.hpp"

using namespace std;

namespace libdnf {

void RepoDict::set_repos(const map<string, shared_ptr<Repo> > &value) {
    repos = value;
}

const map <string, shared_ptr<Repo> > &RepoDict::get_repos() const {
    return repos;
}

void RepoDict::add_repo(shared_ptr<Repo> repo) {
    repos[repo->get_repoid()] = repo;
}

}

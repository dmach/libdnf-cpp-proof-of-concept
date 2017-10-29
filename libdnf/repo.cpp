#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iostream>

#include "repo.hpp"

using namespace std;


void Repo::set_repoid(const string & value) {
    _repoid = value;
}


const string& Repo::get_repoid() {
    return _repoid;
}


void Repo::set_baseurl(const vector<string>& value) {
    _baseurl = value;
}


const vector<string>& Repo::get_baseurl() {
    return _baseurl;
}


void RepoDict::set_repos(const map<string, Repo>& repos) {
    _repos = repos;
}

const map<string, Repo>& RepoDict::get_repos() {
    return _repos;
}

void RepoDict::add_repo(Repo repo) {
    _repos[repo.get_repoid()] = repo;
}

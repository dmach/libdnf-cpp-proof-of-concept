#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iostream>

#include "repo.hpp"

using namespace std;


void Repo::set_repoid(const string & value) {
    this->_repoid = value;
}


const string& Repo::get_repoid() {
    return this->_repoid;
}


void Repo::set_baseurl(const vector<string>& value) {
    this->_baseurl = value;
}


const vector<string>& Repo::get_baseurl() {
    return this->_baseurl;
}


void RepoDict::set_repos(const map<string, Repo>& repos) {
    this->_repos = repos;
}

const map<string, Repo>& RepoDict::get_repos() {
    return this->_repos;
}

void RepoDict::add_repo(Repo repo) {
    this->_repos[repo.get_repoid()] = repo;
}

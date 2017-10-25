#ifndef DNF_REPO_HPP
#define DNF_REPO_HPP


#include <string>
#include <vector>
#include <map>
#include <functional>
#include <iostream>
using namespace std;

#include "package.hpp"



class Repo {
    private:
        string _repoid;
        string _name;
        vector< wstring > _baseurl;

    public:
        void set_repoid(string value);
        const string& get_repoid();

        void set_baseurl(const vector< wstring >& value);
        const vector< wstring >& get_baseurl();

        vector<Package *> packages;
};


class RepoDict {
    private:
        map<string, Repo> _repos;

    public:
        void set_repos(const map<string,Repo>& value);
        const map<string,Repo>& get_repos();
        void add_repo(Repo repo);
};

#endif

#ifndef DNF_REPO_HPP
#define DNF_REPO_HPP

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "package.hpp"


class Repo {
    private:
        std::string _repoid;
        std::string _name;
        std::vector<std::string> _baseurl;

    public:
        void set_repoid(const std::string & value);
        const std::string& get_repoid();

        void set_baseurl(const std::vector<std::string>& value);
        const std::vector<std::string>& get_baseurl();

        std::vector<Package *> packages;
};


class RepoDict {
    private:
        std::map<std::string, std::shared_ptr<Repo> > _repos;

    public:
        void set_repos(const std::map<std::string, std::shared_ptr<Repo> > & value);
        const std::map<std::string, std::shared_ptr<Repo> > & get_repos();
        void add_repo(std::shared_ptr<Repo> & repo);
};

#endif

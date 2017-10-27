#ifndef LIBDNF_REPODICT_H
#define LIBDNF_REPODICT_H

#include <map>
#include <memory>

#include "repo.hpp"

class RepoDict {
public:
    void set_repos(const std::map<std::string, std::shared_ptr<Repo> > &value);
    const std::map <std::string, std::shared_ptr<Repo> > &get_repos() const;
    void add_repo(std::shared_ptr<Repo> repo);

private:
    std::map <std::string, std::shared_ptr<Repo> > repos;
};

#endif //LIBDNF_REPODICT_H

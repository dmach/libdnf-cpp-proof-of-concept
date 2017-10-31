%module repo


%include <attribute.i>
%include <std_string.i>
%include <std_vector.i>
%include <std_map.i>
%include <std_shared_ptr.i>

%shared_ptr(libdnf::Repo)

%{
    // make SWIG wrap following headers
    #include "repo/repo.hpp"
    #include "repo/repodict.hpp"
    #include "package/package.hpp"
%}

%template(list_string) std::vector<std::string>;
%template(list_package) std::vector<libdnf::Package*>;
%template() std::map<std::string, std::shared_ptr<libdnf::Repo> >;

// make SWIG look into following headers
%include "repo/repo.hpp"
%include "repo/repodict.hpp"
%include "package/package.hpp"

using libdnf::Package;

%attribute(libdnf::Repo, std::string, repoid, get_repoid, set_repoid);
%attribute(libdnf::Repo, std::vector<std::string>&, baseurl, get_baseurl, set_baseurl);
%attribute(libdnf::Repo, std::vector<libdnf::Package *>&, packages, getPackages, setPackages);

%module repo


%include <attribute.i>
%include <std_string.i>
%include <std_vector.i>
%include <std_map.i>
%include <std_shared_ptr.i>

%shared_ptr(Repo)

%{
    // make SWIG wrap following headers
    #include "repo.hpp"
%}

namespace std {
    %template(list_string) vector<string>;
    %template(list_package) vector<Package*>;
    %template() map<string, shared_ptr<Repo> >;
}


// make SWIG look into following headers
%include "repo.hpp"



%attribute(Repo, std::string, repoid, get_repoid, set_repoid);
%attribute(Repo, std::vector<std::string>&, baseurl, get_baseurl, set_baseurl);

%module(package="pylibdnf") repo


%{
    // make SWIG wrap following headers
    #include "repo.hpp"
%}


%include <attribute.i>
%include <std_string.i>
%include <std_wstring.i>
%include <std_vector.i>
%include <std_map.i>


namespace std {
    %template(list_string) vector<wstring>;
    %template(list_package) vector<Package*>;
    %template() map<string, Repo>;
}


// make SWIG look into following headers
%include "repo.hpp"



%attribute(Repo, string, repoid, get_repoid, set_repoid);
%attribute(Repo, vector<wstring>&, baseurl, get_baseurl, set_baseurl);

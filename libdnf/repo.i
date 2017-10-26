%define MODULEIMPORT
"
def swig_import_helper():
    import importlib.util
    import os
    import sys

    file_path = os.path.join(os.path.dirname(__file__), '_pylibdnf.so')
    module_name = '_repo'

    spec = importlib.util.spec_from_file_location(module_name, file_path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    sys.modules[module_name] = module
    return module

_repo = swig_import_helper()
del swig_import_helper
"
%enddef


%module(package="pylibdnf", moduleimport=MODULEIMPORT) repo


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

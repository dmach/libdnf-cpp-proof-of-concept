%module package


%{
    // make SWIG wrap following headers
    #include "package/package.hpp"
    #include "package/modulepackage.hpp"
    #include "package/rpmpackage.hpp"
%}

%include <attribute.i>
%include <std_string.i>
%include <typemaps.i>

// make SWIG look into following headers
%include "package/package.hpp"
%include "package/modulepackage.hpp"
%include "package/rpmpackage.hpp"

%apply SWIGTYPE *DYNAMIC { libdnf::Package * };

%{
static swig_type_info *
//Package_dynamic(void **ptr) {
Package_dynamic(libdnf::Package **ptr) {
   libdnf::RPMPackage *rpm;
   rpm = dynamic_cast<libdnf::RPMPackage *>(*ptr);
   if (rpm) {
      //*ptr = (void *) rpm;
      return SWIGTYPE_p_libdnf__RPMPackage;
   }

   libdnf::ModulePackage *mod;
   mod = dynamic_cast<libdnf::ModulePackage *>(*ptr);
   if (mod) {
      //*ptr = (void *) mod;
      return SWIGTYPE_p_libdnf__ModulePackage;
   }

   return 0;
}
%}


// register the above casting function
DYNAMIC_CAST(SWIGTYPE_p_libdnf__Package, Package_dynamic);


%extend libdnf::Package {
   bool __eq__(const libdnf::Package &other) { return $self == &other; }
   long __hash__() { return (long) $self; }  // hash: just address of C struct
}

%attribute(libdnf::Package, std::string, name, getName, setName);

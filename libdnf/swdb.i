%module swdb

// wrap headers
%{
    #include "swdb.hpp"
    #include "swdb/package.hpp"
%}

// make SWIG look into following headers
%include "swdb.hpp"
%include "swdb/package.hpp"

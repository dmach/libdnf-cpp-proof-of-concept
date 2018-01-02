Name:		libdnf_cpp
Version:	1.0.0
Release:	1%{?dist}
Summary:	Libdnf C++ proof-of-concept project

License:	LGPLv2+ 
URL:		https://github.com/dmach/libdnf-cpp-proof-of-concept
Source0:	%{url}/archive/master.tar.gz

BuildRequires:	cmake

%description
This is a proof-of-concept project that shows
how to work with C++ objects and export them
to Python via SWIG.

%package devel
Summary:	Development files for %{name}
Requires:	%{name} = %{version}-%{release}

%description devel
Development files for %{name}

%package -n python3-libdnf
Summary:	Python 3 bindings for libdnf
%{?python_provide:%python_provide python3-libdnf}
Requires:	%{name}{?_isa} = %{version}-%{release}
BuildRequires:	python3-devel

%description -n python3-libdnf
Python 3 bindings for the libdnf library

%prep
%autosetup
mkdir build-py3

%build
pushd build-py3
  %cmake ..
  %make_build
popd


%install
pushd build-py3
  %make_install
popd

%post -p /sbin/ldconfig
%postun -p /sbin/ldconfig

%files
%license COPYING
%doc README TODO
%{_libdir}/libdnf.so.*

%files devel
%{_libdir}/libdnf.so
%{_includedir}/libdnf/

%files -n python3-libdnf
%{python3_sitearch}/libdnf/

%changelog
* Thu Nov 02 2017 Marek Blaha <mblaha@redhat.com> - 1.0.0-1
- initial rpm build



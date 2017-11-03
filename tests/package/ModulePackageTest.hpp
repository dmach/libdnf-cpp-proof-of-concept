#ifndef LIBDNF_PACKAGETEST_HPP
#define LIBDNF_PACKAGETEST_HPP

#include "package.hpp"

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class ModulePackageTest : public CppUnit::TestCase
{

   CPPUNIT_TEST_SUITE(ModulePackageTest);
        CPPUNIT_TEST(testName);
        CPPUNIT_TEST(testStream);
        CPPUNIT_TEST(testVersion);
   CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;

    void testName();
    void testStream();
    void testVersion();

private:
    ModulePackage *modulePackage;

};


#endif //LIBDNF_PACKAGETEST_HPP

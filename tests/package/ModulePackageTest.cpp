#include "ModulePackageTest.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION(ModulePackageTest);

void ModulePackageTest::setUp()
{
    modulePackage = new ModulePackage("httpd", "2.4", 1L);
}

void ModulePackageTest::tearDown()
{
    delete modulePackage;
}

void ModulePackageTest::testName()
{
    CPPUNIT_ASSERT("httpd" == modulePackage->getName());
}

void ModulePackageTest::testStream()
{
    CPPUNIT_ASSERT("2.4" == modulePackage->getStream());
}

void ModulePackageTest::testVersion()
{
    CPPUNIT_ASSERT(1L == modulePackage->getVersion());

    modulePackage->setVersion(2L);
    CPPUNIT_ASSERT(2L == modulePackage->getVersion());

    CPPUNIT_ASSERT_THROW(modulePackage->setVersion(-1L), std::string);
}

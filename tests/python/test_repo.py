#!/usr/bin/python3


import unittest

import repo
import package


class TestRepo(unittest.TestCase):
    def test_repr(self):
        pass

    def test_str(self):
        pass

    def test_repoid_default(self):
        r = repo.Repo()
        self.assertEqual(r.get_repoid(), "")
        self.assertEqual(r.repoid, "")

    def test_repoid_set_get(self):
        r = repo.Repo()
        r.set_repoid("a-repo-id")
        self.assertEqual(r.get_repoid(), "a-repo-id")

    def test_repoid_property(self):
        r = repo.Repo()
        r.repoid = "a-repo-id"
        self.assertEqual(r.repoid, "a-repo-id")
        # verify that the value is identical to what's returned from getter
        self.assertEqual(r.get_repoid(), "a-repo-id")

    def test_baseurl_default(self):
        r = repo.Repo()
        self.assertEqual(r.get_baseurl(), ())

    def test_baseurl_set_get(self):
        r = repo.Repo()
        r.set_baseurl(["http://example.com/repo"])
        self.assertEqual(r.get_baseurl(), ("http://example.com/repo", ))

    def test_baseurl_property(self):
        r = repo.Repo()
        #r.baseurl = ("http://example.com/repo", )
        # verify that the value is identical to what's returned from getter
        #self.assertEqual(r.get_baseurl(), ("http://example.com/repo", ))


class TestRepoDict(unittest.TestCase):
    def test_add_repo(self):
        r1 = repo.Repo()
        r1.repoid = "a-repo-id"

        r2 = repo.Repo()
        r2.repoid = "another-repo-id"

        rd = repo.RepoDict()
        rd.add_repo(r1)

        repos = {r1.repoid: r1}
        rd.set_repos(repos)

        repos[r2.repoid] = r2
        rd.set_repos(repos)

        r1_copy = repos["a-repo-id"]
        self.assertEqual(r1, r1_copy)
        self.assertEqual(r1.repoid, "a-repo-id")
        self.assertEqual(r1_copy.repoid, "a-repo-id")

        r1.repoid = "foo"
        self.assertEqual(r1.repoid, "foo")
        self.assertEqual(r1_copy.repoid, "foo")

        r1_copy.repoid = "bar"
        self.assertEqual(r1.repoid, "bar")
        self.assertEqual(r1_copy.repoid, "bar")


class TestRepoPackages(unittest.TestCase):
    def test_polymorfism(self):
        r = repo.Repo()

        p1 = package.RPMPackage()
        p1.name = "one"
        p1.version = "version"

        p2 = package.ModulePackage()
        p2.name = "two"
        p2.stream = "stream"

        r.packages.append(p1)
        r.packages.append(p2)

        p1_copy = r.packages[0]
        self.assertEqual(p1, p1_copy)

        p1.name = "foo"
        self.assertEqual(p1.name, "foo")
        self.assertEqual(p1_copy.name, "foo")

        p1_copy.name = "bar"
        self.assertEqual(p1.name, "bar")
        self.assertEqual(p1_copy.name, "bar")


if __name__ == "__main__":
    unittest.main()

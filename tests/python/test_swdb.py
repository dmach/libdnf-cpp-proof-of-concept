#!/usr/bin/python3

import unittest

from swdb import SwdbPackage

import gi
gi.require_version('Dnf', '42.0')
from gi.repository import Dnf


class TestSwdb(unittest.TestCase):

    def test_load(self):
        pkg = Dnf.SwdbPkg.new("n", 0, "v", "r", "a")
        self.assertEqual(pkg.nevra(), "n-0:v-r.a")


class TestSwdbWrapper(unittest.TestCase):

    def test_wrapper(self):
        p1 = SwdbPackage("n", 0, "v", "r", "a")
        self.assertEqual(p1.nevra(), "n-0:v-r.a")

if __name__ == "__main__":
    unittest.main()

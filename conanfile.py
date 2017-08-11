from conans import ConanFile
import os


class JsonconsConan(ConanFile):
    name = "jsoncons"
    version = "0.99.7.3"
    description = "jsoncons is a modern C++, header-only library for constructing JSON"
    license = "Boost Software License - Version 1.0"
    url = "https://github.com/danielaparker/jsoncons"
    generators = "cmake"
    exports_sources = "src/jsoncons/*"

    def package(self):
        self.copy(pattern="*", src="src/", dst="include/")

// Copyright 2013 Daniel Parker
// Distributed under Boost license

#include <string>
#include "jsoncons/json.hpp"

using jsoncons::json;
using jsoncons::pretty_print;
using jsoncons::output_format;
using std::string;

int main(int argc, char** argv)
{
    std::string s = "{\"my-array\" : [1,2,3,4]}";
    json val = json::parse_string(s);
    std::vector<int> v = val["my-array"].as<std::vector<int>>();
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i > 0)
        {
            std::cout << ",";
        }
        std::cout << v[i];
    }
    std::cout << std::endl;
    return 0;
}
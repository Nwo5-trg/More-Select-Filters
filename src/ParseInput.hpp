#pragma once
#include "SelectFilterPopup.hpp"

inline const std::unordered_map<std::string, int> intTypesMap{
    {"obj", 1004}, {"bg", 1000}, {"g1", 1001}, {"g2", 1009},
    {"mg", 1013}, {"mg2", 1014}, {"line", 1002}, {"3dl", 1003},
    {"p1", 1005}, {"p2", 1006}, {"lbg", 1007}, {"black", 1010},
    {"white", 1011}, {"lighter", 1012}, {"b5", -5}, {"b4", -3},
    {"b3", -1}, {"b2", 1}, {"b1", 3}, {"default", 0},
    {"t1", 5}, {"t2", 7}, {"t3", 9}, {"t4", 11},
};

inline const std::unordered_map<int, std::string> intTypesMapReverse{
    {1004, "obj"}, {1000, "bg"}, {1001, "g1"}, {1009, "g2"},
    {1013, "mg"}, {1014, "mg2"}, {1002, "line"}, {1003, "3dl"},
    {1005, "p1"}, {1006, "p2"}, {1007, "lbg"}, {1010, "black"},
    {1011, "white"}, {1012, "lighter"}, {-5, "b5"}, {-3, "b4"},
    {-1, "b3"}, {1, "b2"}, {3, "b1"}, {0, "default"},
    {5, "t1"}, {7, "t2"}, {9, "t3"}, {11, "t4"},
};

std::string floatToFormattedString(float num);
std::vector<int> getIntVector(const std::string& input);
std::vector<TypedFloat> getTypedFloatVector(const std::string& input);
std::vector<std::string> getStringVector(const std::string& input);
std::string trimDuplicates(const std::string& input);

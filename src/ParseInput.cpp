#include "ParseInput.hpp"

std::string floatToFormattedString(float num) { // lowk ts just a utils file but i dont wanna change the name
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << num;
    std::string string = ss.str();
    string.erase(string.find_last_not_of('0') + 1, std::string::npos);
    if (string.back() == '.') string.pop_back();
    return string;
}

std::vector<int> getIntVector(const std::string& input) {
    std::vector<int> intVector;
    auto start = 0;
    while (true) {
        auto comma = input.find(',', start);
        auto substr = input.substr(start, comma - start);
        if (substr != "") {
            if (intTypesMap.contains(substr)) intVector.emplace_back(intTypesMap.at(substr));
            else intVector.emplace_back(abs(std::strtol(substr.c_str(), nullptr, 10)));
        }
        if (comma == std::string::npos) break;
        start = comma + 1;
    }
    return intVector;
}

std::vector<TypedFloat> getTypedFloatVector(const std::string& input) {
    std::vector<TypedFloat> typedFloatVector;
    auto start = 0;
    while (true) {
        auto comma = input.find(',', start);
        auto substr = input.substr(start, comma - start);
        if (substr != "") {
            auto num = std::strtof(substr.c_str(), nullptr);
            auto lastChar = substr.back();
            if (lastChar == 's' || lastChar == 'x') typedFloatVector.emplace_back(TypedFloat{num, 1});
            else if (lastChar == 'b' || lastChar == 'v' || lastChar == 'y') typedFloatVector.emplace_back(TypedFloat{num, 2});
            else typedFloatVector.emplace_back(TypedFloat{num, 0});
        }
        if (comma == std::string::npos) break;
        start = comma + 1;
    }
    return typedFloatVector;
}

std::vector<std::string> getStringVector(const std::string& input) {
    std::vector<std::string> stringVector;
    auto start = 0;
    while (true) {
        auto comma = input.find(',', start);
        auto substr = input.substr(start, comma - start);
        if (substr != "") {
            std::unordered_set<std::string> keywords {"layout", "trigger", "decoration", "deco", "passable", "detail", "hazard", "solid"};
            if (keywords.contains(substr)) stringVector.emplace_back(substr);
            else return {"any"};
        }
        if (comma == std::string::npos) break;
        start = comma + 1;
    }
    return stringVector;
}
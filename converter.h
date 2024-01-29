#pragma once

#include <string>
#include <vector>



class ExpressionConverter {
public:
    explicit ExpressionConverter(const std::string& s);

    std::vector<std::string>::iterator begin();

    std::vector<std::string>::iterator end();

private:
    std::vector<std::string> expression_;

    void SetExpression(const std::string& s);

    std::string TrimSpases(const std::string& s);
};

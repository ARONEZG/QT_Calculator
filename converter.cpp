#include "converter.h"


using namespace std;

ExpressionConverter::ExpressionConverter(const string& s) {
    SetExpression(TrimSpases(s));
}

std::vector<std::string>::iterator ExpressionConverter::begin() {
    return expression_.begin();
}

std::vector<std::string>::iterator ExpressionConverter::end() {
    return expression_.end();
}

void ExpressionConverter::SetExpression(const string& s) {
    auto begin = s.begin();
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it == '+' || *it ==  '-' || *it ==  '*' ||
            *it ==  '/' || *it ==  '(' || *it ==  ')') {
            if (!string(begin, it).empty()) {
                expression_.push_back(string(begin, it));
            }
            expression_.push_back(string());
            expression_.back().push_back(*it);
            begin = it + 1;
        }
    }
    if (expression_.empty()) {
        expression_.push_back(s);
    }
    for (auto it = s.end() - 1; it >= s.begin(); it--) {
        if (*it == '+' || *it ==  '-' || *it ==  '*' ||
            *it ==  '/' || *it ==  '(' || *it ==  ')') {
            if (!string(it + 1, s.end()).empty()) {
                expression_.push_back(string(it + 1, s.end()));
            }
            break;
        }
    }
}

string ExpressionConverter::TrimSpases(const string& s) {
    string result;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            continue;
        }
        result.push_back(s[i]);
    }
    return result;
}

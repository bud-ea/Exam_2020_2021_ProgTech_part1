#include "DBClass.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int DBClass::load(const char* filename, const char* key)
{
    std::ifstream f(filename);
    std::string s;

    if (!f.good()) { return -1; }

    while (f.good()) {
        DBRecord newRecord;
        int i;
        for (i = 0; i < 3 && f.good(); i++) {
            getline(f, s);
            auto l = s.rfind("\"");
            if (l == string::npos) {
                i--;
                continue;
            }
            auto pl = s.rfind("\"", l-1);
            string ss = s.substr(pl+1, l-pl-1);
            newRecord[i] = std::move(ss);
        }
        if (i == 3) {
            data.push_back(std::move(newRecord));
        }
    }
    f.close();
    return 0;
}

void DBClass::printAll() const
{
    for (const auto& e : data) {
        e.print();
    }
}

int DBClass::find(const char* secondname) const
{
    for (unsigned int i = 0; i < data.size(); i++) {
        if (data[i][1] == secondname) { return i; }
    }
    return -1;
}

int DBClass::add(const char* name, const char* second_name, const char* passport)
{
    for (const auto& e : string(name)) {
        if (!((e | 32) >= 'a' && (e | 32) <= 'z')) { return -1; }
    }
    for (const auto& e : string(second_name)) {
        if (!((e | 32) >= 'a' && (e | 32) <= 'z')) { return -1; }
    }
    if (strlen(passport) != 11) { return -1; }
    for (int i = 0; i < 4; i++) {
        if (!(passport[i] >= '0' && passport[i] <= '9')) { return -1; }
    }
    if (passport[4] != ' ') { return -1; }
    for (int i = 5; i < 11; i++) {
        if (!(passport[i] >= '0' && passport[i] <= '9')) { return -1; }
    }
    data.push_back({name, second_name, passport});
    return data.size() - 1;
}

int DBClass::remove(const int n)
{
    if (n < 0 || (unsigned int) n >= data.size() - 1) { return -1; }
    data.erase(data.begin() + n);
    return 0;
}

void DBClass::save(const char* filename, const char* key)
{
    ofstream f (filename);
    for (const auto& e : data) {
        f << "{" << endl;
        f << "\t\"Name\"=\"" << e[0] << "\"" << endl;
        f << "\t\"Second name\"=\"" << e[1] << "\"" << endl;
        f << "\t\"Passport\"=\"" << e[2] << "\"" << endl;
        f << "}" << endl;
    }
}


void DBRecord::print() const
{
    for (const auto& e : data) {
        cout << e << '\t';
    }
    cout << endl;
}

#ifndef DBCLASS_H
#define DBCLASS_H

#include <vector>
#include <array>
#include <string>

class DBRecord {
  public:
    DBRecord() = default;
    DBRecord(const char* name, const char* second_name, const char* passport)
        : data{name, second_name, passport} {}
    void print() const;
    std::string& operator[](unsigned int i) { return data[i]; }
    const std::string& operator[](unsigned int i) const { return data[i]; }
  protected:
    std::array<std::string, 3> data;
};

class DBClass {
  public:
    int load(const char* filename, const char* key);
    void printAll() const;
    int find(const char* secondname) const;
    int add(const char* name, const char* second_name, const char* passport);
    int remove(const int n);
    void save(const char* filename, const char* key);
  protected:
    std::vector<DBRecord> data;
};

#endif // DBCLASS_H

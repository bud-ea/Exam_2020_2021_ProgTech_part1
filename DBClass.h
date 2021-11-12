#pragma once
#include <vector>
#include <array>
#include <string>
/*!
	* @file   DBClass.h
	* @brief   краткое описание
	* @author author
	* @date   2021-12-11
	*/

class DBRecord {
/**
@class DBRecord
Один из классов представленных для экзамена
*/
  public:
    DBRecord() = default; /// Конструктор
	DBRecord(const char* name, const char* second_name, const char* passport)
		: data{name, second_name, passport} {}
	void print() const;
/// Метод, делающий что-то
    /// @param const char* name – параметр, отвечающий за что-то
	/// @param и другие передаваемые функции параметры
    /// @return 
	std::string& operator[](unsigned int i) { return data[i]; }
	const std::string& operator[](unsigned int i) const { return data[i]; }
  protected:
	std::array<std::string, 3> data;
};

class DBClass {
/**
@class DBClass
Второй класс представленный для экзамена
*/
  public: /// Конструктор по умолчанию
	int load(const char* filename, const char* key);
	/// Метод, делающий что-то
	/// @param const char* name – параметр, отвечающий за что-то
	/// @param и другие передаваемые функции параметры
	/// @return возварщает int значение
	void printAll() const;
	/// Метод, делающий что-то
	/// @param const char* name – параметр, отвечающий за что-то
	/// @param и другие передаваемые функции параметры
	/// @return ничего не возвращает
	int find(const char* secondname) const;
	/// @param const char* name – параметр, отвечающий за что-то
	/// @param и другие передаваемые функции параметры
	/// @return ничего не возвращает
	int add(const char* name, const char* second_name, const char* passport);
	/// Метод, делающий что-то
	/// @param const char* name – параметр, отвечающий за что-то
    /// @param и другие передаваемые функции параметры
    /// @return ничего не возвращает
	int remove(const int n);
	/// Метод, делающий что-то
    /// @param const char* name – параметр, отвечающий за что-то
    /// @param и другие передаваемые функции параметры
    /// @return ничего не возвращает
	void save(const char* filename, const char* key);
	/// Метод, делающий что-то
	/// @param const char* name – параметр, отвечающий за что-то
	/// @param и другие передаваемые функции параметры
	/// @return ничего не возвращает
  protected:
	std::vector<DBRecord> data;
};

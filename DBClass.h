#pragma once
#include <vector>
#include <array>
#include <string>
/*!
	* @file   DBClass.h
	* @brief   описание
	* @author author
	* @date   2021-10-08
	*/
class DBRecord { 
/**
@class DBRecord
ќдин из классов представленных дл€ экзамена
*/
public:
	DBRecord() = default; ///  онструктор
	DBRecord(const char* name, const char* second_name, const char* passport)
		: data{ name, second_name, passport } {}
	void print() const;
	/// ћетод, делающий что-то
    /// @param const char* name Ц параметр, отвечающий за что-то
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
¬торой класс представленный дл€ экзамена
*/
public: ///  онструктор по умолчанию
	int load(const char* filename, const char* key);
	/// ћетод, делающий что-то
	/// @param const char* name Ц параметр, отвечающий за что-то
	/// @param и другие передаваемые функции параметры
	/// @return возварщает int значение
	void printAll() const;
	/// ћетод, делающий что-то
	/// @param const char* name Ц параметр, отвечающий за что-то
	/// @param и другие передаваемые функции параметры
	/// @return ничего не возвращает
	int find(const char* secondname) const;
	/// 
	/// 
/// @param const char* name Ц параметр, отвечающий за что-то
/// @param и другие передаваемые функции параметры
/// @return ничего не возвращает
	int add(const char* name, const char* second_name, const char* passport);
	/// ћетод, делающий что-то
    /// @param const char* name Ц параметр, отвечающий за что-то
    /// @param и другие передаваемые функции параметры
    /// @return ничего не возвращает
	int remove(const int n);
	/// ћетод, делающий что-то
    /// @param const char* name Ц параметр, отвечающий за что-то
    /// @param и другие передаваемые функции параметры
    /// @return ничего не возвращает
	void save(const char* filename, const char* key);
	/// ћетод, делающий что-то
/// @param const char* name Ц параметр, отвечающий за что-то
/// @param и другие передаваемые функции параметры
/// @return ничего не возвращает
protected:
	std::vector<DBRecord> data;
};

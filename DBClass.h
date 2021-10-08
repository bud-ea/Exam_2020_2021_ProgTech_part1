#pragma once
#include <vector>
#include <array>
#include <string>
/*!
	* @file   DBClass.h
	* @brief   ��������
	* @author author
	* @date   2021-10-08
	*/
class DBRecord { 
/**
@class DBRecord
���� �� ������� �������������� ��� ��������
*/
public:
	DBRecord() = default; /// �����������
	DBRecord(const char* name, const char* second_name, const char* passport)
		: data{ name, second_name, passport } {}
	void print() const;
	/// �����, �������� ���-��
    /// @param const char* name � ��������, ���������� �� ���-��
	/// @param � ������ ������������ ������� ���������
    /// @return 
	std::string& operator[](unsigned int i) { return data[i]; }
	const std::string& operator[](unsigned int i) const { return data[i]; }
protected:
	std::array<std::string, 3> data;
};

class DBClass {
/**
@class DBClass
������ ����� �������������� ��� ��������
*/
public: /// ����������� �� ���������
	int load(const char* filename, const char* key);
	/// �����, �������� ���-��
	/// @param const char* name � ��������, ���������� �� ���-��
	/// @param � ������ ������������ ������� ���������
	/// @return ���������� int ��������
	void printAll() const;
	/// �����, �������� ���-��
	/// @param const char* name � ��������, ���������� �� ���-��
	/// @param � ������ ������������ ������� ���������
	/// @return ������ �� ����������
	int find(const char* secondname) const;
	/// 
	/// 
/// @param const char* name � ��������, ���������� �� ���-��
/// @param � ������ ������������ ������� ���������
/// @return ������ �� ����������
	int add(const char* name, const char* second_name, const char* passport);
	/// �����, �������� ���-��
    /// @param const char* name � ��������, ���������� �� ���-��
    /// @param � ������ ������������ ������� ���������
    /// @return ������ �� ����������
	int remove(const int n);
	/// �����, �������� ���-��
    /// @param const char* name � ��������, ���������� �� ���-��
    /// @param � ������ ������������ ������� ���������
    /// @return ������ �� ����������
	void save(const char* filename, const char* key);
	/// �����, �������� ���-��
/// @param const char* name � ��������, ���������� �� ���-��
/// @param � ������ ������������ ������� ���������
/// @return ������ �� ����������
protected:
	std::vector<DBRecord> data;
};

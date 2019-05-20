#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <assert.h>

class MyString
{
public:
	MyString();										//����������� �� ���������
	MyString(const MyString &string);				//����������� ����������� [MyString copyString(string);]
	MyString(const char* string);					//����������� ����������� [MyString copyString(string);]

	MyString& operator= (const MyString &string);	//�������� ������������ ������������
	MyString& operator= (const char * string);		//�������� ������������ ������������

	MyString operator+ (MyString &string);			//��������
	MyString operator+ (const char * string);		//��������

	MyString& operator+= (MyString& string);		//�������� � ������������
	MyString& operator+= (const char * string);		//�������� � ������������

	bool	operator== (MyString& string);			//��������� �����
	bool	operator== (const char* string);		//��������� �����

	bool	operator< (MyString& string);			//��������� �����
	bool	operator< (const char* string);		    //��������� �����

	bool	operator> (MyString& string);			//��������� �����
	bool	operator> (const char* string);		    //��������� �����

	bool	operator<= (MyString& string);			//��������� �����
	bool	operator<= (const char* string);		    //��������� �����

	bool	operator>= (MyString& string);			//��������� �����
	bool	operator>= (const char* string);		    //��������� �����

	char	operator[] (unsigned int index);			//��������� �����


	MyString	reverse();							//�������� ������
	unsigned	size();								//������
	bool		isEmpty();							//��������, ������ �� ������
	int         hash();
	int			numberGET();



	friend std::ostream& operator<< (std::ostream& stream, const MyString &string) {
		stream << string._string;
		return stream;
	}

	friend std::istream& operator >> (std::istream& stream, const MyString &string) {
		//��������� ���
		return stream;
	}

	~MyString();//����������
private:
	unsigned int _length;
	unsigned int _size;
	char* _string;
	int _hash;
};

#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <assert.h>

class MyString
{
public:
	MyString();										//конструктор по умолчанию
	MyString(const MyString &string);				//конструктор копирования [MyString copyString(string);]
	MyString(const char* string);					//конструктор копирования [MyString copyString(string);]

	MyString& operator= (const MyString &string);	//оператор присваивания копированием
	MyString& operator= (const char * string);		//оператор присваивания копированием

	MyString operator+ (MyString &string);			//сложение
	MyString operator+ (const char * string);		//сложение

	MyString& operator+= (MyString& string);		//сложение и присваивание
	MyString& operator+= (const char * string);		//сложение и присваивание

	bool	operator== (MyString& string);			//равенство строк
	bool	operator== (const char* string);		//равенство строк

	bool	operator< (MyString& string);			//равенство строк
	bool	operator< (const char* string);		    //равенство строк

	bool	operator> (MyString& string);			//равенство строк
	bool	operator> (const char* string);		    //равенство строк

	bool	operator<= (MyString& string);			//равенство строк
	bool	operator<= (const char* string);		    //равенство строк

	bool	operator>= (MyString& string);			//равенство строк
	bool	operator>= (const char* string);		    //равенство строк

	char	operator[] (unsigned int index);			//равенство строк


	MyString	reverse();							//разворот строки
	unsigned	size();								//размер
	bool		isEmpty();							//проверка, пустая ли строка
	int         hash();
	int			numberGET();



	friend std::ostream& operator<< (std::ostream& stream, const MyString &string) {
		stream << string._string;
		return stream;
	}

	friend std::istream& operator >> (std::istream& stream, const MyString &string) {
		//дополнить код
		return stream;
	}

	~MyString();//деструктор
private:
	unsigned int _length;
	unsigned int _size;
	char* _string;
	int _hash;
};

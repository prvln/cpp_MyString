//#include "pch.h"
#include "MyString.h"


MyString::MyString()
{
	this->_length = 0;
	this->_size = 0;
	this->_string = NULL;
	this->_hash = 0;
}

MyString::MyString(const MyString &string)
{
	this->_length = string._length;
	this->_size = string._size;
	this->_string = new char[this->_size];
	strcpy_s(this->_string, this->_size, string._string);
	_hash = this->hash();
}

MyString::MyString(const char* string) {
	this->_length = strlen(string);
	this->_size = this->_length + 1;
	this->_string = new char[this->_size];
	strcpy_s(this->_string, this->_size, string);
	_hash = this->hash();
}

MyString::~MyString()
{
	if (this->_string != NULL)
	{
		delete[] this->_string;
		this->_string = NULL;
	}
}

MyString MyString::operator+(const char * string)
{
	MyString* buff = new MyString();

	buff->_length = strlen(string) + strlen(this->_string);
	buff->_size = buff->_length + 1;
	buff->_string = new char[buff->_size];

	strcpy_s(buff->_string, buff->_size, this->_string);
	strcat_s(buff->_string, buff->_size, string);

	_hash = this->hash();
	return (MyString&)*buff;
}

MyString MyString::operator+(MyString &string)
{
	MyString* buff = new MyString();

	buff->_length = string._length + this->_length;
	buff->_size = buff->_length + 1;
	buff->_string = new char[buff->_size];

	strcpy_s(buff->_string, buff->_size, this->_string);
	strcat_s(buff->_string, buff->_size, string._string);

	_hash = this->hash();
	return (MyString&)*buff;
}

MyString & MyString::operator=(const MyString & string)
{
	if (this != &string)
	{
		this->_length = string._length;
		this->_size = string._size;
		this->_string = new char[this->_size];

		strcpy_s(this->_string, this->_size, string._string);
	}

	_hash = this->hash();
	return *this;
}
MyString & MyString::operator=(const char * string)
{
	if (this->_string != string)
	{
		this->_length = strlen(string);
		this->_size = this->_length + 1;
		this->_string = (char*)string;

		strcpy_s(this->_string, this->_size, string);
	}

	_hash = this->hash();
	return *this;
}

MyString & MyString::operator+=(MyString & string)
{
	this->_length = this->_length + string._length;
	this->_size = this->_length + 1;

	char* buff = new char[this->_size];
	strcpy_s(buff, this->_size, this->_string);
	strcat_s(buff, this->_size, string._string);

	delete[] this->_string;
	this->_string = buff;

	_hash = this->hash();
	return *this;
}

MyString & MyString::operator+= (const char * string)
{
		this->_length = this->_length + strlen(string);
		this->_size = this->_length + 1;

		char* buff = new char[this->_size];
		strcpy_s(buff, this->_size, this->_string);
		strcat_s(buff, this->_size, string);

		delete[] this->_string;
		this->_string = buff;

		_hash = this->hash();
		return *this;
}

bool MyString::operator==(MyString & string)
{
	bool trigger = true;
	if (this->_size != string._size) {
		trigger = false;
		return trigger;
	}
	else {
		for (int i = 0; i < this->_length; i++) {
			if (this->_string[i] == string._string[i]) {
				continue;
			}
			else{
				trigger = false;
				return trigger;
			}
		}
		return trigger;
	}
}

bool MyString::operator==(const char * string)
{
	bool trigger = true;
	if (this->_size != strlen(string)) {
		trigger = false;
		return trigger;
	}
	else {
		for (int i = 0; i < this->_length; i++) {
			if (this->_string[i] == string[i]) {
				continue;
			}
			else {
				trigger = false;
				return trigger;
			}
		}
		return trigger;
	}
}

bool MyString::operator<(MyString & string)
{
	if (this->_length > string._length) {
		return false;
	}
	else if (this->_length < string._length) {
		return true;
	}
	else {
		for (int i = 0; i < this->_length; i++) {
			if ((int)this->_string[i] > (int)string[i]) {
				return false;
			}
			else if ((int)this->_string[i] < (int)string[i]) {
				return true;
			}
			else {
				continue;
			}
		}
		return false;
	}
}

bool MyString::operator<(const char * string)
{
	if (this->_length > strlen(string)) {
		return false;
	}
	else if (this->_length < strlen(string)) {
		return true;
	}
	else {
		for (int i = 0; i < this->_length; i++) {
			if ((int)this->_string[i] > (int)string[i]) {
				return false;
			}
			else if ((int)this->_string[i] < (int)string[i]) {
				return true;
			}
			else {
				continue;
			}
		}
		return false;
	}
}

bool MyString::operator>(MyString & string)
{
	if (this->_length > string._length) {
		return true;
	}
	else if (this->_length < string._length) {
		return false;
	}
	else {
		for (int i = 0; i < this->_length; i++) {
			if ((int)this->_string[i] > (int)string[i]) {
				return true;
			}
			else if ((int)this->_string[i] < (int)string[i]) {
				return false;
			}
			else {
				continue;
			}
		}
		return false;
	}
}

bool MyString::operator>(const char * string)
{
	if (this->_length > strlen(string)) {
		return true;
	}
	else if (this->_length < strlen(string)) {
		return false;
	}
	else {
		for (int i = 0; i < this->_length; i++) {
			if ((int)this->_string[i] > (int)string[i]) {
				return true;
			}
			else if ((int)this->_string[i] < (int)string[i]) {
				return false;
			}
			else {
				continue;
			}
		}
		return false;
	}
}

bool MyString::operator<=(MyString & string)
{
	if (this->_length > string._length) {
		return false;
	}
	else if (this->_length < string._length) {
		return true;
	}
	else {
		for (int i = 0; i < this->_length; i++) {
			if ((int)this->_string[i] > (int)string[i]) {
				return false;
			}
			else if ((int)this->_string[i] < (int)string[i]) {
				return true;
			}
			else {
				continue;
			}
		}
		return true;
	}
}

bool MyString::operator<=(const char * string)
{
	if (this->_length > strlen(string)) {
		return false;
	}
	else if (this->_length < strlen(string)) {
		return true;
	}
	else {
		for (int i = 0; i < this->_length; i++) {
			if ((int)this->_string[i] > (int)string[i]) {
				return false;
			}
			else if ((int)this->_string[i] < (int)string[i]) {
				return true;
			}
			else {
				continue;
			}
		}
		return true;
	}
}

bool MyString::operator>=(MyString & string)
{
	if (this->_length > string._length) {
		return true;
	}
	else if (this->_length < string._length) {
		return false;
	}
	else {
		for (int i = 0; i < this->_length; i++) {
			if ((int)this->_string[i] > (int)string[i]) {
				return true;
			}
			else if ((int)this->_string[i] < (int)string[i]) {
				return false;
			}
			else {
				continue;
			}
		}
		return true;
	}
}

bool MyString::operator>=(const char * string)
{
	if (this->_length > strlen(string)) {
		return true;
	}
	else if (this->_length < strlen(string)) {
		return false;
	}
	else {
		for (int i = 0; i < this->_length; i++) {
			if ((int)this->_string[i] > (int)string[i]) {
				return true;
			}
			else if ((int)this->_string[i] < (int)string[i]) {
				return false;
			}
			else {
				continue;
			}
		}
		return true;
	}
}

int MyString::numberGET() {
	int result = 0;
	bool positive = true;
	int start_pos = 0;
	if (this->_string[0] == '-') {
		positive = false;
		start_pos++;
	}
	for (int i = start_pos; i < this->_size; ++i)
	{
		switch (this->_string[i])
		{
		case '0': {
			result *= 10;
			break;
		}
		case '1': {
			result *= 10;
			result += 1;
			break;
		}
		case '2': {
			result *= 10;
			result += 2;
			break;
		}
		case '3': {
			result *= 10;
			result += 3;
			break;
		}
		case '4': {
			result *= 10;
			result += 4;

			break;
		}
		case '5': {
			result *= 10;
			result += 5;
			break;
		}
		case '6': {
			result *= 10;
			result += 6;
			break;
		}
		case '7': {
			result *= 10;
			result += 7;
			break;
		}
		case '8': {
			result *= 10;
			result += 8;
			break;
		}
		case '9': {
			result *= 10;
			result += 9;
			break;
		}
		default: {
			assert(true == false && "ÑÒÐÎÊÀ ÑÎÄÅÐÆÈÒ ÍÅÊÎÐÐÅÊÒÍÛÅ ÑÈÌÂÎËÛ");
		}
		}
	}
	if (positive == true) {
		result *= -1;
	}
	return result;
}

char MyString::operator[](unsigned int index)
{
	assert(index > this->_length || index >= 0);
	return this->_string[index];
}

MyString MyString::reverse()
{
	MyString buff = this->_string;
	int lngth = this->_length;
	for (int i = 0; i < lngth; i++) {
		buff._string[i] = this->_string[lngth - i - 1];
	}
	std::cout << buff;
	for (int i = 0; i < lngth; i++) {
		this->_string[i] = buff._string[i];
	}
	return *this;
}

unsigned MyString::size()
{
	return this->_length;
}

bool MyString::isEmpty()
{
	if (this->_length == 0) {
		return true;
	}
	else {
		return false;
	}
}

int MyString::hash() 
{
	int hash = 0;
	for (int i = 0; i < this->_length; i++) {
		hash += this->_string[i];
	}
	return hash % this->_length;
}

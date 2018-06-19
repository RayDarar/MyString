//Моя реализация класса string
#ifndef _STRING_H_
#define _STRING_H_
#define xf(n) for(int i = 0; i < n; i++)

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <exception>
using namespace std;

class String
{
private:
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	char *m_stringRep;
	int lenth;
	/////////////////////////////////////////////////////////////////////////////////////////////////////



	/////////////////////////////////////////////////////////////////////////////////////////////////////
	int lenthOf(const char *str)
	{
		int sum = 0;
		for (int i = 0;; i++)
		{
			if (str[i] == '\0')
				break;
			sum++;
		}

		return sum;
	}
	bool checkInBOOL(const char *subStr)
	{
		int tlenth = lenthOf(subStr);
		bool flag;
		for (int i = 0; i < this->lenth; i++)
		{
			flag = true;
			if (this->m_stringRep[i] == subStr[0])
			{
				for (int j = 0, i1 = i; j < tlenth; j++, i1++)
				{
					if (this->m_stringRep[i1] != subStr[j])
					{
						flag = false;
						break;
					}
				}
				if (flag == true)
					return true;
			}
		}
	}
	int checkInINT(const char *subStr)
	{
		int tlenth = lenthOf(subStr);
		int sum = 0;
		bool flag;
		for (int i = 0; i < this->lenth; i++)
		{
			flag = true;
			if (this->m_stringRep[i] == subStr[0])
			{
				for (int j = 0, i1 = i; j < tlenth; j++, i1++)
				{
					if (this->m_stringRep[i1] != subStr[j])
					{
						flag = false;
						break;
					}
				}
				if (flag == true)
					sum++;
			}
		}
		return sum;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
public:
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	String() { lenth = 0; m_stringRep = new char[lenth]; }
	String(const char *str)
	{
		lenth = lenthOf(str);
		m_stringRep = new char[lenth];

		xf(lenth)
			m_stringRep[i] = str[i];
	}
	String(int lenth, char c)throw()
	{
		if (lenth < 0)
			throw "Error, bad size";
		else
		{
			this->lenth = lenth;
			m_stringRep = new char[lenth];
			xf(lenth)
				m_stringRep[i] = c;
		}
	}
	String(int lenth) throw()
	{
		if (lenth < 0)
			throw "Error, bad size";
		else
		{
			this->lenth = lenth;
			m_stringRep = new char[lenth];
			xf(lenth)
				m_stringRep[i] = ' ';
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////



	/////////////////////////////////////////////////////////////////////////////////////////////////////
	char operator[](int i)throw()
	{
		if (i < 0 || i > lenth)
			throw "Error, out of lenth";
		else
			return m_stringRep[i];
	}
	friend ostream& operator<<(ostream&os, String str);
	/////////////////////////////////////////////////////////////////////////////////////////////////////



	/////////////////////////////////////////////////////////////////////////////////////////////////////
	char &getAt(int pos) throw()
	{
		if (pos < 0 || pos > lenth)
			throw "Error, out of lenth";
		else
		{
			xf(lenth)
			{
				if (i == pos)
					return m_stringRep[i];
			}
		}
	}
	String& AddCharAt(int pos, char c) throw()
	{
		if (pos < 0 || pos > lenth)
			throw "Error, out of range";
		else
		{
			char *temp;
			temp = new char[this->lenth + 1];

			for (int i = 0, i1 = 0; i < this->lenth; i++, i1++)
			{
				if (i == pos)
				{
					temp[i1] = c;
					i1++;
				}
				temp[i1] = this->m_stringRep[i];
			}
			delete[] this->m_stringRep;
			this->lenth++;
			this->m_stringRep = new char[lenth];

			xf(this->lenth)
				this->m_stringRep[i] = temp[i];

			delete[] temp;
			return *this;
		}
	}
	String& DelCharAt(int pos) throw()
	{
		if (pos < 0 || pos > lenth)
			throw "Error, out of range";
		else
		{
			char *temp;
			temp = new char[lenth - 1];
			for (int i = 0, i1 = 0; i < lenth; i++, i1++)
			{
				if (i == pos)
					i++;
				temp[i1] = m_stringRep[i];
			}
			delete[] m_stringRep;
			lenth--;
			m_stringRep = new char[lenth];
			xf(lenth)
				m_stringRep[i] = temp[i];

			delete[] temp;
			return *this;
		}
	}
	String& ConcatStr(const String& str)
	{
		char *temp;
		temp = new char[this->lenth + str.lenth];

		for (int i = 0, i1 = 0, i2 = 0; i < this->lenth + str.lenth; i++)
		{
			if (i < this->lenth)
			{
				temp[i] = this->m_stringRep[i1];
				i1++;
			}
			else
			{
				temp[i] = str.m_stringRep[i2];
				i2++;
			}
		}
		delete[] this->m_stringRep;
		this->lenth = this->lenth + str.lenth;
		this->m_stringRep = new char[this->lenth];

		xf(this->lenth)
			this->m_stringRep[i] = temp[i];

		delete[] temp;
		return *this;
	}
	String& ConcatStr(const char* str)
	{
		char *temp;
		int tlenth = lenthOf(str);
		temp = new char[this->lenth + tlenth];

		for (int i = 0, i1 = 0, i2 = 0; i < this->lenth + tlenth; i++)
		{
			if (i < this->lenth)
			{
				temp[i] = this->m_stringRep[i1];
				i1++;
			}
			else
			{
				temp[i] = str[i2];
				i2++;
			}
		}
		delete[] this->m_stringRep;
		this->lenth = this->lenth + tlenth;
		this->m_stringRep = new char[this->lenth];

		xf(this->lenth)
			this->m_stringRep[i] = temp[i];

		delete[] temp;
		return *this;
	}
	String& AddStrAt(const String& str, int pos) throw()
	{
		if (pos < 0 || pos > lenth)
			throw "Error, out of range";
		else
		{
			char *temp;
			temp = new char[this->lenth + str.lenth];

			for (int i = 0, i1 = 0; i < this->lenth + str.lenth; i++, i1++)
			{
				if (i == pos)
				{
					for (int j = 0; j < str.lenth; j++, i++)
						temp[i] = str.m_stringRep[j];
				}
				temp[i] = this->m_stringRep[i1];
			}
			delete[] this->m_stringRep;
			this->lenth = this->lenth + str.lenth;
			this->m_stringRep = new char[this->lenth];

			xf(this->lenth)
				this->m_stringRep[i] = temp[i];

			delete[] temp;
			return *this;
		}
	}
	String& AddStrAt(const char *str, int pos) throw()
	{
		if (pos < 0 || pos > lenth)
			throw "Error, out of range";
		else
		{
			char *temp;
			int tlenth = lenthOf(str);
			temp = new char[this->lenth + tlenth];

			for (int i = 0, i1 = 0; i < this->lenth + tlenth; i++, i1++)
			{
				if (i == pos)
				{
					for (int j = 0; j < tlenth; j++, i++)
						temp[i] = str[j];
				}
				temp[i] = this->m_stringRep[i1];
			}
			delete[] this->m_stringRep;
			this->lenth = this->lenth + tlenth;
			this->m_stringRep = new char[this->lenth];

			xf(this->lenth)
				this->m_stringRep[i] = temp[i];

			delete[] temp;
			return *this;
		}
	}
	String& DelStrAt(int begin, int end) throw()
	{
		if (begin > end)
			throw "Error, bad value's";
		else if (begin < 0 || begin > lenth)
			throw "Error, check begig value";
		else if (end < 0 || end > lenth)
			throw "Error, check your end value";
		else
		{
			char *temp;
			int tlenth = lenth - (end - begin);
			temp = new char[tlenth];

			for (int i = 0, i1 = 0; i < lenth; i++, i1++)
			{
				if (i == begin)
					i += end - begin;
				temp[i1] = m_stringRep[i];
			}
			delete[] m_stringRep;
			lenth = tlenth;
			m_stringRep = new char[lenth];
			xf(lenth)
				m_stringRep[i] = temp[i];

			delete[] temp;
			return *this;
		}
	}
	int SubStr(const String& subStr) throw()
	{
		if (subStr.lenth > this->lenth)
			throw "Error, bad lenth of subStr";
		else
		{
			bool flag;
			for (int i = 0; i < this->lenth; i++)
			{
				flag = true;
				if (this->m_stringRep[i] == subStr.m_stringRep[0])
				{
					for (int j = 0, i1 = i; j < subStr.lenth; j++, i1++)
					{
						if (this->m_stringRep[i1] != subStr.m_stringRep[j])
						{
							flag = false;
							break;
						}
					}
					if (flag == true)
						return i;
				}
			}
		}
	}
	int SubStr(const char *subStr) throw()
	{
		int tlenth = lenthOf(subStr);
		if (tlenth > this->lenth)
			throw "Error, bad lenth of subStr";
		else
		{
			bool flag;
			for (int i = 0; i < this->lenth; i++)
			{
				flag = true;
				if (this->m_stringRep[i] == subStr[0])
				{
					for (int j = 0, i1 = i; j < tlenth; j++, i1++)
					{
						if (this->m_stringRep[i1] != subStr[j])
						{
							flag = false;
							break;
						}
					}
					if (flag == true)
						return i;
				}
			}
		}
	}
	String& Replace(const char *subStr, const char* rep) throw()
	{
		int subLenth = lenthOf(subStr);
		if (subLenth > this->lenth)
			throw "Error, bad lenth of subStr";
		else if (checkInBOOL(subStr) == false)
			throw "Error, bad subStr";
		else
		{
			bool flag;
			char *temp;
			int repLenth = lenthOf(rep);
			int sum = checkInINT(subStr);
			int tlenth = (this->lenth - (subLenth * sum)) + (repLenth * sum);

			temp = new char[tlenth];

			for (int i = 0, ii = 0; i < tlenth; i++, ii++)
			{
				flag = true;
				if (m_stringRep[ii] == subStr[0])
				{
					for (int j = 0, i1 = ii; j < subLenth; j++, i1++)
					{
						if (this->m_stringRep[i1] != subStr[j])
						{
							flag = false;
							break;
						}
					}
					if (flag == true)
					{
						ii += subLenth;
						for (int j = 0; j < repLenth; j++, i++)
							temp[i] = rep[j];
					}
				}
				temp[i] = m_stringRep[ii];
			}
			delete[] m_stringRep;
			this->lenth = tlenth;
			m_stringRep = new char[this->lenth];

			xf(this->lenth)
				m_stringRep[i] = temp[i];

			delete[] temp;
			return *this;
		}
	}
	String& Replace(const String& subStr, const String& rep) throw()
	{
		if (subStr.lenth > this->lenth)
			throw "Error, bad lenth of subStr";
		else if (checkInBOOL(subStr.m_stringRep) == false)
			throw "Error, bad subStr";
		else
		{
			bool flag;
			char *temp;
			int sum = checkInINT(subStr.m_stringRep);
			int tlenth = (this->lenth - (subStr.lenth * sum)) + (rep.lenth * sum);

			temp = new char[tlenth];

			for (int i = 0, ii = 0; i < tlenth; i++, ii++)
			{
				flag = true;
				if (m_stringRep[ii] == subStr.m_stringRep[0])
				{
					for (int j = 0, i1 = ii; j < subStr.lenth; j++, i1++)
					{
						if (this->m_stringRep[i1] != subStr.m_stringRep[j])
						{
							flag = false;
							break;
						}
					}
					if (flag == true)
					{
						ii += subStr.lenth;
						for (int j = 0; j < rep.lenth; j++, i++)
							temp[i] = rep.m_stringRep[j];
					}
				}
				temp[i] = m_stringRep[ii];
			}
			delete[] m_stringRep;
			this->lenth = tlenth;
			m_stringRep = new char[this->lenth];

			xf(this->lenth)
				m_stringRep[i] = temp[i];

			delete[] temp;
			return *this;
		}
	}
	char* GetRange(int begin, int end) throw()
	{
		if (begin < 0 || begin > lenth)
			throw "Error, bad value of begin";
		else if (end < 0 || end > lenth)
			throw "Error, bad value of end";
		else if (begin > end)
			throw "Error, bad value of begin & end";
		else
		{
			String tp;
			char *temp;
			int tlenth = end - begin;
			temp = new char[tlenth];

			for (int i = 0, i1 = 0; i < lenth; i++)
			{
				if (i >= begin && i < end)
				{
					temp[i1] = this->m_stringRep[i];
					i1++;
				}
			}
			delete[] tp.m_stringRep;
			tp.lenth = tlenth;
			tp.m_stringRep = new char[tp.lenth];
			xf(tp.lenth)
				tp.m_stringRep[i] = temp[i];

			delete[] temp;
			return tp.m_stringRep;
		}
	}

	void print()
	{
		xf(lenth)
			cout << m_stringRep[i];
		cout << endl;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////



	/////////////////////////////////////////////////////////////////////////////////////////////////////
	~String() { delete[] m_stringRep; }
	int size() { return lenth; }
	const char* GetStrRep() { return m_stringRep; }
	/////////////////////////////////////////////////////////////////////////////////////////////////////
};
ostream& operator<<(ostream&os, String str)
{
	xf(str.lenth)
		os << str.m_stringRep[i];

	return os;
}
#endif // !_STRING_H_

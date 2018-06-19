#include "String.h"

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	String x("I like living thing's");

	cout << "getAt" << endl;
	cout << x.getAt(5) << endl;
	x.print();
	cout << endl;
	_getch();

	cout << "AddCharAt" << endl;
	x.AddCharAt(4, '!');
	x.print();
	cout << endl;
	_getch();

	cout << "DelCharAt" << endl;
	x.DelCharAt(4);
	x.print();
	cout << endl;
	_getch();

	cout << "ConcatChar" << endl;
	x.print();
	x.ConcatStr(" and you :D");
	x.print();
	cout << endl;
	_getch();

	cout << "AddStrAt" << endl;
	x.print();
	x.AddStrAt("WOW!", 4);
	x.print();
	cout << endl;
	_getch();

	cout << "DelStrAt" << endl;
	x.print();
	x.DelStrAt(4, 8);
	x.print();
	cout << endl;
	_getch();

	cout << "SubStr" << endl;
	cout << x.SubStr("li") << endl;
	x.print();
	cout << endl;
	_getch();

	cout << "Replace" << endl;
	x.print();
	x.Replace("li", "AHAH");
	x.print();
	cout << endl;

	_getch();
}
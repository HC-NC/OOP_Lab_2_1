#include <iostream>
#include <Windows.h>

using namespace std;

class Complex
{
	int _actual;
	int _imaginaty;

public:

	Complex()
	{
		_actual = 0;
		_imaginaty = 0;
	};

	Complex(const int, const int);
	Complex(const Complex&);

	void Input();
	void Output();

	bool operator==(const Complex&);
	Complex operator+(const Complex&);
};

Complex::Complex(const int actual, const int imaginaty)
{
	_actual = actual;
	_imaginaty = imaginaty;
}

Complex::Complex(const Complex& complex)
{
	_actual = complex._actual;
	_imaginaty = complex._imaginaty;
}

void Complex::Input()
{
	cout << "Введите действительную часть: ";
	cin >> _actual;

	cout << "Введите мнимую часть: ";
	cin >> _imaginaty;
}

void Complex::Output()
{ 
	if (_actual == 0 && _imaginaty == 0)
	{
		cout << 0 << endl;
		return;
	}

	if (_actual != 0)
	{
		cout << _actual;

		if (_imaginaty > 0)
			cout << "+";
	}

	if (_imaginaty != 0)
		cout << _imaginaty << "i" << endl;
}

bool Complex::operator==(const Complex& complex)
{
	return _actual == complex._actual && _imaginaty == complex._imaginaty;
}

Complex Complex::operator+(const Complex& complex)
{
	return Complex(_actual + complex._actual, _imaginaty + complex._imaginaty);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Complex a, b(1, -3), c(0, 5), d(b);

	a.Output();
	b.Output();
	c.Output();
	d.Output();

	a.Input();

	a.Output();

	if (b == d)
		cout << "b == d" << endl;
	else
		cout << "b != d" << endl;

	if (a == c)
		cout << "a == c" << endl;
	else
		cout << "a != c" << endl;

	d = b + c;

	cout << "b + c = ";
	d.Output();
}
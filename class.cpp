#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
class Fraction {
	int a, b;
public:
	Fraction(int a_ = 1, int b_ = 1); // DEFAULT + PARAMETRE CONSTRUCTOR
	friend ostream& operator << (ostream& os, const Fraction& f);
	Fraction operator+ (const Fraction& f) const;
	Fraction operator- (const Fraction& f) const;
	Fraction operator* (const Fraction& f) const;
	Fraction operator/ (const Fraction& f) const;
	void simplify();
	bool operator>(const Fraction& f) const;
	bool operator<(const Fraction& f) const;
};

//================================================================================//

Fraction::Fraction(int a_, int b_) {// XUONG DAY THI KO CAN " = 1 " NUA 
	a = a_;
	b = b_;
}

Fraction Fraction::operator+(const Fraction& f) const {
	Fraction result;
	result.a = a * f.b + f.a * b;
	result.b = b * f.b;
	return result;
}
Fraction Fraction::operator-(const Fraction& f) const {
	Fraction result;
	result.a = a * f.b - f.a * b;
	result.b = b * f.b;
	return result;
}
Fraction Fraction::operator*(const Fraction& f) const {
	Fraction result;
	result.a = a * f.a;
	result.b = b * f.b;
	return result;
}
Fraction Fraction::operator/ (const Fraction& f) const {
	Fraction result;
	result.a = a * f.b;
	result.b = b * f.a;
	return result;
}
int UCLN(int a, int b)
{
	if (b == 0) return a;
	if (a % b == 0) return b;
	else return UCLN(b, a % b);
}
void Fraction::simplify() {
	a = a / UCLN(a, b);
	b = b / UCLN(a, b);
}
bool Fraction::operator < (const Fraction& f) const {
	if (a < f.a && b == f.b) return 1;
	else return 0;
}
bool Fraction::operator > (const Fraction& f) const {
	if (a > f.a && b == f.b) return 1;
	else return 0;
}
ostream& operator<< (ostream& os, const Fraction& f)
{
	Fraction result;
	result.a = f.a / UCLN(f.a, f.b),
		result.b = f.b / UCLN(f.a, f.b);
	cout << result.a << "/" << result.b << endl;
	return os;
}
int main()
{
	Fraction x(1, 2);
	Fraction y(1, 2);
	x = x + y;
	cout << x;
}
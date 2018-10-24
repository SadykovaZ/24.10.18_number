#include<iostream>
using namespace std;
class number_
{
	int *num;
public:
	explicit number_(int number = 0) //защита от неявного оператора
	{
		num = new int(number);
	}
	int getNumber()const { return *num; }
	void setNumber(int number)
	{
		*num = number;
	}
	~number_()
	{
		delete num;
	}
	number_(const number_&obj)
	{
		this->num = new int(*obj.num);
	}
	number_& operator=(const number_&obj)
	{
		//*this->num = *obj.num;
		//защита от самоприсваивания
		if (this == &obj)
			return *this;
		this->~number_();
		this->num = new int(*obj.num);
		return *this;
	}
	number_&operator+=(const number_&obj)
	{
		*this->num += *obj.num;
		return *this;
	}
	number_&operator-=(const number_&obj)
	{
		*this->num -= *obj.num;
		return *this;
	}
	number_&operator*=(const number_&obj)
	{
		*this->num *= *obj.num;
		return *this;
	}
	number_&operator/=(const number_&obj)
	{
		if (*obj.num == 0)
		{
			cout << "На ноль делить нельзя";
		}
		*this->num /= *obj.num;
		return *this;
	}
	number_ & operator+=(int number)
	{
		*this->num += number;
		return *this;
	}
	number_ & operator-=(int number)
	{
		*this->num -= number;
		return *this;
	}
	number_ & operator*=(int number)
	{
		*this->num *= number;
		return *this;
	}
	number_ & operator/=(int number)
	{
		*this->num /= number;
		return *this;
	}
	number_ & operator=(int n)
	{
		*this->num = n;
		return *this;
	}
	operator int()
	{
		return *this->num;
	}
	operator double()
	{
		return *this->num;
	}
	void operator()()
	{

	}

};
ostream& operator<<(ostream&os, const number_ &num)
{
	os << num.getNumber();
	return os;
}
istream& operator>>(istream& is, number_ &num)
{
	int x;
	is >> x;
	num.setNumber(x);
	return is;
}
number_ operator+(const number_&a, const number_&b)
{
	number_ tmp(a.getNumber());
	tmp += b.getNumber();
	return tmp;
}
number_ operator+(const number_&a, int number)
{
	number_ tmp(a.getNumber());
	tmp += number;
	return tmp;
}
number_ operator+(int number, const number_ &a)
{
	number_ tmp(number);
	tmp += a.getNumber();
	return tmp;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	number_ n;
	cin >> n;
	n = n + 2;
	cout << n;
	

	//number_ n2,n3;
	//
	//cin >> n>>n2;
	///*n++;
	//n = n2 + n3;*/
	//n -= n2;
	//cout << n;
	
	/*n = n2 + 5;
	n = 5 + n3;*/
	//n = n2;
	////самоприсваивание
	//n = n;
	/*cout << n;
	cin >> n;
	number_ n2 = n;
	n2.setNumber(7);
	n2 = n;
	n2.operator=(n);*/
	system("pause");
}
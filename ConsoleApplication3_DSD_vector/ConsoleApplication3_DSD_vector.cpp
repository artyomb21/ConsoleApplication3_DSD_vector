// Тема : class, C++;
//Динамический массив объектов, 
//создавать объект,удалить,
//и инициализировать поля то есть данные.

#include <iostream>
#include <Windows.h>
using namespace std;
class Point
{
	int x, y;
public:
	Point() :x(0), y(0)
	{}
	Point(int x, int y) :x(x), y(y)
	{
	}
	void input_info()
	{
		cout << "input x" << endl;
		cin >> x;
		cout << "input y" << endl;
		cin >> y;
	}
	void show()
	{
		cout << "x = " << x << "   y = " << y << endl;
	}
};

class Dinamic_array
{
private:
	Point* p;
	int n;
public:
	Dinamic_array() :p(NULL), n(0) {}
	void add()
	{
		if (n == 0)
		{
			n = 1;
			p = new Point[n];
			p[n - 1].input_info();
		}
		else {
			Point* t = p;
			++n;
			p = new Point[n];
			for (size_t i = 0; i < n - 1; i++)
			{
				p[i] = t[i];
			}
			p[n - 1].input_info();
			delete[] t;
		}
	}
	void delete_object(int number_of_delete_dobject)
	{
		++number_of_delete_dobject;
		Point* t = p;
		p = new Point[n - 1];
		//t[i] p[j];
		for (int i = 0, j = 0; i < n; ++i, ++j)
		{
			if (i == number_of_delete_dobject)
			{
				++i;
			}
			p[j] = t[i];

		}
		--n;
		delete[] t;
	}
	void show_objects()
	{
		for (int i = 0; i < n; i++)
		{
			p[i].show();
		}
	}
};
int main()
{
	Dinamic_array object_1;
	object_1.add();
	object_1.add();
	object_1.add();
	object_1.show_objects();
	object_1.delete_object(1);
	cout << endl;
	object_1.show_objects();
}

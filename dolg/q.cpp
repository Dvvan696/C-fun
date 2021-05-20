#include <iostream>
#include <vector>
using namespace std;

struct point { double x; double y; };
struct rectangle {
	point leftlow;
	point righthigh;
	point THRID;
	double Perim() {
		double perim, lenx, leny;
		if (leftlow.x > righthigh.x)
			lenx = leftlow.x - righthigh.x;
		else
			lenx = righthigh.x - leftlow.x;
		if (leftlow.y > righthigh.y)
			leny = leftlow.y - righthigh.y;
		else
			leny = righthigh.y - leftlow.y;
		perim = lenx * 2 + leny * 2;
		return perim;
	}
	double Square() {
		double square, lenx, leny;
		if (leftlow.x > righthigh.x)
			lenx = leftlow.x - righthigh.x;
		else
			lenx = righthigh.x - leftlow.x;
		if (leftlow.y > righthigh.y)
			leny = leftlow.y - righthigh.y;
		else
			leny = righthigh.y - leftlow.y;
		square = leny * lenx;
		return square;
	}
	bool Check() {
		if ((((THRID.x < righthigh.x) && (THRID.x > leftlow.x)) || ((THRID.x < leftlow.x) && (THRID.x > righthigh.x))) && (((THRID.y < leftlow.y) && (THRID.y > righthigh.y)) || ((THRID.y < righthigh.y) && (THRID.y > leftlow.y))))
			return true;
		else
			return false;
	};
};

int main() {
	rectangle NOW;
	cout << "EXFperim" << endl;
	cin >> NOW.leftlow.x;
	cout << "EYFperim" << endl;
	cin >> NOW.leftlow.y;
	cout << "EXSqare" << endl;
	cin >> NOW.righthigh.x;
	cout << "EYSqare" << endl;
	cin >> NOW.righthigh.y;
	cout << "EXThrid" << endl;
	cin >> NOW.THRID.x;
	cout << "EYThrid" << endl;
	cin >> NOW.THRID.y;
	cout << "perim = " << NOW.Perim() << endl;
	cout << "square = " << NOW.Square() << endl;
	if (NOW.Check())
		cout << "Third point is IN the rectangle" << endl;
	else
		cout << "Third point is OUT of the rectangle" << endl;
	return 0;
}
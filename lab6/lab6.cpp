#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void OutputEl(int a) {
	cout << a << " ";
}

int main() {
    setlocale(LC_ALL, "ru");

	int intersect = 0;
	vector<int> Intersect;

	vector<int> MyVector = { 1, 1, 1, 3, 3, 1,
							 2, 1, 2, 3, 4, 1,
							 5, 1, 5, 3, 7, 1 
	};

	cout << "Данное множество точек: " << endl;
	for_each(MyVector.begin(), MyVector.end(), OutputEl);
	cout << endl << endl << "Объектов в векторе: " << MyVector.size() << endl << endl;

	int x1, y1, x2, y2, x3, y3, x5, y5, x6, y6, x7, y7;

	for (int i = 0; i < MyVector.size(); i = i + 6) {
		x1 = MyVector.at(i); x2 = MyVector.at(i + 2); x3 = MyVector.at(i + 4);
		y1 = MyVector.at(i + 1); y2 = MyVector.at(i + 3); y3 = MyVector.at(i + 5);

		for (int j = 0; j < MyVector.size(); j = j + 6) {
			x5 = MyVector.at(j); x6 = MyVector.at(j + 2); x7 = MyVector.at(j + 4);
			y5 = MyVector.at(j + 1); y6 = MyVector.at(j + 3); y7 = MyVector.at(j + 5);

			int a = (x1 - x5) * (y2 - y1) - (x2 - x1) * (y1 - y5);
			int b = (x2 - x5) * (y3 - y2) - (x3 - x2) * (y2 - y5);
			int c = (x3 - x5) * (y1 - y3) - (x1 - x3) * (y3 - y5);
			int e = (x1 - x6) * (y2 - y1) - (x2 - x1) * (y1 - y6);
			int f = (x2 - x6) * (y3 - y2) - (x3 - x2) * (y2 - y6);
			int g = (x3 - x6) * (y1 - y3) - (x1 - x3) * (y3 - y6);
			int i = (x1 - x7) * (y2 - y1) - (x2 - x1) * (y1 - y7);
			int l = (x2 - x7) * (y3 - y2) - (x3 - x2) * (y2 - y7);
			int k = (x3 - x7) * (y1 - y3) - (x1 - x3) * (y3 - y7);

			if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0) ||
				(e >= 0 && f >= 0 && g >= 0) || (e <= 0 && f <= 0 && g <= 0) ||
				(i >= 0 && l >= 0 && k >= 0) || (i <= 0 && l <= 0 && k <= 0)) {
				cout << "Треугольник пересекается с треугольником " << endl;
				intersect++;
			}
			else cout << "Треугольник НЕ пересекается с треугольником " << endl;
		}
		cout << "Кол-во пересечений " << intersect << endl << endl;
		Intersect.push_back(intersect);
		intersect = 0;
	}

	cout << "Пересечения на каждый треугольник: ";
	for_each(Intersect.begin(), Intersect.end(), OutputEl);
	cout << endl;

	auto result = max_element(Intersect.begin(), Intersect.end());
	cout << "\nТреугольник с max кол-вом пересечений на " << distance(Intersect.begin(), result) << " позиции\n";

    return 0;
}
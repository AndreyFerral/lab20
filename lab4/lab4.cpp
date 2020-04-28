#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>
using namespace std;

void OutputEl(int a) {
	cout << a << " ";
}

int main() {
	setlocale(LC_ALL, "ru");
	
	auto start = chrono::high_resolution_clock::now();
	vector<int> MyVector(1000000, 0);

	for (int i = 0; i < MyVector.size(); i++) {
		MyVector.at(i) = rand() % 61 - 30;
	}

	cout << "��������� � �������: " << MyVector.size() << endl;
	//for_each(MyVector.begin(), MyVector.end(), OutputEl);

	int CountPositive = count_if(MyVector.begin(), MyVector.end(), [](int numb) {return numb >= 0;  });
	cout << "\n������������� ��������� (0 ����): " << CountPositive << endl;

	auto rFirstZero = find_if(MyVector.rbegin(), MyVector.rend(), [](int zero) { return !zero; });
	auto result = accumulate(MyVector.rbegin(), rFirstZero, 0);
	cout << "\n����� ��������� ����� ���� ����: " << result << endl;
	
	sort(MyVector.begin(), MyVector.end(), [](int a, int b) {
		return a < b;
	});
	
	//cout << "\n������, � ������� ������� �������� <2, ����� ���������:\n";
	//for_each(MyVector.begin(), MyVector.end(), OutputEl);

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "\n����� ����������: " << duration.count() << " sec"<< endl;

	return 0;
}
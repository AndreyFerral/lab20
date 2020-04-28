#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

struct ZNAK {
	string name;
	string zodiak;
	int datebt[3];
	void OutputEl() {
		cout << "���: " << this->name << endl;
		cout << "���� �������: " << this->zodiak << endl;
		cout << "���� ��������: ";
		for (int j = 0; j < 3; j++) {
			cout << this->datebt[j] << " ";
		}
		cout << endl << endl;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<ZNAK> znak;

	int count;
	cout << "������� �� ������ �������� ���������? "; cin >> count; cout << endl;
	for (int i = 0; i < count; i++) {
		znak.push_back(ZNAK());
		cout << "������� ���: "; cin >> znak[i].name;
		cout << "������� ���� �������: "; cin >> znak[i].zodiak;
		cout << "������� ����: "; cin >> znak[i].datebt[0];
		cout << "������� �����: "; cin >> znak[i].datebt[1];
		cout << "������� ���: "; cin >> znak[i].datebt[2]; cout << endl;
	}

	cout << "��������� ������: " << endl;
	for (auto el : znak) {
		el.OutputEl();
	}

	sort(znak.begin(), znak.end(), [](ZNAK a, ZNAK b) {
		return a.zodiak < b.zodiak;
	});

	cout << "��������������� ������ (�� �������): " << endl;
	for (auto el : znak) {
		el.OutputEl();
	}

	int month = 0;
	bool find = false;
	cout << "���������� � �����, ��������� � ��������� ������������� �����" << endl; 
	cout << "������� �����: "; cin >> month; cout << endl;

	auto result = find_if(znak.begin(), znak.end(), [&](ZNAK& c) {
		return c.datebt[1] == month;
		});
	if (result != znak.end()) {
		result->OutputEl();
		find = true;
	}
	if (find == false) cout << "���������� �� �������";

	return 0;
}

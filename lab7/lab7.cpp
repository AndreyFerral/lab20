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
		cout << "»м€: " << this->name << endl;
		cout << "«нак зодиака: " << this->zodiak << endl;
		cout << "ƒата рождени€: ";
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
	cout << "—колько вы хотите добавить элементов? "; cin >> count; cout << endl;
	for (int i = 0; i < count; i++) {
		znak.push_back(ZNAK());
		cout << "¬ведите им€: "; cin >> znak[i].name;
		cout << "¬ведите знак зодиака: "; cin >> znak[i].zodiak;
		cout << "¬ведите день: "; cin >> znak[i].datebt[0];
		cout << "¬ведите мес€ц: "; cin >> znak[i].datebt[1];
		cout << "¬ведите год: "; cin >> znak[i].datebt[2]; cout << endl;
	}

	cout << "¬веденные данные: " << endl;
	for (auto el : znak) {
		el.OutputEl();
	}

	sort(znak.begin(), znak.end(), [](ZNAK a, ZNAK b) {
		return a.zodiak < b.zodiak;
	});

	cout << "ќтсортированные данные (по зодиаку): " << endl;
	for (auto el : znak) {
		el.OutputEl();
	}

	int month = 0;
	bool find = false;
	cout << "»нформаци€ о люд€х, родившис€ в введенный пользователем мес€ц" << endl; 
	cout << "¬ведите мес€ц: "; cin >> month; cout << endl;

	auto result = find_if(znak.begin(), znak.end(), [&](ZNAK& c) {
		return c.datebt[1] == month;
		});
	if (result != znak.end()) {
		result->OutputEl();
		find = true;
	}
	if (find == false) cout << "»нформаци€ не найдена";

	return 0;
}

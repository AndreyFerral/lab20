#include <list>
#include <iostream>
#include <windows.h>
using namespace std;

class CardOfAbonents {
private:
	string name;
	int number;
	int talktime;
public:
	CardOfAbonents(string name, int number, int talktime) {
		this->name = name;
		this->number = number;
		this->talktime = talktime;
	}

	void OutputInformation() {
		cout << "ФИО абонента: " << this->name << endl;
		cout << "Номер абонента: " << this->number << endl;
		cout << "Время разговора: " << this->talktime << endl << endl;
	}

	int GetNumber() {
		return number;
	}

	int GetTalktime() {
		return talktime;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list <CardOfAbonents> MyListCard;
	
	string name = "";
	int number, talktime, count;
	int FindNumber;

	cout << "1. Добавить элементы "; cout << endl;
	cout << "2. Вывести все элементы "; cout << endl;
	cout << "3. Вывод извещения на оплату телефонного разговора "; cout << endl << endl;

	int action;
	while (true) {
		cout << "Выберите действие: "; cin >> action; cout << endl;
		switch (action) {
		case 1:
			cout << "Сколько вы хотите добавить элементов? "; cin >> count; cout << endl;
			for (int i = 0; i < count; i++) {
				cout << "Введите ФИО: "; cin >> name;
				cout << "Введите номер телефона: "; cin >> number;
				cout << "Введите время разговора: "; cin >> talktime; cout << endl;
				MyListCard.push_back(CardOfAbonents(name, number, talktime));
			}
			break;
		case 2:
			for (auto el : MyListCard) {
				el.OutputInformation();
			}
			break;
		case 3:
			cout << "Введите номер телефона, по которому нужно найти человека: "; cin >> FindNumber;
			auto result = find_if(MyListCard.begin(), MyListCard.end(), [&](CardOfAbonents& c) {
				return c.GetNumber() == FindNumber;
				});
			if (result != MyListCard.end()) {
				cout << "\nВам нужно оплатить телефонный разговор по тарифу. ВашиСекунды * 2 = рублей" << endl;
				cout << "С вас: " <<  result->GetTalktime() * 2 << " руб." << endl;
			}
			else cout << "Людей не найдено" << endl;
		}
	}
	return 0;
}
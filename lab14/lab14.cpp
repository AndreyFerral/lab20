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
		cout << "��� ��������: " << this->name << endl;
		cout << "����� ��������: " << this->number << endl;
		cout << "����� ���������: " << this->talktime << endl << endl;
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

	cout << "1. �������� �������� "; cout << endl;
	cout << "2. ������� ��� �������� "; cout << endl;
	cout << "3. ����� ��������� �� ������ ����������� ��������� "; cout << endl << endl;

	int action;
	while (true) {
		cout << "�������� ��������: "; cin >> action; cout << endl;
		switch (action) {
		case 1:
			cout << "������� �� ������ �������� ���������? "; cin >> count; cout << endl;
			for (int i = 0; i < count; i++) {
				cout << "������� ���: "; cin >> name;
				cout << "������� ����� ��������: "; cin >> number;
				cout << "������� ����� ���������: "; cin >> talktime; cout << endl;
				MyListCard.push_back(CardOfAbonents(name, number, talktime));
			}
			break;
		case 2:
			for (auto el : MyListCard) {
				el.OutputInformation();
			}
			break;
		case 3:
			cout << "������� ����� ��������, �� �������� ����� ����� ��������: "; cin >> FindNumber;
			auto result = find_if(MyListCard.begin(), MyListCard.end(), [&](CardOfAbonents& c) {
				return c.GetNumber() == FindNumber;
				});
			if (result != MyListCard.end()) {
				cout << "\n��� ����� �������� ���������� �������� �� ������. ����������� * 2 = ������" << endl;
				cout << "� ���: " <<  result->GetTalktime() * 2 << " ���." << endl;
			}
			else cout << "����� �� �������" << endl;
		}
	}
	return 0;
}
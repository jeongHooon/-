#include <iostream>
#include <string>

using namespace std;
class Card {
	string name;
	string office;
	string adress;
	string fax;
	string call;
	string email;
public:
	void datainput() {
		cout << "�̸��� �Է� �Ͻÿ� : " << endl;
		cin >> name;
		cout << "�Ҽ� �Է� �Ͻÿ� : " << endl;
		cin >> office;
		cout << "�ּҸ� �Է� �Ͻÿ� : " << endl;
		cin >> adress;
		cout << "�ѽ���ȣ�� �Է� �Ͻÿ� : " << endl;
		cin >> fax;
		cout << "��ȣ�� �Է� �Ͻÿ� : " << endl;
		cin >> call;
		cout << "�̸����� �Է� �Ͻÿ� : " << endl;
		cin >> email;
	}
	void datashow(string find_name) {
		if (find_name == name) {
			cout << "===============================" << endl;
			cout << "�̸� : " << name << endl;
			cout << "�Ҽ� : " << office << endl;
			cout << "�ּ� : " << adress << endl;
			cout << "�ѽ� : " << fax << endl;
			cout << "��ȣ : " << call << endl;
			cout << "�̸��� : " << email << endl;
			cout << "===============================" << endl;
		}
	}
};
int main() {
	int size = 0;
	cout << "���� ������ ������ �Է� : ";
	cin >> size;

	Card* card = new Card[size];

	for (int i = 0; i < size; ++i)
		card[i].datainput();
	cout << "ã�� �̸��� �Է��Ͻÿ� : ";

	string find_name;
	cin >> find_name;

	for (int i = 0; i < size; ++i) {
		card[i].datashow(find_name);
	}
}
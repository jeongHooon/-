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
		cout << "이름을 입력 하시오 : " << endl;
		cin >> name;
		cout << "소속 입력 하시오 : " << endl;
		cin >> office;
		cout << "주소를 입력 하시오 : " << endl;
		cin >> adress;
		cout << "팩스번호를 입력 하시오 : " << endl;
		cin >> fax;
		cout << "번호를 입력 하시오 : " << endl;
		cin >> call;
		cout << "이메일을 입력 하시오 : " << endl;
		cin >> email;
	}
	void datashow(string find_name) {
		if (find_name == name) {
			cout << "===============================" << endl;
			cout << "이름 : " << name << endl;
			cout << "소속 : " << office << endl;
			cout << "주소 : " << adress << endl;
			cout << "팩스 : " << fax << endl;
			cout << "번호 : " << call << endl;
			cout << "이메일 : " << email << endl;
			cout << "===============================" << endl;
		}
	}
};
int main() {
	int size = 0;
	cout << "만들 명함의 개수를 입력 : ";
	cin >> size;

	Card* card = new Card[size];

	for (int i = 0; i < size; ++i)
		card[i].datainput();
	cout << "찾을 이름을 입력하시오 : ";

	string find_name;
	cin >> find_name;

	for (int i = 0; i < size; ++i) {
		card[i].datashow(find_name);
	}
}
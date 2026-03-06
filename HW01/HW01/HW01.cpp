#include <iostream>

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	if (count == 1) {
		*p_HPPotion -= 1;
	}
	else if (count == 2) {
		*p_MPPotion -= 1;
	}
	else if (count == 3) {
		*p_HPPotion += 1;
		*p_MPPotion += 1;
	}

	return;
}

void setBuyPotion(int count, int* p_BuyHpPotion, int* p_BuyMpPotion)
{
	if (count == 1) {
		*p_BuyHpPotion += 1;
	}
	else if (count == 2) {
		*p_BuyMpPotion += 1;
	}
}

int main()
{
	int stat[4];
	int statValue[3] = {100, 100, 100};
	int hpcnt = 5;
	int mpcnt = 5;
	int level = 1;
	int money = 10000;

	while (1) {
		cout << "hp와 mp를 입력하시오.";
		cin >> stat[0] >> stat[1];

		if (stat[0] < 50 || stat[1] < 50) {
			cout << "50이상의 값만 입력가능 다시 입력해주십시오." << endl;
		}
		else {
			break;
		}

	}
	while (1) {
		cout << "공격력과 방어력을 입력하시오: ";
		cin >> stat[2] >> stat[3];

		if (stat[2] <= 0 || stat[3] <= 0) {
			cout << "0보다 큰값을 입력하시오." << endl;
		}
		else {
			break;
		}
	}
	while (1) {

		int sel;

		cout << "1. HP up / 2. MP up / 3. 공격력 up / 4. 방어력 up / 5. 현재 능력치 / 6. Level up / 7. 포션 구매 / 8. 사냥하기 / 9. 책읽기 /  0. 나가기" << endl;

		cin >> sel;

		if (sel == 1) {
			if (hpcnt > 0) {
				stat[0] += 50;
				setPotion(1, &hpcnt, &mpcnt);
				cout << "현재 hp: " << stat[0] << endl << "남은 포션 수 : " << hpcnt << endl;
			}
			else {
				cout << "포션이 부족합니다. 포션을 충전하세요.";
			}
			continue;
		}
		else if (sel == 2) {
			if (mpcnt > 0) {
				stat[1] += 50;
				setPotion(2, &hpcnt, &mpcnt);
				cout << "현재 mp: " << stat[1] << endl << "남은 포션 수 : " << mpcnt << endl;
			}
			else {
				cout << "포션이 부족합니다. 포션을 충전하세요." << endl;
			}
			continue;
		}
		else if (sel == 3) {
			stat[2] *= 2;
			cout << "공격력이 2배 증가하였습니다!" << endl << "현재 공격력 :" << stat[2] << endl;
			continue;
		}
		else if (sel == 4) {
			stat[3] *= 2;
			cout << "방어력이 2배 증가하였습니다!" << endl << "현재 방어력 :" << stat[3] << endl;
			continue;
		}
		else if (sel == 5) {
			cout << "hp :" << stat[0] << endl;
			cout << "mp :" << stat[1] << endl;
			cout << "공격력 :" << stat[2] << endl;
			cout << "방어력 :" << stat[3] << endl;
			cout << "레벨 :" << level << endl;
			cout << "현재 hp / mp 포션 수 " << hpcnt << " / " << mpcnt << endl;
			cout << "현재 자금 " << money << endl;
			cout << "현재 힘 능력치 " << statValue[0] << endl;
			cout << "현재 민첩 능력치 " << statValue[1] << endl;
			cout << "현재 지능 능력치 " << statValue[2] << endl;


			continue;
		}
		else if (sel == 6) {
			setPotion(3, &hpcnt, &mpcnt);
			level += 1;
			money += 1000;
			cout << "레벨업!! hp/mp 포션이 하나씩 지급됩니다." << endl;
			cout << "1000원을 획득합니다." << endl;
			cout << "현재 hp / mp " << stat[0] << " / " << stat[1] << endl;
			cout << "현재 포션 수 " << hpcnt << " / " << mpcnt << endl;
			cout << "현재 레벨 " << level << endl;
			
			continue;
		}
		else if (sel == 7) {

			int sel2;

			cout << "포션 상점입니다. 무엇을 구입하시겠습니까?" << endl;
			cout << "1. hp포션(500원), 2.mp 포션(500원)  *입력된 정보가 맞지 않을시 자동으로 상점을 떠납니다." << endl;
			cout << "현재 잔액: " << money << endl;
			cin >> sel2;
			if (sel2 == 1) {
				setBuyPotion(1, &hpcnt, &mpcnt);
				money -= 500;
				cout << "hp포션을 구입하였습니다." << endl;
				cout << "남은 잔액: " << money << endl;
				cout << "남은 hp포션: " << hpcnt << endl;
			}
			else if (sel2 == 2) {
				setBuyPotion(2, &hpcnt, &mpcnt);
				money -= 500;
				cout << "mp포션을 구입하였습니다." << endl;
				cout << "남은 잔액: " << money << endl;
				cout << "남은 mp포션: " << mpcnt << endl;
			}
			else {
				cout << "안녕히가십시오." << endl;
			}
			continue;
		}
		else if (sel == 8) {
			stat[0] -= 50;
			stat[1] -= 50;
			statValue[0] += 50;
			statValue[1] += 50;
			money += 2000;
			level += 1;
			setPotion(3, &hpcnt, &mpcnt);
			if (stat[0] <= 0) {
				cout << "캐릭터가 사망하였습니다." << endl;
				break;
			}
			if (stat[1] <= 0) {
				cout << "mp를 모두 소모하였습니다. 사냥을 종료합니다." << endl;
				stat[1] = 0;

				continue;
			}
			cout << "사냥을 시작합니다." << endl;
			cout << "hp와 mp를 소모하였습니다." << endl;
			cout << "힘 능력치와 민첩 능력치를 얻었습니다." << endl;
			cout << "2000원을 획득했습니다." << endl;
			cout << "현재 자금" << money << endl;
			cout << "레벨업!! hp/mp 포션이 하나씩 지급됩니다." << endl;

			continue;
		}
		else if (sel == 9) {
			statValue[2] += 100;
			cout << "책읽기로 지능을 얻었습니다." << endl;

			continue;
		}
		else if (sel == 0) {
			cout << "프로그램이 종료됩니다.";
			break;
		}
		else {
			cout << "잘못된 입력정보입니다." << endl;
			continue;
		}
		return 0;
	}
}	
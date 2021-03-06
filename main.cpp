#include "Manager.h"

using namespace std;

Manager* manager;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");

	manager = new Manager;

	int local;
	bool flag = true;
	bool flag_new = true;

	cout << "------------\nВ данной программе реализован паттерн строитель по сборке разного типа транспорта. Есть 3 вида ТС:\n1. Автомобиль\n2. Квадроцикл\n3. Мотоцикл\n"
		"Пользовтелю предлагается выбор того, какой вид транспорта он хочет получить.\nПосле выбора типа транспорта, происходит сам процесс создания классом Builder.\n"
		"Указание к созданию транспорта дает класс Manager (или Director, в других источниках про данный паттерн).\nТ.е. алгоритм имеет такой вид:\n1. Выбор типа ТС пользователем\n"
		"2. Это указание отправляется Manager\n3. Manager говорит Builder, что необходимо создать и какие параметры выбрал пользователь для своего ТС\n"
		"4. Пользователь получает готовый результат\n------------\n";
	system("pause");
	while (flag) {
		system("cls");
		flag_new = true;
		cout << "Выберите тип ТС, которое хотите получить:\n1. Автомобиль\n2. Квадроцикл\n3. Мотоцикл\n4. Выход из программы\n";

		while (!(cin >> local)) {
			cout << "Неверный ввод, повторите.\n";
			cin.clear();
			cin.ignore(32.767, '\n');
		}

		switch (local) {
		case 1:
			while (flag_new) {
				system("cls");
				cout << "Какой автомобиль вы хотите?\n1. Новый\n2. Старый\n";

				while (!(cin >> local)) {
					cout << "Неверный ввод, повторите.\n";
					cin.clear();
					cin.ignore(32.767, '\n');
				}

				switch (local) {
				case 1:
					manager->create_car();
					flag_new = false;
					break;
				case 2:
					manager->output_old_auto();
					flag_new = false;
					break;
				default:
					cout << "Неверный ввод, повторите.\n";
					system("pause");
				}
			}
			break;
		case 2:
			while (flag_new) {
				system("cls");
				cout << "Какой квадроцикл вы хотите?\n1. Новый\n2. Старый\n";

				while (!(cin >> local)) {
					cout << "Неверный ввод, повторите.\n";
					cin.clear();
					cin.ignore(32.767, '\n');
				}

				switch (local) {
				case 1:
					manager->create_kvadro();
					flag_new = false;
					break;
				case 2:
					manager->output_old_kvadro();
					flag_new = false;
					break;
				default:
					cout << "Неверный ввод, повторите.\n";
					system("pause");
				}
			}
			break;
		case 3:
			while (flag_new) {
				system("cls");
				cout << "Какой мотоцикл вы хотите?\n1. Новый\n2. Старый\n";

				while (!(cin >> local)) {
					cout << "Неверный ввод, повторите.\n";
					cin.clear();
					cin.ignore(32.767, '\n');
				}

				switch (local) {
				case 1:
					manager->create_moto();
					flag_new = false;
					break;
				case 2:
					manager->output_old_moto();
					flag_new = false;
					break;
				default:
					cout << "Неверный ввод, повторите.\n";
					system("pause");
				}
			}
			break;
		case 4:
			flag = false;
			break;
		default:
			cout << "Неверный ввод, повторите.\n";
			system("pause");
		}
	}

	delete manager;
	return 0;
}

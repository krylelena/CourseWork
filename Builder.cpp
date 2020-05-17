#include "Builder.h"

Builder::Builder() {
	type = new string[N];				//Тип транспорта
	wheel = new int;					//Количество колес
	color = new string[N];				//Цвет
	price = new int;					//Цена
	engine_type = new string[N];		//Тип двигателя
	engine_volume = new float;			//Объем двигателя
	year = new int;						//Год выпуска
	mark = new string[N];				//Марка
	model = new string [N];				//Модель
	mass = new int;						//Масса
	min_fuel = new string[N];			//Требование к топливу (минимальное)
	type_of_steering = new string[N];	//Тип рулевого управления
	consuptition = new float;			//Расход топлива
	volume_trunk = new int;				//Объем багажника
}

Builder::~Builder() {
	type = nullptr;
	wheel = nullptr;
	color = nullptr;
	price = nullptr;
	engine_type = nullptr;
	engine_volume = nullptr;
	year = nullptr;
	mark = nullptr;
	model = nullptr;
	mass = nullptr;
	min_fuel = nullptr;
	type_of_steering = nullptr;
	consuptition = nullptr;
	volume_trunk = nullptr;

	delete type;
	delete wheel;
	delete color;
	delete price;
	delete engine_type;
	delete engine_volume;
	delete year;
	delete mark;
	delete model;
	delete mass;
	delete min_fuel;
	delete type_of_steering;
	delete consuptition;
	delete volume_trunk;
}

void Builder::create_auto(fstream& TS) {
	*type = "Auto";
	*wheel = 4;
	choose_color();
	choose_price();
	choose_engine_type();
	choose_engine_volume();
	choose_year();

	choose_mark_auto();
	choose_model_auto();

	choose_mass();
	choose_min_fuel();
	choose_type_of_steering();
	choose_consuptition();
	choose_volume_trunk();
	output_new(TS);
}

void Builder::create_kvadro(fstream& TS) {
	*type = "Kvadro";
	*wheel = 4;
	choose_color();
	choose_price();
	choose_engine_type();
	choose_engine_volume();
	choose_year();

	choose_mark_kvadro();
	choose_model_kvadro();

	choose_mass();
	choose_min_fuel();
	choose_type_of_steering();
	choose_consuptition();
	choose_volume_trunk();
	output_new(TS);
}

void Builder::create_moto(fstream& TS) {
	*type = "Moto";
	*wheel = 2;
	choose_color();
	choose_price();
	choose_engine_type();
	choose_engine_volume();
	choose_year();

	choose_mark_moto();
	choose_model_moto();

	choose_mass();
	choose_min_fuel();
	choose_type_of_steering();
	choose_consuptition();
	choose_volume_trunk();
	output_new(TS);
}

void Builder::output() {
	setlocale(LC_ALL, "ru");
	cout << "Тип транспорта: " << *type << "\nКоличество колес: " << *wheel << "\nЦвет: " << *color << "\nЦена: " << *price << endl;
	cout << "Тип двигателя: " << *engine_type << "\nОбъем двигателя: " << *engine_volume << "\nГод выпуска: " << *year << "\nМарка: " << *mark << endl;
	cout << "Модель: " << *model << "\nМасса: " << *mass << "\nТребование к топливу(минимальное): " << *min_fuel << "\nТип рулевого "
		"управления: " << *type_of_steering << "\nРасход топлива: " << *consuptition << "\nОбъем багажника: " << *volume_trunk << endl;
}

void Builder::output_new(fstream& TS) {
	int local;
	bool flag = true;

	string file = *type + ".txt";
	TS.open(file, ios::app);

	if (!TS.is_open()) {
		cout << "Файл " << file << " не открыт\n";
		exit(1);
	}

	output();

	cout << "\n------\nСохранить текущее ТС?\n1. Да\n2. Нет\n------\n";

	while (flag) {

		while (!(cin >> local)) {
			cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
			cin.clear();
			cin.ignore(32.767, '\n');
		}

		switch (local) {
		case 1:
			TS << *type << "\n" << *wheel << "\n" << *color << "\n" << *price << "\n" << *engine_type << "\n" << *engine_volume << "\n"
				<< *year << "\n" << *mark << "\n" << *model << "\n" << *mass << "\n" << *min_fuel << "\n" << *type_of_steering << "\n"
				<< *consuptition << "\n" << *volume_trunk << "\n\n";
			flag = false;
			break;
		case 2:
			flag = false;
			break;
		default:
			cout << "Неверный ввод, повторите.\n";
			system("pause");
		}
	}
	TS.close();
	system("pause");
}

void Builder::reading(fstream& TS) {
	TS >> *type;
	TS >> *wheel;
	TS >> *color;
	TS >> *price;
	TS >> *engine_type;
	TS >> *engine_volume;
	TS >> *year;
	TS >> *mark;
	TS >> *model;
	TS >> *mass;
	TS >> *min_fuel;
	TS >> *type_of_steering;
	TS >> *consuptition;
	TS >> *volume_trunk;
}

void Builder::reading_old(fstream& TS, string Type) {
	string file = Type + ".txt";
	TS.open(file, ios::in);

	if (!TS.is_open()) {
		cout << "Файл " << file << " не открыт\n";
		system("pause");
		exit(1);
	}

	system("cls");

	for (count = 0; !TS.eof(); count++) {
		if (TS.eof())
			break;

		reading(TS);
	}

	TS.close();
	TS.open(file, ios::in);

	for (int i = 1; i < count; i++) {
		if (TS.eof())
			break;

		reading(TS);

		cout << "------\nTC № " << i << endl;
		output();
	}
	system("pause");
	TS.close();
}

void Builder::select(fstream& TS, string Type) {
	setlocale(LC_ALL, "ru");

	int local;
	bool flag1 = true, flag2 = true;

	string file = Type + ".txt";
	TS.open(file, ios::in);

	if (!TS.is_open()) {
		cout << "Файл " << file << " не открыт\n";
		system("pause");
		exit(1);
	}

	while (flag1) {
		cout << "------\nХотите выбрать определенное ТС?\n1. Да\n2. Нет\n";
		cin >> local;
		switch (local) {
		case 1:
			while (flag2) {
				cout << "Введите № ТС, которое Вам понравилось\n";
				cin >> local;

				if (local > 0 && local < count) {
					local--;

					for (int i = 0; i < count; i++) {
						if (TS.eof())
							break;

						reading(TS);
						if (i == local) {
							system("cls");
							cout << "TC № " << i + 1 << endl;
							output();
							system("pause");
							break;
						}
					}

					flag2 = false;
				}
				else {
					cout << "Неверный ввод, повторите.\n";
					system("pause");
				}
			}
			flag1 = false;
			break;
		case 2:
			flag1 = false;
			break;
		default:
			cout << "Неверный ввод, повторите.\n";
			system("pause");
		}
	}

	TS.close();
}


/*
	Методы выбора цвета, марки, модели и т.д.
	Каждый метод может быть вызан при создании разного типа транспорта
*/
void Builder::choose_color() {
	//Выбор цвета
	int local;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "Выберите цвет ТС:\n1. Red\n2. Blue\n3. Yellow\n4. Black\n5. White\n";

		while (!(cin >> local)) {
			cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
			cin.clear();
			cin.ignore(32.767, '\n');
		}

		switch (local) {
		case 1:
			*color = "Red";
			flag = false;
			break;
		case 2:
			*color = "Blue";
			flag = false;
			break;
		case 3:
			*color = "Yellow";
			flag = false;
			break;
		case 4:
			*color = "Black";
			flag = false;
			break;
		case 5:
			*color = "White";
			flag = false;
			break;
		default:
			cout << "Неверный ввод, повторите.\n";
			system("pause");
		}
	}
}

void Builder::choose_price() {
	*price = rand() % 25000 + 5000;
}

void Builder::choose_engine_type() {
	//Выбор типа двигателя
	int local;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "Выберите тип двигателя:\n1. Benz\n2. Diesel\n";

		while (!(cin >> local)) {
			cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
			cin.clear();
			cin.ignore(32.767, '\n');
		}

		switch (local) {
		case 1:
			*engine_type = "Benz";
			flag = false;
			break;
		case 2:
			*engine_type = "Diesel";
			flag = false;
			break;
		default:
			cout << "Неверный ввод, повторите.\n";
			system("pause");
		}
	}
}

void Builder::choose_engine_volume() {
	//Выбор объема двигателя
	int local;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "Выберите объем двигателя:\n1. 1.3\n2. 1.6\n3. 1.8\n4. 2.0\n5. 2.4\n";

		while (!(cin >> local)) {
			cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
			cin.clear();
			cin.ignore(32.767, '\n');
		}

		switch (local) {
		case 1:
			*engine_volume = 1.3;
			flag = false;
			break;
		case 2:
			*engine_volume = 1.6;
			flag = false;
			break;
		case 3:
			*engine_volume = 1.8;
			flag = false;
			break;
		case 4:
			*engine_volume = 2.0;
			flag = false;
			break;
		case 5:
			*engine_volume = 2.4;
			flag = false;
			break;
		default:
			cout << "Неверный ввод, повторите.\n";
			system("pause");
		}
	}
}

void Builder::choose_year() {
	*year = rand() % 20 + 2001;
}

/*
		Методы, принадлежащие к созданию автомобиля
*/
void Builder::choose_mark_auto() {
	//Выбор  марки
	int local;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "Выберите марку:\n1. Merc\n2. BMW\n3. Audi\n4. Mitsubishi\n5. Renault\n6. Shkoda\n";

		while (!(cin >> local)) {
			cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
			cin.clear();
			cin.ignore(32.767, '\n');
		}

		switch (local) {
		case 1:
			*mark = "Merc";
			flag = false;
			break;
		case 2:
			*mark = "BMW";
			flag = false;
			break;
		case 3:
			*mark = "Audi";
			flag = false;
			break;
		case 4:
			*mark = "Mitsubishi";
			flag = false;
			break;
		case 5:
			*mark = "Renault";
			flag = false;
			break;
		case 6:
			*mark = "Shkoda";
			flag = false;
			break;
		default:
			cout << "Неверный ввод, повторите.\n";
			system("pause");
		}
	}
}

//Доделать модели машин
void Builder::choose_model_auto() {
	//Выбор  марки
	int local;
	bool flag = true;

	if (*mark == "Merc") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "BMW") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark  == "Audi") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "Mitsubishi") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "Renault") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "Shkoda") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}
}

/*
		Методы, принадлежащие к созданию квадроцикла
*/
void Builder::choose_mark_kvadro() {
	//Выбор  марки
	int local;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "Выберите марку:\n1. MarkKvadro1\n2. MarkKvadro2\n3. MarkKvadro3\n4. MarkKvadro4\n5. MarkKvadro5\n6. MarkKvadro6\n";

		while (!(cin >> local)) {
			cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
			cin.clear();
			cin.ignore(32.767, '\n');
		}

		switch (local) {
		case 1:
			*mark = "MarkKvadro1";
			flag = false;
			break;
		case 2:
			*mark = "MarkKvadro2";
			flag = false;
			break;
		case 3:
			*mark = "MarkKvadro3";
			flag = false;
			break;
		case 4:
			*mark = "MarkKvadro4";
			flag = false;
			break;
		case 5:
			*mark = "MarkKvadro5";
			flag = false;
			break;
		case 6:
			*mark = "MarkKvadro6";
			flag = false;
			break;
		default:
			cout << "Неверный ввод, повторите.\n";
			system("pause");
		}
	}
}

void Builder::choose_model_kvadro() {
	//Выбор  марки
	int local;
	bool flag = true;

	if (*mark == "MarkKvadro1") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "MarkKvadro2") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "MarkKvadro3") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "MarkKvadro4") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "MarkKvadro5") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "MarkKvadro6") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}
}
/*
		Методы, принадлежащие к созданию мотоцикла
*/
void Builder::choose_mark_moto() {
	//Выбор  марки
	int local;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "Выберите марку:\n1. MarkMoto1\n2. MarkMoto2\n3. MarkMoto3\n4. MarkMoto4\n5. MarkMoto5\n6. MarkMoto6\n";

		while (!(cin >> local)) {
			cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
			cin.clear();
			cin.ignore(32.767, '\n');
		}

		switch (local) {
		case 1:
			*mark = "MarkMoto1";
			flag = false;
			break;
		case 2:
			*mark = "MarkMoto2";
			flag = false;
			break;
		case 3:
			*mark = "MarkMoto3";
			flag = false;
			break;
		case 4:
			*mark = "MarkMoto4";
			flag = false;
			break;
		case 5:
			*mark = "MarkMoto5";
			flag = false;
			break;
		case 6:
			*mark = "MarkMoto6";
			flag = false;
			break;
		default:
			cout << "Неверный ввод, повторите.\n";
			system("pause");
		}
	}
}

void Builder::choose_model_moto() {
	//Выбор  марки
	int local;
	bool flag = true;

	if (*mark == "MarkMoto1") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "MarkMoto2") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "MarkMoto3") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "MarkMoto4") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "MarkMoto5") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	else if (*mark == "MarkMoto6") {
		while (flag) {
			system("cls");
			cout << "Выберите модель:\n1. Модель_1\n2. Модель_2\n3. Модель_3\n";

			while (!(cin >> local)) {
				cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
				cin.clear();
				cin.ignore(32.767, '\n');
			}

			switch (local) {
			case 1:
				*model = "Модель_1";
				flag = false;
				break;
			case 2:
				*model = "Модель_2";
				flag = false;
				break;
			case 3:
				*model = "Модель_3";
				flag = false;
				break;
			default:
				cout << "Неверный ввод, повторите.\n";
				system("pause");
			}
		}
	}

	system("cls");
}

/*
		Общие методы создания транспорта
*/
void Builder::choose_mass() {
	if (*type == "Auto")
		*mass = rand() % 1500 + 1001;
	else if (*type == "Kvadro")
		*mass = rand() % 300 + 300;
	else if (*type == "Moto")
		*mass = rand() % 100 + 30;
}

void Builder::choose_min_fuel() {
	int local;

	if (*engine_type == "Diesel")
		*min_fuel = *engine_type;
	else {
		int local = rand() % 3;
		switch (local) {
		case 0:
			*min_fuel = "92";
			break;
		case 1:
			*min_fuel = "95";
			break;
		case 2:
			*min_fuel = "98";
			break;
		}
	}
}

void Builder::choose_type_of_steering() {
	//Выбор  рулевого управления
	int local;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "Выберите тип рулевого упралвения:\n1. Реечное рулевое управление\n2. Червячное рулевое управление\n3. Винтовое рулевое управление\n";

		while (!(cin >> local)) {
			cout << "Вы ввели некорректное число...Повторите ввод снова!!!\n";
			cin.clear();
			cin.ignore(32.767, '\n');
		}

		switch (local) {
		case 1:
			*type_of_steering = "Реечное(РУ)";
			flag = false;
			break;
		case 2:
			*type_of_steering = "Червячное(РУ)";
			flag = false;
			break;
		case 3:
			*type_of_steering = "Винтовое(РУ)";
			flag = false;
			break;
		default:
			cout << "Неверный ввод, повторите.\n";
			system("pause");
		}
	}
}

void Builder::choose_consuptition() {
	if (*type == "Auto")
		*consuptition = rand() % 10 + 7;
	else if (*type == "Kvadro")
		*consuptition = rand() % 6 + 2;
	else if (*type == "Moto")
		*consuptition = rand() % 4 + 2;
}

void Builder::choose_volume_trunk() {
	if (*type == "Auto")
		*volume_trunk = rand() % 201 + 200;
	else if (*type == "Kvadro")
		*volume_trunk = 0;
	else if (*type == "Moto")
		*volume_trunk = 0;
}

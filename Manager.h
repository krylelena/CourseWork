#pragma once
#include "Builder.h"

class Manager {
private:
	Builder* builder;

	fstream Auto;
	fstream Kvadro;
	fstream Moto;
public:
	Manager();						//Конструктор без параметров
	~Manager();						//Деструктор
	void create_new();				//Созданиие объекта класса Builder, т.е. Мэнеджер получает в свое распоряжение строителя
	void deleted();					//Удаление объекта класса Builder

	void create_car() {				//Создание автомобиля
		builder->create_auto(Auto);
	}
	void create_kvadro() {			//Создание квадроцикла
		builder->create_kvadro(Kvadro);
	}
	void create_moto() {			//Создание мотоцикла
		builder->create_moto(Moto);
	}

	void output_old_auto();
	void output_old_kvadro();
	void output_old_moto();
};

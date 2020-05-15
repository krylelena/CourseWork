#pragma once
#include <cstring>
#include <iostream>
#include <fstream>
#define N 20

using namespace std;

class Builder {
private:
	string* type;					//Тип транспорта
	int* wheel;						//Количество колес
	string* color;					//Цвет
	int* price;						//Цена
	string* engine_type;			//Тип двигателя
	float* engine_volume;			//Объем двигателя
	int* year;						//Год выпуска
	string* mark;					//Марка
	string* model;					//Модель
	int* mass;						//Масса
	string* min_fuel;				//Требование к топливу (минимальное)
	string* type_of_steering;		//Тип рулевого управления
	float* consuptition;			//Расход топлива
	int* volume_trunk;				//Объем багажника

	int count;						//Счетчик количества считанных ТС из файла
public:
	Builder();
	~Builder();

	void create_auto(fstream& TS);				//Создание автомобиля
	void create_kvadro(fstream& TS);			//Создание квадроцикла
	void create_moto(fstream& TS);				//Создание мотоцикла

	void output();								//Вывод информации о созданном транспорте
	void output_new(fstream& TS);				//Вывод нового ТС в файл
	void reading(fstream& TS);
	void reading_old(fstream& TS, string Type);	//Вывод старых ТС на экран

	void select(fstream& TS, string Type);		//Выбор ТС пользователем из старого набора
	/*
		Общие методы создания транспорта
	*/
	void choose_color();			//Выбор цвета
	void choose_price();			//Цена
	void choose_engine_type();		//Выбор типа двигателя
	void choose_engine_volume();	//Выбор объема двигателя
	void choose_year();				//Год создания
	/*
		Методы, принадлежащие к созданию автомобиля
	*/
	void choose_mark_auto();		//Выбор марки
	void choose_model_auto();		//Выбор модели
	/*
		Методы, принадлежащие к созданию квадроцикла
	*/
	void choose_mark_kvadro();		//Выбор марки
	void choose_model_kvadro();		//Выбор модели
	/*
		Методы, принадлежащие к созданию мотоцикла
	*/
	void choose_mark_moto();		//Выбор марки
	void choose_model_moto();		//Выбор модели
	/*
		Общие методы создания транспорта
	*/
	void choose_mass();				//Масса
	void choose_min_fuel();			//Требование к топливу
	void choose_type_of_steering();	//Выбор типа управления
	void choose_consuptition();		//Расход топлива
	void choose_volume_trunk();		//Объем багажника
};

#include "Manager.h"

Manager::Manager() {
	/*
	cout << "Constructor Manager\n";
	system("pause");
	*/

	/*Auto.open("Auto.txt", ios::app);
	if (!Auto.is_open()) {
		cout << "Файл Auto.txt не открыт\n";
		exit(1);
	}
	Kvadro.open("Kvadro.txt", ios::app);
	if (!Kvadro.is_open()) {
		cout << "Файл Auto.txt не открыт\n";
		exit(1);
	}
	Moto.open("Moto.txt", ios::app);
	if (!Moto.is_open()) {
		cout << "Файл Auto.txt не открыт\n";
		exit(1);
	}*/

	create_new();
}

Manager::~Manager() {

	cout << "Destructor Manager\n";
	system("pause");


	/*
	Auto.close();
	Kvadro.close();
	Moto.close();
	*/
	deleted();
}

void Manager::create_new(){
	this->builder = new Builder;
}

void Manager::deleted() {
	delete this->builder;
}

void Manager::output_old_auto() {
	builder->reading_old(Auto, "Auto");
	builder->select(Auto, "Auto");
}

void Manager::output_old_kvadro() {
	builder->reading_old(Kvadro, "Kvadro");
	builder->select(Kvadro, "Kvadro");
}

void Manager::output_old_moto() {
	builder->reading_old(Moto, "Moto");
	builder->select(Moto, "Moto");
}

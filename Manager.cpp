#include "Manager.h"

Manager::Manager() {
	create_new();
}

Manager::~Manager() {
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

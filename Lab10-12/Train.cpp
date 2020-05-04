#include "Train.h"
#include "Utils.h"
#include "FreightTrain.h"
#include "PassengerTrain.h"

Train::Train() {
	model = " ";
	producer_name = " ";
	nr_wagons = 0;
	nr_trains_available = 0;
	nr_trains_booked = 0;
}

Train::Train(string m, string p_n, int n_w, int n_t_a, int n_t_b) {
	model = m;
	producer_name = p_n;
	nr_wagons = n_w;
	nr_trains_available = n_t_a;
	nr_trains_booked = n_t_b;
}

Train::Train(const Train& t) {
	model = t.model;
	producer_name = t.producer_name;
	//producer_name = new char[strlen(t.producer_name) + 1];
	//strcpy_s(producer_name, strlen(t.producer_name) + 1, t.producer_name);
	nr_wagons = t.nr_wagons;
	nr_trains_available = t.nr_trains_available;
	nr_trains_booked = t.nr_trains_booked;
}

Train::~Train() {
	/*if (producer_name) {
		delete[] producer_name;
		producer_name = NULL;
	}*/
}

Train& Train::operator=(const Train& t) {
	model = t.model;
	/*if (producer_name) {
		delete[] producer_name;
		producer_name = NULL;
	}*/
	producer_name = t.producer_name;
	//producer_name = new char[strlen(t.producer_name) + 1];
	//strcpy_s(producer_name, strlen(t.producer_name) + 1, t.producer_name);
	nr_wagons = t.nr_wagons;
	nr_trains_available = t.nr_trains_available;
	nr_trains_booked = t.nr_trains_booked;
	return *this;
}

bool Train::operator==(const Train& t) {
	return (model == t.model) && (producer_name == t.producer_name) &&
		(nr_wagons == t.nr_wagons) && (nr_trains_available == t.nr_trains_available) &&
		(nr_trains_booked == t.nr_trains_booked);
}

string Train::getModel() {
	return model;
}

string Train::getProducerName() {
	return producer_name;
}

int Train::getNumberWagons() {
	return nr_wagons;
}

int Train::getNumberTrainsAvailable() {
	return nr_trains_available;
}

int Train::getNumberTrainsBooked() {
	return nr_trains_booked;
}

void Train::setModel(string m) {
	model = m;
}

void Train::setProducerName(string p_n) {
	/*if (producer_name) {
		delete[] producer_name;
		producer_name = NULL;
	}
	producer_name = new char[strlen(p_n) + 1];
	strcpy_s(producer_name, strlen(p_n) + 1, p_n);*/
	producer_name = p_n;
}

void Train::setNumberWagons(int n_w) {
	nr_wagons = n_w;
}

void Train::setNumberTrainsAvailable(int n_t_a) {
	nr_trains_available = n_t_a;
}

void Train::setNumberTrainsBooked(int n_t_b) {
	nr_trains_booked = n_t_b;
}

ostream& operator<<(ostream& os, Train& t) {
	cout << "Train: " << t.model << " " << t.producer_name
		<< " " << t.nr_wagons << " " << t.nr_trains_available << " " << t.nr_trains_booked << endl;
	return os;
}

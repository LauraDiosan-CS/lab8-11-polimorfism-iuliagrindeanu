#include "FreightTrain.h"
#include "Utils.h"

FreightTrain::FreightTrain() : Train() {
	cargo_type = "";
}

FreightTrain::FreightTrain(string m, string p_n, int n_w, string c_t, int n_t_a, int n_t_b) : Train(m, p_n, n_w, n_t_a, n_t_b) {
	cargo_type = c_t;
}

FreightTrain::FreightTrain(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	model = tokens[1];
	producer_name = tokens[2];
	nr_wagons = stoi(tokens[3]);
	cargo_type = tokens[4];
	nr_trains_available = stoi(tokens[5]);
	nr_trains_booked = stoi(tokens[6]);
}

FreightTrain::FreightTrain(const FreightTrain& ft):Train(ft) {
	//cargo_type = new char[strlen(ft.cargo_type) + 1];
	//strcpy_s(cargo_type, strlen(ft.cargo_type) + 1, ft.cargo_type);
	cargo_type = ft.cargo_type;
}

FreightTrain::~FreightTrain() {
	/*if (cargo_type) {
		delete[] cargo_type;
		cargo_type = NULL;
	}*/
}

FreightTrain& FreightTrain::operator=(const FreightTrain& ft) {
	if (this != &ft) {
		Train::operator=(ft);
		//cargo_type = new char[strlen(ft.cargo_type) + 1];
		//strcpy_s(cargo_type, strlen(ft.cargo_type) + 1, ft.cargo_type);
		cargo_type = ft.cargo_type;
	}
	return *this;
}

bool FreightTrain::operator==(const FreightTrain& ft) {
	bool eqTrain = Train::operator==(ft);
	return eqTrain && (cargo_type == ft.cargo_type);
}

string FreightTrain::getCargoType() {
	return cargo_type;
}


void FreightTrain::setCargoType(string c_t) {
	/*if (cargo_type) {
		delete[] cargo_type;
		cargo_type = NULL;
	}
	cargo_type = new char[strlen(c_t) + 1];
	strcpy_s(cargo_type, strlen(c_t) + 1, c_t);*/
	cargo_type = c_t;
}

string FreightTrain::toString() {
	return model + " " + producer_name + " " + to_string(nr_wagons) + " " + cargo_type + " " +
		to_string(nr_trains_available) + " " + to_string(nr_trains_booked);
}

string FreightTrain::toStringDelim(char delim) {
	return string("FT") + delim+ model + delim + producer_name + delim + to_string(nr_wagons) + delim + cargo_type + delim +
		to_string(nr_trains_available) + delim + to_string(nr_trains_booked);
}

ostream& operator<<(ostream& os, FreightTrain& ft) {
	os << "FreightTrain: " << ft.model << " " << ft.producer_name << " " << ft.nr_wagons << " "
		<< ft.cargo_type << " " << ft.nr_trains_available << " " << ft.nr_trains_booked << endl;
	return os;
}


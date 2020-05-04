#include "PassengerTrain.h"
#include "Utils.h"

PassengerTrain::PassengerTrain() :Train() {
	nr_seats = 0;
}

PassengerTrain::PassengerTrain(string m, string p_n, int n_w, int n_s, int n_t_a, int n_t_b) : Train(m, p_n, n_w, n_t_a, n_t_b) {
	nr_seats = n_s;
}

PassengerTrain::PassengerTrain(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	model = tokens[1];
	producer_name = tokens[2];
	nr_wagons = stoi(tokens[3]);
	nr_seats = stoi(tokens[4]);
	nr_trains_available = stoi(tokens[5]);
	nr_trains_booked = stoi(tokens[6]);
}

PassengerTrain::PassengerTrain(const PassengerTrain& pt) : Train(pt) {
	nr_seats = pt.nr_seats;
}

PassengerTrain::~PassengerTrain() {
	nr_seats = 0;
}

PassengerTrain& PassengerTrain::operator=(const PassengerTrain& pt) {
	if (this != &pt) {
		Train::operator=(pt);
		nr_seats = pt.nr_seats;
	}
	return *this;
}

bool PassengerTrain::operator==(const PassengerTrain& pt) {
	bool eqTrain=Train::operator==(pt);
	return eqTrain && (nr_seats == pt.nr_seats);
}

int PassengerTrain::getNumberSeats() {
	return nr_seats;
}

int PassengerTrain::getNumberTrainsAvailable() {
	return nr_trains_available;
}

void PassengerTrain::setNumberSeats(int n_s) {
	nr_seats = n_s;
}

string PassengerTrain::toString() {
	return model + " " + producer_name + " " + to_string(nr_wagons) + " " + to_string(nr_seats)
		+ " " + to_string(nr_trains_available) + " " + to_string(nr_trains_booked);
}

string PassengerTrain::toStringDelim(char delim) {
	return string("PT") + delim + model + delim + producer_name + delim + to_string(nr_wagons) + delim + to_string(nr_seats)
		+ delim + to_string(nr_trains_available) + delim + to_string(nr_trains_booked);
}

ostream& operator<<(ostream& os, PassengerTrain& pt) {
	os << "PassengerTrain: " << pt.model << " " << pt.producer_name << " " << pt.nr_wagons << " "
		<< pt.nr_seats << " " << pt.nr_trains_available << " " << pt.nr_trains_booked << endl;
	return os;
}
#pragma once
#include "Train.h"

class PassengerTrain : public Train {
private:
	int nr_seats;
public:
	PassengerTrain();
	PassengerTrain(string m, string p_n, int n_w, int n_s, int n_t_a, int n_t_b);
	PassengerTrain(string, char);
	PassengerTrain(const PassengerTrain& pt);
	~PassengerTrain();
	PassengerTrain& operator=(const PassengerTrain& pt);
	bool operator==(const PassengerTrain& pt);
	int getNumberSeats();
	int getNumberTrainsAvailable();
	void setNumberSeats(int n_s);
	string toString();
	string toStringDelim(char delim);
	friend ostream& operator<<(ostream&, PassengerTrain& pt);
};
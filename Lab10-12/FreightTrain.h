#pragma once
#include <iostream>
#include "Train.h"
using namespace std;

class FreightTrain: public Train {
private:
	
	string cargo_type;
	
public:
	FreightTrain();
	FreightTrain(string m, string p_n, int n_w, string c_t, int n_t_a, int n_t_b);
	FreightTrain(string, char);
	FreightTrain(const FreightTrain& ft);
	~FreightTrain();
	FreightTrain& operator=(const FreightTrain& ft);
	bool operator==(const FreightTrain& ft);
	string getCargoType();
	void setCargoType(string c_t);
	string toString();
	string toStringDelim(char delim);
	friend ostream& operator<<(ostream&, FreightTrain& ft);
};
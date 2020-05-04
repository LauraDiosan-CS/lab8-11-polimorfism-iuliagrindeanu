#pragma once
#include <iostream>
#include <string>
using namespace std;

class Train {
protected:
	string model;
	string producer_name;
	int nr_wagons;
	int nr_trains_available;
	int nr_trains_booked;
public:
	Train();
	Train(string m, string p_n, int n_w, int n_t_a, int n_t_b);
	Train(const Train& t);
	Train(string line, char delim);
	virtual ~Train();
	virtual Train& operator=(const Train& t);
	virtual bool operator==(const Train& t);
	string getModel();
	string getProducerName();
	int getNumberWagons();
	int getNumberTrainsAvailable();
	int getNumberTrainsBooked();
	void setModel(string m);
	void setProducerName(string p_n);
	void setNumberWagons(int n_w);
	void setNumberTrainsAvailable(int n_t_a);
	void setNumberTrainsBooked(int n_t_b);
	//virtual string toString() ;
	virtual string toStringDelim(char delim) {
		return string(" ");
	};
	friend ostream& operator<<(ostream& os, Train& t);
};
#pragma once
#include "IRepository.h"
#include "FreightTrain.h"
#include "PassengerTrain.h"
#include "RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"

class Service {
private:
	char delim;
	RepositoryFile<Train>* repoTrain;
public:
	Service();
	Service(RepositoryFile<Train>*);
	~Service();
	void addTrain(Train* ft);
	int find(Train* t);
	void update(Train* old, Train* newTrain);
	int remove(Train* t);
	char getDelim() { return delim; };
	void setDelim(char d) {delim = d;};
	//void addPassengerTrain(PassengerTrain& pt);
	void load_from_file(string filename);
	void save_to_file(string filename);
	vector<Train*> getAll();
};
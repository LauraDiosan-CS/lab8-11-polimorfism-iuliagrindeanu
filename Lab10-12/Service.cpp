#include "Service.h"

Service::Service() {
	repoTrain = NULL;
}

Service::Service(RepositoryFile<Train>* repo) {
	repoTrain = repo;
}

Service::~Service() {

}

void Service::addTrain(Train* ft) {
	repoTrain->add(ft);
}

void Service::load_from_file(string filename) {
	int len = (int)filename.length();
	string ext = filename.substr(len - 3, 3);
	if (ext == string("txt")) {
		delim = ' ';
		repoTrain = new RepositoryFileTXT<Train>(filename.c_str());
	}
	else 
		if(ext == string("csv")) {
			delim = ',';
			repoTrain = new RepositoryFileCSV<Train>(filename.c_str());
		}
	repoTrain->loadFromFile();

}

vector<Train*> Service::getAll() {
	return repoTrain->getAll();
}

void Service::save_to_file(string filename) {
	RepositoryFile<Train>* newRepoTrain=NULL;
	int len = (int)filename.length();
	string ext = filename.substr(len - 3, 3);
	if (ext == string("txt")) {
		delim = ' ';
		newRepoTrain = new RepositoryFileTXT<Train>(filename.c_str());
	}
	else
		if (ext == string("csv")) {
			delim = ',';
			newRepoTrain = new RepositoryFileCSV<Train>(filename.c_str());
		}
	newRepoTrain->saveToFile(repoTrain);
	delete repoTrain;
	repoTrain = newRepoTrain;
}

int Service::find(Train* t) {
	return repoTrain->find(t);
}

void Service::update(Train* old, Train* newTrain) {
	repoTrain->update(old, newTrain);
}

int Service::remove(Train* t) {
	return repoTrain->remove(t);
}

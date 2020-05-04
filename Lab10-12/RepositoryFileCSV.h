#pragma once
#include "RepositoryFile.h"
#include <fstream>
using namespace std;

template  <class T> class RepositoryFileCSV :
	public RepositoryFile<T>
{
public:
	RepositoryFileCSV();
	RepositoryFileCSV(const char*);
	void loadFromFile();
	void saveToFile(RepositoryFile<T>* repo);
	~RepositoryFileCSV();
};
template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV()
{
}

template<class T>
inline RepositoryFileCSV<T>::RepositoryFileCSV(const char* fName) :RepositoryFile<T>(fName)
{
}

template<class T>
void RepositoryFileCSV<T>::loadFromFile()
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line)) {
		T* tren = NULL;
		if (line[0] == 'F') {
			tren = new FreightTrain(line, ',');
		}
		else 
			if (line[0] == 'P') {
				tren = new PassengerTrain(line, ',');
			}
		IRepository<T>::elem.push_back(tren);
		
	}
	MySort();

}

template<class T>
inline void RepositoryFileCSV<T>::saveToFile(RepositoryFile<T>* repo)
{
	ofstream f(RepositoryFile<T>::fileName);
	for (T* crt : repo->getAll()) {
		//f << crt << endl;
		f << crt->toStringDelim(',') << endl;
	}
}

template<class T>
RepositoryFileCSV<T>::~RepositoryFileCSV()
{
}



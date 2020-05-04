#pragma once
#include "RepositoryFile.h"
#include <fstream>
using namespace std;

template <class T> class RepositoryFileTXT :public RepositoryFile<T>
{
public:
	RepositoryFileTXT();
	RepositoryFileTXT(const char*);
	void loadFromFile();
	void saveToFile(RepositoryFile<T>* repo);
	~RepositoryFileTXT();
};

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT()
{
}

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT(const char* fName) :RepositoryFile<T>(fName)
{
}

template<class T>
inline void RepositoryFileTXT<T>::loadFromFile()
{
	string line;
	ifstream f(RepositoryFile<T>::fileName);
	while (getline(f, line)) {
		T* tren = NULL;
		if (line[0] == string("F")[0]) {
			tren = new FreightTrain(line, ' ');
		}
		else
			if (line[0] == string("P")[0]) {
				tren = new PassengerTrain(line, ' ');
			}
		IRepository<T>::elem.push_back(tren);
	}
		
}


template<class T>
inline void RepositoryFileTXT<T>::saveToFile(RepositoryFile<T>* repo)
{
	ofstream f(RepositoryFile<T>::fileName);
	for (T* crt : repo->getAll()) {
		//f << crt << endl;
		f << crt->toStringDelim(' ') << endl;
	}
}

template<class T>
inline RepositoryFileTXT<T>::~RepositoryFileTXT()
{
}


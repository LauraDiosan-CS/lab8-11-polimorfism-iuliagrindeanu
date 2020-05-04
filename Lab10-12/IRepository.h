#pragma once
#include <vector>
#include <algorithm>
#include "FreightTrain.h"
#include "PassengerTrain.h"
using namespace std;

template <class T> class IRepository {
protected:
	vector<T*> elem;
public:
	IRepository();
	~IRepository();
	void add(T*);
	int find(T*);
	void update(T*, T*);
	int remove(T*);
	int size();
	void MySort();
	vector<T*> getAll();
	T* get(int index);
};

template<class T>
inline IRepository<T>::IRepository()
{
}

template<class T>
inline void IRepository<T>::MySort() {
	std::sort(elem.begin(), elem.end(), compareTrains<T>);
}

template<class T>
inline IRepository<T>::~IRepository()
{
	for (auto e : elem)
		delete e;
}
template<class T>
inline bool compareTrains(T* a, T* b) {
	return a->getModel() < b->getModel();
	}
/*template<class T>
struct {
	bool operator()(T* a, T* b) const
	{
		return a->model < b->model;
	}
} customLess<T>;*/

template<class T>
inline void IRepository<T>::add(T* e)
{
	elem.push_back(e);
	std::sort(elem.begin(), elem.end(), compareTrains<T>);
}

template<class T>
inline int IRepository<T>::find(T* e)
{
	int index = -1;
	for (int i = 0; i < elem.size(); i++) {
		if (*e == *(elem[i])) {
			index = i;
			break;
		}
	}
	//auto it = std::find(elem.begin(), elem.end(), e);
	//if (it != elem.end()) return distance(elem.begin(), it);
	return index;
}

template<class T>
inline void IRepository<T>::update(T* vechi, T* nou){
	//int index = -1;
	for (int i = 0; i < elem.size(); i++) {
		if (*vechi == *(elem[i])) {
			delete elem[i];
			*(elem[i]) = *nou;
			//index = i;
			break;
		}
	}
	//std::replace(elem.begin(), elem.end(), vechi, nou);
}

template<class T>
inline int IRepository<T>::remove(T* e)
{
	/*for (int i = 0; i < elem.size(); i++) {
		if (*e == *(elem[i])) {
			elem.erase(i, *(elem[i]));
			return 0;
		}
	}
	return -1;*/
	auto last = std::find(elem.begin(), elem.end(), e);
	if (last != elem.end()) {
		elem.erase(last, elem.end());
		return 0;
	}
	return -1;
}

template<class T>
inline int IRepository<T>::size()
{
	return elem.size();
}

template<class T>
inline vector<T*> IRepository<T>::getAll()
{
	return elem;
}

template<class T>
inline T* IRepository<T>::get(int index) {
	return elem[index];
}


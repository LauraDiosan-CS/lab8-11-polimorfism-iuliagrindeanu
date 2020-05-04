#pragma once
#include "Service.h"
class UI {
private:
	Service s;
public:
	UI();
	~UI();
	void showUI();
	void load_from_file();
	void save_to_file();
	void add();
	void find();
	void update();
	void remove();
	void showAll();
};

#include "UI.h"

UI::UI() {

}

UI::~UI() {

}

void UI::load_from_file() {
	cout << "Introduceti numele fisierului: ";
	string filename;
	cin >> filename;
	
	s.load_from_file(filename);
	
}

void UI::showAll() {
	vector<Train*> all = s.getAll();
	for (Train* t : all) {
		//Train* tb = t;
		cout << t->toStringDelim(s.getDelim()) << endl;
	}
}

void UI::save_to_file() {
	cout << "Introduceti numele fisierului in care doriti sa salvati: ";
	string filename;
	cin >> filename;

	s.save_to_file(filename);
}

void UI::add() {
	cout << "Introduceti tipul trenului (PT passenger, FT freight): ";
	string tip;
	cin >> tip;
	cout << "Model: ";
	string model;
	cin >> model;
	cout << "Producator: ";
	string producer;
	cin >> producer;
	cout << "Nr vagoane: ";
	int nr_w;
	cin >> nr_w;
	cout << "Nr trenuri disponibile: ";
	int nr_a;
	cin >> nr_a;
	cout << "Nr trenuri rezervate: ";
	int nr_b;
	cin >> nr_b;
	if (tip == string("FT")) {
		cout << "Introduceti incarcatura: ";
		string c_t;
		cin >> c_t;
		Train* ft = new FreightTrain(model, producer, nr_w, c_t, nr_a, nr_b);
		s.addTrain(ft);
	}
	else
		if (tip == string("PT")) {
			cout << "Introduceti nr de locuri: ";
			int nr_s;
			cin >> nr_s;
			Train* pt = new PassengerTrain(model, producer, nr_w, nr_s, nr_a, nr_b);
			s.addTrain(pt);
		}
}

void UI::find() {
	cout << "Introduceti tipul trenului (PT passenger, FT freight): ";
	string tip;
	cin >> tip;
	cout << "Model: ";
	string model;
	cin >> model;
	cout << "Producator: ";
	string producer;
	cin >> producer;
	cout << "Nr vagoane: ";
	int nr_w;
	cin >> nr_w;
	cout << "Nr trenuri disponibile: ";
	int nr_a;
	cin >> nr_a;
	cout << "Nr trenuri rezervate: ";
	int nr_b;
	cin >> nr_b;
	int index = -1;
	//int nr_a = 0;
	//int nr_b = 0;
	if (tip == string("FT")) {
		cout << "Introduceti incarcatura: ";
		string c_t;
		cin >> c_t;
		Train* ft = new FreightTrain(model, producer, nr_w, c_t, nr_a, nr_b);
		index = s.find(ft);
	}
	else
		if (tip == string("PT")) {
			cout << "Introduceti nr de locuri: ";
			int nr_s;
			cin >> nr_s;
			Train* pt = new PassengerTrain(model, producer, nr_w, nr_s, nr_a, nr_b);
			index = s.find(pt);
		}
	if (index >= 0) {
		cout << "Am gasit trenul la index: " <<index<< endl;
	}
	else
		cout << "Nu l-am gasit!" << endl;
}

void UI::update() {
	Train* t = NULL;
	cout << "Introduceti tipul trenului (PT passenger, FT freight): ";
	string tip;
	cin >> tip;
	cout << "Model: ";
	string model;
	cin >> model;
	cout << "Producator: ";
	string producer;
	cin >> producer;
	cout << "Nr vagoane: ";
	int nr_w;
	cin >> nr_w;
	cout << "Nr trenuri disponibile: ";
	int nr_a;
	cin >> nr_a;
	cout << "Nr trenuri rezervate: ";
	int nr_b;
	cin >> nr_b;
	int index = -1;
	//int nr_a = 0;
	//int nr_b = 0;
	if (tip == string("FT")) {
		cout << "Introduceti incarcatura: ";
		string c_t;
		cin >> c_t;
		t = new FreightTrain(model, producer, nr_w, c_t, nr_a, nr_b);
	}
	else
		if (tip == string("PT")) {
			cout << "Introduceti nr de locuri: ";
			int nr_s;
			cin >> nr_s;
			t = new PassengerTrain(model, producer, nr_w, nr_s, nr_a, nr_b);
		}
	index = s.find(t);
	if (index >= 0) {
		cout << "Am gasit trenul la index: " << index << endl;
		cout << "Introduceti noul tren: " << endl;
		cout << "Introduceti tipul trenului (PT passenger, FT freight): ";
		string tip2;
		cin >> tip2;
		cout << "Model: ";
		string model2;
		cin >> model2;
		cout << "Producator: ";
		string producer2;
		cin >> producer2;
		cout << "Nr vagoane: ";
		int nr_w2;
		cin >> nr_w2;
		cout << "Nr trenuri disponibile: ";
		int nr_a2;
		cin >> nr_a2;
		cout << "Nr trenuri rezervate: ";
		int nr_b2;
		cin >> nr_b2;
		if (tip == string("FT")) {
			cout << "Introduceti incarcatura: ";
			string c_t2;
			cin >> c_t2;
			Train* ft2 = new FreightTrain(model2, producer2, nr_w2, c_t2, nr_a2, nr_b2);
			s.update(t, ft2);
		}
		else
			if (tip == string("PT")) {
				cout << "Introduceti nr de locuri: ";
				int nr_s2;
				cin >> nr_s2;
				Train* pt2 = new PassengerTrain(model2, producer2, nr_w2, nr_s2, nr_a2, nr_b2);
				s.update(t, pt2);
			}

	}
	else
		cout << "Nu l-am gasit!" << endl;

}

void UI::remove() {
	Train* t = NULL;
	cout << "Introduceti tipul trenului (PT passenger, FT freight): ";
	string tip;
	cin >> tip;
	cout << "Model: ";
	string model;
	cin >> model;
	cout << "Producator: ";
	string producer;
	cin >> producer;
	cout << "Nr vagoane: ";
	int nr_w;
	cin >> nr_w;
	cout << "Nr trenuri disponibile: ";
	int nr_a;
	cin >> nr_a;
	cout << "Nr trenuri rezervate: ";
	int nr_b;
	cin >> nr_b;
	if (tip == string("FT")) {
		cout << "Introduceti incarcatura: ";
		string c_t;
		cin >> c_t;
		t = new FreightTrain(model, producer, nr_w, c_t, nr_a, nr_b);
	}
	else
		if (tip == string("PT")) {
			cout << "Introduceti nr de locuri: ";
			int nr_s;
			cin >> nr_s;
			t = new PassengerTrain(model, producer, nr_w, nr_s, nr_a, nr_b);
		}
	s.remove(t);
}


void UI::showUI()
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Load from file." << endl;
		cout << "	2. Show all." << endl;
		cout << "	3. Save to file." << endl;
		cout << "	4. Add." << endl;
		cout << "	5. Find." << endl;
		cout << "	6. Update." << endl;
		cout << "	7. Delete." << endl;
		cout << "Introduceti optiunea (prin numarul ei): ";
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {load_from_file(); break; }
		case 2: {showAll(); break; }
		case 3: {save_to_file(); break; }
		case 4: {add(); break; }
		case 5: {find(); break; }
		case 6: {update(); break; }
		case 7: {remove(); break; }
		case 0: {gata = true; cout << "Bye Bye!" << endl; }
		}
	}
}
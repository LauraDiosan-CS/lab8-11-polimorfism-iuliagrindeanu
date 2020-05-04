#include "Test.h"

void testTrain() {
	Train t1("SteamTrain", "ProducerName1", 5, 10, 7);
	assert(t1.getNumberWagons() == 5);
	assert(t1.getModel() == "SteamTrain");
	//assert(strcmp(t1.getProducerName(), "ProducerName1") == 0);
	Train t2;
	t2 = t1;
	t2.setNumberTrainsAvailable(9);
	assert(t2.getNumberTrainsAvailable() == 9);
}

void testFreightTrain() {
	FreightTrain ft1("SteamTrain", "ProducerName1", 5, "cereals", 20, 10);
	assert(ft1.getNumberWagons() == 5);
	assert(ft1.getModel() == "SteamTrain");
	//assert(strcmp(ft1.getProducerName(), "ProducerName1") == 0);
	//assert(strcmp(ft1.getCargoType(), "cereals") == 0);
	//assert(strcmp(ft1.getCargoType(), "condiments") == -1);
	FreightTrain ft2;
	ft2 = ft1;
	assert(ft2 == ft1);
}

void testPassengerTrain() {
	PassengerTrain pt1("SteamTrain", "ProducerName1", 5, 50, 20, 10);
	assert(pt1.getNumberWagons() == 5);
	assert(pt1.getModel() == "SteamTrain");
	//assert(strcmp(pt1.getProducerName(), "ProducerName1") == 0);
	assert(pt1.getNumberSeats() == 50);
	PassengerTrain pt2;
	pt2 = pt1;
	assert(pt2 == pt1);
}

void testLoadFromFileTXT() {
	const char* fileNameTrains = "Trains.txt";
	RepositoryFile<Train>* repoTrains = new RepositoryFileTXT<Train>(fileNameTrains);
	((RepositoryFileTXT<Train>*)repoTrains)->loadFromFile();
	assert(repoTrains->size() == 4);

}

void testAdd() {
	const char* fileNameTrains = "Trains.txt";
	RepositoryFile<Train>* repoTrains = new RepositoryFileTXT<Train>(fileNameTrains);
	((RepositoryFileTXT<Train>*)repoTrains)->loadFromFile();
	assert(repoTrains->size() == 4);
	Train* t1 = new PassengerTrain("Diesel", "Bombardier", 7, 200, 30, 5);
	repoTrains->add(t1);
	assert(repoTrains->size() == 5);
	Train* t2 = new FreightTrain("Diesel", "Bombardier", 7, "cereale", 30, 5);
	repoTrains->add(t2);
	assert(repoTrains->size() == 6);
}

void testFind() {
	const char* fileNameTrains = "Trains.csv";
	RepositoryFile<Train>* repoTrains = new RepositoryFileCSV<Train>(fileNameTrains);
	((RepositoryFileCSV<Train>*)repoTrains)->loadFromFile();
	assert(repoTrains->size() == 4);
	Train* t1 = new PassengerTrain("Diesel", "Bombardier", 7, 200, 30, 5);
	repoTrains->add(t1);
	int index = repoTrains->find(t1);
	assert(index == 4);
}

void testUpdate() {
	const char* fileNameTrains = "Trains.csv";
	RepositoryFile<Train>* repoTrains = new RepositoryFileCSV<Train>(fileNameTrains);
	((RepositoryFileCSV<Train>*)repoTrains)->loadFromFile();
	assert(repoTrains->size() == 4);
	Train* t1 = new PassengerTrain("Diesel", "Bombardier", 7, 200, 30, 5);
	repoTrains->add(t1);
	Train* t2 = new FreightTrain("Diesel", "Bombardier", 7, "cereale", 30, 5);
	repoTrains->update(t1, t2);
	int index = repoTrains->find(t2);
	//assert(index == 4);
}

void testSaveToFile() {
	const char* fileNameTrains = "Trains.csv";
	RepositoryFile<Train>* repoTrains = new RepositoryFileCSV<Train>(fileNameTrains);
	((RepositoryFileCSV<Train>*)repoTrains)->loadFromFile();
	const char* fileNameTrains2 = "Trains2.csv";
	RepositoryFile<Train>* repoTrains2 = new RepositoryFileCSV<Train>(fileNameTrains2);
	((RepositoryFileCSV<Train>*)repoTrains2)->saveToFile(repoTrains);
	((RepositoryFileCSV<Train>*)repoTrains2)->loadFromFile();
	assert(repoTrains2->size() == 4);
}

void testLive1() {
	const char* fileNameTrains = "fisier-111-1.csv";
	RepositoryFile<Train>* repoTrains = new RepositoryFileCSV<Train>(fileNameTrains);
	((RepositoryFileCSV<Train>*)repoTrains)->loadFromFile();
	Train* t1 = new FreightTrain("KBT8", "Fleishmann", 8, "carbuni", 10, 20);
	Train* t2 = new PassengerTrain("A0JK", "Neumann", 10, 200, 4, 30);
	Train* t3 = new FreightTrain("B1xC", "Aron", 11, "benzina", 9, 12);
	Train* t4 = new PassengerTrain("DIJ9", "Stora", 9, 150, 5, 28);

	assert(repoTrains->size() == 2);

	assert(*(repoTrains->get(0)) == *t2);
	assert(*(repoTrains->get(1)) == *t1);
	repoTrains->add(t3);
	assert(repoTrains->size() == 3);
	assert(*(repoTrains->get(0)) == *t2);
	assert(*(repoTrains->get(1)) == *t3);
	assert(*(repoTrains->get(2)) == *t1);
	repoTrains->add(t4);
	assert(repoTrains->size() == 4);
	assert(*(repoTrains->get(0)) == *t2);
	assert(*(repoTrains->get(1)) == *t3);
	assert(*(repoTrains->get(2)) == *t4);
	assert(*(repoTrains->get(3)) == *t1);


}
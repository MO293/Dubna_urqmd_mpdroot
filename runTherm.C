#include <iostream>
#include <fstream>
#include <string>

class Generator {
	unsigned numberOfEvents;
	bool randomize;
	string tableType;
	string inputDirShare;
	string eventOutputFile;
	string freezeOutModel;
	string inputFile;
	float bwvt;
	float bwa;
	float tau;
	float rhoMax;
	float temperature;
	float miuI;
	float miuS;
	float miuB;
	float alphaRange;
	float rapidityRange;
	unsigned numberOfIntegrateSamples;

public:
	Generator() :
	numberOfEvents(1),
	randomize(1), 
	tableType("SHARE"), 
	inputDirShare("./share"),
	eventOutputFile("event.out"),
	freezeOutModel("SingleFreezeOut"),
	inputFile("therminator.in"),
	bwvt(0.55),
	bwa(-0.5),
	tau(9.74),
	rhoMax(7.74),
	temperature(0.1501),
	miuI(-0.0079697),
	miuS(0.0699562),
	miuB(0.3032),
	alphaRange(8.0),
	rapidityRange(4.0),
	numberOfIntegrateSamples(1000000) 
	{}

	void setNumberOfEvents(unsigned numberOfEvents) { this->numberOfEvents = numberOfEvents; }
	unsigned getNumberOfEvents() { return this->numberOfEvents; }

	void setRandomize(bool randomize) { this->randomize = randomize; }
	bool getRandomize() { return this->randomize; }

	void setTableType(string tableType) { this->tableType = tableType; }
	string getTableType() { return this->tableType; }

	void setInputDirShare(string inputDirShare) { this->inputDirShare = inputDirShare; }
	string getInputDirShare() { return this->inputDirShare; }

	void setEventOutputFile(string eventOutputFile) { this->eventOutputFile = eventOutputFile; }
	string getEventOutputFile() { return this->eventOutputFile; }

	void setFreezeOutModel(string freezeOutModel) { this->freezeOutModel = freezeOutModel; }
	string getFreezeOutModel() { return this->freezeOutModel; }

	void setBwvt(float bwvt) { this->bwvt = bwvt; }
	float getBwvt() { return this->bwvt; }

	void setBwa(float bwa) { this->bwa = bwa; }
	float getBwa() { return this->bwa; }

	void setTau(float tau) { this->tau = tau; }
	float getTau() { return this->tau; }

	void setRhoMax(float rhoMax) { this->rhoMax = rhoMax; }
	float getRhoMax() { return this->rhoMax; }

	void setTemperature(float temperature) { this->temperature = temperature; }
	float getTemperature() { return this->temperature; }

	void setMiuI(float miuI) { this->miuI = miuI; }
	float getMiuI() { return this->miuI; }

	void setMiuS(float miuS) { this->miuS = miuS; }
	float getMiuS() { return this->miuS; }

	void setMiuB(float miuB) { this->miuB = miuB; }
	float getMiuB() { return this->miuB; }

	void setAlphaRange(float alphaRange) { this->alphaRange = alphaRange; }
	float getAlphaRange() { return this->alphaRange; }

	void setRapidityRange(float rapidityRange) { this->rapidityRange = rapidityRange; }
	float getRapidityRange() { return this->rapidityRange; }

	void setNumberOfIntegrateSamples(unsigned numberOfIntegrateSamples) { this->numberOfIntegrateSamples = numberOfIntegrateSamples; }
	unsigned getNumberOfIntegrateSamples() { return this->numberOfIntegrateSamples; }

	void generateInputFile() {
		std::fstream inputFile;
		try {
			inputFile.open(this->inputFile, std::fstream::out | std::fstream::trunc);
			inputFile << "NumberOfEvents = " << getNumberOfEvents() << endl;
			inputFile << "Randomize = " << getRandomize() << endl;
			inputFile << "TableType = " << getTableType() << endl;
			inputFile << "InputDirSHARE = " << getInputDirShare() << endl;
			inputFile << "EventOutputFile = " << getEventOutputFile() << endl;
			inputFile << "FreezeOutModel = " << getFreezeOutModel() << endl;
			inputFile << "BWVt = " << getBwvt() << endl;
			inputFile << "BWA = " << getBwa() << endl;
			inputFile << "Tau = " << getTau() << endl;
			inputFile << "RhoMax = " << getRhoMax() << endl;
			inputFile << "Temperature = " << getTemperature() << endl;
			inputFile << "MiuI = " << getMiuI() << endl;
			inputFile << "MiuS = " << getMiuS() << endl;
			inputFile << "MiuB = " << getMiuB() << endl;
			inputFile << "AlphaRange = " << getAlphaRange() << endl;
			inputFile << "RapidityRange = " << getRapidityRange() << endl;
			inputFile << "NumberOfIntegrateSamples = " << getNumberOfIntegrateSamples() << endl;
			inputFile.close();
		} catch(const ifstream::failure& e) {
			cout << "Exception occured while working with file." << endl;
		}
	}

	void generateEvents() {
		system("$VMCWORKDIR/macro/mpd/therminator/therm_events");
	}

	void runMC() {
		system("root -b -q $VMCWORKDIR/macro/mpd/runMC.C");
	}

	void reco() {
		system("root -b -q $VMCWORKDIR/macro/mpd/reco.C");
	}

	void run() {
		runMC();
		reco();
	}


};

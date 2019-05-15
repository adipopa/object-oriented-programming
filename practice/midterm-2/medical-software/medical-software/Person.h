#pragma once

#include "BMI.h"
#include "BP.H"
#include <vector>
#include <algorithm>
#include <fstream>

class Person {

private:
	std::string name;
	std::vector<MedicalAnalysis*> medicalAnalyses;

public:
	Person(std::string name);

	void addAnalysis(MedicalAnalysis* medicalAnalysis);
	std::vector<MedicalAnalysis*> getAllAnalyses();
	std::vector<MedicalAnalysis*> getAnalysesByMonth(int month);
	bool isIll(int month);
	std::vector<MedicalAnalysis*> getAnalysesBetweenDates(std::string date1, std::string date2);
	void writeToFile(std::string filename, std::string date1, std::string date2);

	~Person();
};


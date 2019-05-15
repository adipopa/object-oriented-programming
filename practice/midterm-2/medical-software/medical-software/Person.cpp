#include "Person.h"

Person::Person(std::string name) : name{ name } {}

void Person::addAnalysis(MedicalAnalysis* medicalAnalysis) {
	this->medicalAnalyses.push_back(medicalAnalysis);
}

std::vector<MedicalAnalysis*> Person::getAllAnalyses() {
	return this->medicalAnalyses;
}

std::vector<MedicalAnalysis*> Person::getAnalysesByMonth(int month) {
	std::vector<MedicalAnalysis*> analysesByMonth;
	auto analysesFilterFunction = [month](MedicalAnalysis* medicalAnalysis) -> bool {
		return std::stoi(medicalAnalysis->getDate().substr(5, 2)) == month;
	};
	std::copy_if(this->medicalAnalyses.begin(), this->medicalAnalyses.end(), std::back_inserter(analysesByMonth), analysesFilterFunction);
	return analysesByMonth;
}

bool Person::isIll(int month) {
	std::vector<MedicalAnalysis*> analysesByMonth = this->getAnalysesByMonth(month);
	if (analysesByMonth.size() == 0) {
		throw std::runtime_error("You have zero analyses this month.");
	}
	for (auto medicalAnalysis : analysesByMonth) {
		if (medicalAnalysis->isResultOK()) {
			return false;
		}
	}
	return true;
}

std::vector<MedicalAnalysis*> Person::getAnalysesBetweenDates(std::string date1, std::string date2) {
	std::vector<MedicalAnalysis*> analysesBetweenDates;
	auto analysesFilterFunction = [date1, date2](MedicalAnalysis* medicalAnalysis) -> bool {
		return medicalAnalysis->getDate() >= date1 && medicalAnalysis->getDate() <= date2;
	};
	std::copy_if(this->medicalAnalyses.begin(), this->medicalAnalyses.end(), std::back_inserter(analysesBetweenDates), analysesFilterFunction);
	return analysesBetweenDates;
}

void Person::writeToFile(std::string filename, std::string date1, std::string date2) {
	std::vector<MedicalAnalysis*> analysesBetweenDates = this->getAnalysesBetweenDates(date1, date2);

	if (filename.empty()) {
		return;
	}

	std::ofstream outputStream(filename);

	for (auto medicalAnalysis : analysesBetweenDates) {
		outputStream << medicalAnalysis->toString();
	}

	outputStream.close();
}

Person::~Person() {
	for (auto medicalAnalysis : this->medicalAnalyses) {
		delete medicalAnalysis;
	}
}

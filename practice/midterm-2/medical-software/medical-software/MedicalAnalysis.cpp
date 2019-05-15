#include "MedicalAnalysis.h"

MedicalAnalysis::MedicalAnalysis(std::string date) : date{ date } {}

bool MedicalAnalysis::isResultOK() {
	return false;
}

std::string MedicalAnalysis::toString() {
	return "Date: " + this->date + "\n";
}

std::string MedicalAnalysis::getDate() {
	return this->date;
}

MedicalAnalysis::~MedicalAnalysis() {}

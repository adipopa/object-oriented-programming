#include "BP.h"

BP::BP(std::string date, int systolicValue, int diastolicValue) : MedicalAnalysis{ date }, systolicValue { systolicValue }, diastolicValue{ diastolicValue } {}

bool BP::isResultOK() {
	return this->systolicValue >= 90 && this->systolicValue <= 119 && this->diastolicValue >= 60 && this->diastolicValue <= 79;
}

std::string BP::toString() {
	return "Date: " + this->date + ", Systolic value: " + std::to_string(this->systolicValue) +
		", diastolic value: " + std::to_string(this->diastolicValue) + " - " + (this->isResultOK() ? "OK" : "Not OK") + "\n";
}

BP::~BP() {}

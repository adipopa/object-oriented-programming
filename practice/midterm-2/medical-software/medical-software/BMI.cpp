#include "BMI.h"

BMI::BMI(std::string date, double value) : MedicalAnalysis{ date }, value { value } {}

bool BMI::isResultOK() {
	return this->value >= 18.5 && this->value <= 25;
}

std::string BMI::toString() {
	return "Date: " + this->date + ", BMI: " + std::to_string(this->value) + " - " + (this->isResultOK() ? "OK" : "Not OK") + "\n";
}

BMI::~BMI() {}

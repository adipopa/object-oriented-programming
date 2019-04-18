#pragma once

#include <string>

class Team {

private:
	std::string name;
	std::string country;
	int currentScore;

public:
	Team(const std::string& name, const std::string& country) : name{ name }, country{ country }, currentScore{ 0 } {};

	std::string getName() const { return this->name; };
	std::string getCountry() const { return this->country; };
	int getCurrentScore() const { return this->currentScore; };

	void setCurrentScore(const int currentScore) { this->currentScore = currentScore; };

	~Team() {};
};


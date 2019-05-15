#pragma once

class Drone {
	
private:
	int droneXPosition, droneYPosition;

public:
	Drone() : droneXPosition{ 0 }, droneYPosition{ 0 } {}

	Drone(const int& droneXPosition, const int& droneYPosition) :droneXPosition{ droneXPosition }, droneYPosition{ droneYPosition } {}

	int getXPosition() const { return droneXPosition; };
	int getYPosition() const { return droneYPosition; };

	void setXPosition(const int& droneXPosition) { this->droneXPosition = droneXPosition; }
	void setYPosition(const int& droneYPosition) { this->droneYPosition = droneYPosition; }

	~Drone() {}
};


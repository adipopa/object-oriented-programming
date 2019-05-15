#pragma once

class Tile {

private:
	int tileXPosition, tileYPosition;

public:
	Tile() : tileXPosition{ 0 }, tileYPosition{ 0 } {}

	Tile(const int& tileXPosition, const int& tileYPosition) :tileXPosition{ tileXPosition }, tileYPosition{ tileYPosition } {}

	int getXPosition() const { return tileXPosition; };
	int getYPosition() const { return tileYPosition; };

	~Tile() {}
};
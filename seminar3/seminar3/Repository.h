#pragma once
#include "Song.h"
#include "DynamicVector.h"
#include <vector>

class Repository
{
private:
	std::vector<Song> songs;

public:
	/*
		Default constructor.
	*/
	Repository() {}

	/*
		Adds a song to the repository.
		Input: s - Song.
		Output: the song is added to the repository.
	*/
	void addSong(const Song& s);

	/*
		Finds a song, by artist and title.
		Input: artist, title - string
		Output: the song that was found, or an "empty" song (all fields empty and duration 0), if nothing was found.
	*/
	Song findByArtistAndTitle(const std::string& artist, const std::string& title);

	std::vector<Song> getSongs() const { return songs; }
};
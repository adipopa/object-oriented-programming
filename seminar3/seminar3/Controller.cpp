#include "Controller.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

void Controller::addSongToRepository(const std::string& artist, const std::string& title, double minutes, double seconds, const std::string& source)
{
	Song s{ artist, title, Duration{minutes, seconds}, source };
	this->repo.addSong(s);
}

void Controller::addSongToPlaylist(const Song& song)
{
	// TODO
}

std::vector<Song> Controller::addAllSongsByArtistToPlaylist(const std::string& artist)
{
	// get all the songs from the repository
	std::vector<Song> songs = this->repo.getSongs();

	// use STL algorithms and lambdas
	std::vector<Song> auxSongs;
	auto it = std::copy_if(songs.begin(), songs.end(), songs.begin(), [artist](Song& song) { return song.getArtist().compare(artist) == 0; });
	auxSongs.resize(std::distance(songs.begin(), it));

	return auxSongs;
}
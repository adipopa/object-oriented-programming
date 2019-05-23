#include "WatchlistRepository.h"

WatchlistRepository::WatchlistRepository() {}

WatchlistRepository::WatchlistRepository(std::vector<Recording> watchlist) : watchlist{ watchlist } {}

void WatchlistRepository::saveToWatchlist(const Recording& recording) {
	this->watchlist.push_back(recording);
}

std::vector<Recording> WatchlistRepository::getWatchlist() {
	return this->watchlist;
}

void WatchlistRepository::setMylistLocation(const std::string& mylistLocation) {}

void WatchlistRepository::openMylist() {}

WatchlistRepository::~WatchlistRepository() {}

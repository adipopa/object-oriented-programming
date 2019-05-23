#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "Recording.h"
#include <vector>

class WatchlistRepository {

protected:
	std::vector<Recording> watchlist;

	std::string mylistLocation;

public:
	WatchlistRepository();

	WatchlistRepository(std::vector<Recording> watchlist);

	virtual void saveToWatchlist(const Recording& recording);

	std::vector<Recording> getWatchlist();

	virtual void setMylistLocation(const std::string& mylistLocation);

	virtual void openMylist();

	~WatchlistRepository();
};


#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "WatchlistRepository.h"
#include <Windows.h>
#include <fstream>

class WatchlistHTMLRepository : public WatchlistRepository {

public:
	WatchlistHTMLRepository(std::vector<Recording> watchlist);

	void saveToWatchlist(const Recording& recording) override;

	void setMylistLocation(const std::string& mylistLocation) override;

	void exportToHTML();

	void openMylist() override;

	~WatchlistHTMLRepository();
};


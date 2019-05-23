#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "WatchlistRepository.h"
#include <Windows.h>
#include <fstream>

class WatchlistCSVRepository : public WatchlistRepository {

public:
	WatchlistCSVRepository(std::vector<Recording> watchlist);

	void saveToWatchlist(const Recording& recording) override;

	void setMylistLocation(const std::string& mylistLocation) override;

	void exportToCSV();

	void openMylist() override;

	~WatchlistCSVRepository();
};


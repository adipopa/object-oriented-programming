#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "WatchlistRepository.h"

class WatchlistFakeRepository : public WatchlistRepository {

public:
	// Default constructor for an WatchlistFakeRepository.
	WatchlistFakeRepository();

	~WatchlistFakeRepository();
};